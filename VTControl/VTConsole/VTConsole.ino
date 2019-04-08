#include "FastLED.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_LEDBackpack.h>
#include <Aurebesh6p.h>
#include <Fonts/FreeSans9pt7b.h>
#include <PacketSerial.h>
#include <extEEPROM.h>


FASTLED_USING_NAMESPACE

#ifndef _BV
  #define _BV(bit) (1<<(bit))
#endif

extEEPROM codeEep(kbits_2, 1, 8);         //device size, number of devices, page size

//Console
PacketSerial myPacketSerial;

#define DATA_PIN    5
#define LED_TYPE    WS2811
#define COLOR_ORDER RGB
#define NUM_LEDS    50
CRGB leds[NUM_LEDS];

#define BRIGHTNESS        64
#define FRAMES_PER_SECOND  60
#define UPDATES_PER_SECOND  60


#define OLED_RESET 2

//Adafruit_LEDBackpack matrix = Adafruit_LEDBackpack();
Adafruit_7segment matrix = Adafruit_7segment();
Adafruit_SSD1306 OLEDdisplay(OLED_RESET);

#define ToggleDuel_1_U    41
#define ToggleDuel_1_D    43
#define ToggleDuel_2_U    37
#define ToggleDuel_2_D    39

#define ToggleDuel_3_U    48
#define ToggleDuel_3_D    46
#define ToggleDuel_4_U    45
#define ToggleDuel_4_D    47

#define ToggleLit_1    49
#define ToggleLit_2    51
#define ToggleLit_3    53
#define ToggleLit_4    50
#define ToggleLit_5    52


#define ToggleLitTL_1    57
#define ToggleLitTL_2    56
#define ToggleLitTR_1    54
#define ToggleLitTR_2    55

#define Rot_1SW   15
#define Rot_1DT   14
#define Rot_1CLK   3


#define Rot_2SW   25
#define Rot_2DT   27
#define Rot_2CLK   4

#define Button_LED1_SW    26
#define Button_LED2_SW    22
#define Button_LED3_SW    28
#define Button_LED4_SW    30


int Rot_1State;
int Rot_1LastState;

//LEDS
#define Button_LED1       34
#define Button_LED2       24
#define Button_LED3       32
#define Button_LED4       36


#define FightStick_LED    58



#define LTogBox1    19
#define LTogBox2    18
#define LTogBox3    17
#define LTogBox4    16
#define LTogBox5    35
#define LTogBox6    33
#define LTogBox7    31
#define LTogBox8    29

#define RTogBox1    10
#define RTogBox2    11
#define RTogBox3    12
#define RTogBox4    13
#define RTogBox5    6
#define RTogBox6    7
#define RTogBox7    8
#define RTogBox8    9


#define FightStickUP    42
#define FightStickDOWN  44
#define FightStickLEFT  40
#define FightStickRIGHT 38

#define SendBufferSize 16
#define ReceiveBufferSize 16


void BuildBuffer();
void ProcessBuffer(char* B);
bool CheckBuffer(byte[SendBufferSize], byte[SendBufferSize]);
void CopyBuffer(byte[SendBufferSize], byte[SendBufferSize]);

long LastRender = 0;
long LastUpdate = 0;

byte SendBuffer[SendBufferSize] = {};
byte LastSendBuffer[SendBufferSize] = {};
char *buff;

int Target = 0;

int lastCount = 50;
volatile int virtualPosition = 50;

uint8_t CylinderCode[15]= {};
bool CheckCode;

void setup() {
  
  
  delay(3000); // 3 second delay for recovery
  
  // tell FastLED about the LED strip configuration
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  
  // set master brightness control
  FastLED.setBrightness(BRIGHTNESS);

  for ( int id = 3; id <= 68; id++)
  {
    if (id != 5 && id != 20 && id != 21)pinMode(id, INPUT_PULLUP);
  }

  //Leds  
  //pinMode(27, OUTPUT);
  //pinMode(24, OUTPUT);
  //pinMode(32, OUTPUT);
  //pinMode(34, OUTPUT);
  //pinMode(36, OUTPUT);
  pinMode(Button_LED1, OUTPUT);
  pinMode(Button_LED2, OUTPUT);
  pinMode(Button_LED3, OUTPUT);
  pinMode(Button_LED4, OUTPUT);
  
  pinMode(FightStick_LED, OUTPUT);
  digitalWrite(FightStick_LED, HIGH);

  uint8_t myEEPROM = codeEep.begin(extEEPROM::twiClock100kHz);
  
  //Serial.begin(115200);
  myPacketSerial.begin(28800);
  myPacketSerial.setPacketHandler(&onPacketReceived);

  OLEDdisplay.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  OLEDdisplay.setFont(&FreeSans9pt7b);
  matrix.begin(0x70);  // pass in the address

  //attachInterrupt(digitalPinToInterrupt(PinA), isr, LOW);
  //attachInterrupt(digitalPinToInterrupt(PinA), isr, LOW);
  //attachInterrupt(digitalPinToInterrupt(PinA), isr, LOW);
  //attachInterrupt(digitalPinToInterrupt(PinA), isr, LOW);
  
  
}



void loop()
{
    
  myPacketSerial.update();
  
  if (millis() > (LastRender + 1000 / FRAMES_PER_SECOND))
  {
    Render();
    LastRender = millis();
  }

  
  if (millis() > (LastUpdate + 1000 / UPDATES_PER_SECOND))
  {
      if(CheckCode) {
        codeEep.read(0, CylinderCode, 15);
        BuildBuffer(2);
        CheckCode = false;
        for (int x = 0; x < 15; x++)
        {
          CylinderCode[x] = 0;
        }
      } else {
        BuildBuffer(1);
      }
      
      myPacketSerial.send(SendBuffer, SendBufferSize);
      
//      if (CheckBuffer(SendBuffer, LastSendBuffer))
//      {
//        CopyBuffer(SendBuffer, LastSendBuffer);
//        myPacketSerial.send(SendBuffer, SendBufferSize);
//      }

      LastUpdate = millis();
  }   
}


void onPacketReceived(const uint8_t* buffer, size_t size)
{

  // Make a temporary buffer.
  if(size == 16)
  {
    //uint8_t tempBuffer[size];
    // Copy the packet into our temporary buffer.
    //memcpy(tempBuffer, buffer, size);
    ProcessBuffer(buffer);
  }
}

bool CheckBuffer(byte bb[16], byte bb2[16])
{
  bool change = false;
  for (int x = 0; x < 16; x++)
  {
    if (!(bb[x] == bb2[x])) change = true;
  }
  return change;
}


void CopyBuffer(byte BufferSource[SendBufferSize], byte BufferDest[SendBufferSize])
{ 
  memcpy(BufferDest, BufferSource, SendBufferSize);  
}


void BuildBuffer(byte packet)
{
  byte i = 1;
  SendBuffer[0] = packet;
  
  if (packet == 1) {    
    //Toggels [0]  
    bitWrite(SendBuffer[i], 0, (digitalRead(ToggleDuel_1_U) == LOW));
    bitWrite(SendBuffer[i], 1, (digitalRead(ToggleDuel_1_D) == LOW));
    bitWrite(SendBuffer[i], 2, (digitalRead(ToggleDuel_2_U) == LOW));
    bitWrite(SendBuffer[i], 3, (digitalRead(ToggleDuel_2_D) == LOW));  
    bitWrite(SendBuffer[i], 4, (digitalRead(ToggleDuel_3_U) == LOW));
    bitWrite(SendBuffer[i], 5, (digitalRead(ToggleDuel_3_D) == LOW));
    bitWrite(SendBuffer[i], 6, (digitalRead(ToggleDuel_4_U) == LOW));
    bitWrite(SendBuffer[i], 7, (digitalRead(ToggleDuel_4_D) == LOW));

    i++;
    //LED Toggels
    bitWrite(SendBuffer[i], 0, (digitalRead(ToggleLit_1) == LOW));
    bitWrite(SendBuffer[i], 1, (digitalRead(ToggleLit_2) == LOW));
    bitWrite(SendBuffer[i], 2, (digitalRead(ToggleLit_3) == LOW));
    bitWrite(SendBuffer[i], 3, (digitalRead(ToggleLit_4) == LOW));
    bitWrite(SendBuffer[i], 4, (digitalRead(ToggleLit_5) == LOW));

    i++;
    //Toggels Top left Top Right
    bitWrite(SendBuffer[i], 0, (digitalRead(ToggleLitTL_1) == LOW));
    bitWrite(SendBuffer[i], 1, (digitalRead(ToggleLitTL_2) == LOW));
    bitWrite(SendBuffer[i], 2, (digitalRead(ToggleLitTR_1) == LOW));
    bitWrite(SendBuffer[i], 3, (digitalRead(ToggleLitTR_2) == LOW));
    
    //Rot Buttons
    bitWrite(SendBuffer[i], 4, (digitalRead(Rot_1SW) == LOW));
    bitWrite(SendBuffer[i], 5, (digitalRead(Rot_2SW) == LOW));
  
   
    i++;
    bitWrite(SendBuffer[i], 0, (digitalRead(Button_LED1_SW) == LOW));
    bitWrite(SendBuffer[i], 1, (digitalRead(Button_LED2_SW) == LOW));
    bitWrite(SendBuffer[i], 2, (digitalRead(Button_LED3_SW) == LOW));
    bitWrite(SendBuffer[i], 3, (digitalRead(Button_LED4_SW) == LOW));
  
    i++;
    bitWrite(SendBuffer[i], 0, (digitalRead(LTogBox1) == LOW));
    bitWrite(SendBuffer[i], 1, (digitalRead(LTogBox2) == LOW));
    bitWrite(SendBuffer[i], 2, (digitalRead(LTogBox3) == LOW));
    bitWrite(SendBuffer[i], 3, (digitalRead(LTogBox4) == LOW));
    bitWrite(SendBuffer[i], 4, (digitalRead(LTogBox5) == LOW));
    bitWrite(SendBuffer[i], 5, (digitalRead(LTogBox6) == LOW));
    bitWrite(SendBuffer[i], 6, (digitalRead(LTogBox7) == LOW));
    bitWrite(SendBuffer[i], 7, (digitalRead(LTogBox8) == LOW));
    
    i++;
    bitWrite(SendBuffer[i], 0, (digitalRead(RTogBox1) == LOW));
    bitWrite(SendBuffer[i], 1, (digitalRead(RTogBox2) == LOW));
    bitWrite(SendBuffer[i], 2, (digitalRead(RTogBox3) == LOW));
    bitWrite(SendBuffer[i], 3, (digitalRead(RTogBox4) == LOW));
    bitWrite(SendBuffer[i], 4, (digitalRead(RTogBox5) == LOW));
    bitWrite(SendBuffer[i], 5, (digitalRead(RTogBox6) == LOW));
    bitWrite(SendBuffer[i], 6, (digitalRead(RTogBox7) == LOW));
    bitWrite(SendBuffer[i], 7, (digitalRead(RTogBox8) == LOW));  

    i++;
    bitWrite(SendBuffer[i], 0, (digitalRead(FightStickUP) == LOW));
    bitWrite(SendBuffer[i], 1, (digitalRead(FightStickDOWN) == LOW));
    bitWrite(SendBuffer[i], 2, (digitalRead(FightStickLEFT) == LOW));
    bitWrite(SendBuffer[i], 3, (digitalRead(FightStickRIGHT) == LOW));
  }  


  if (packet == 2) {
    for (int x = 0; x < 15; x++) {
      SendBuffer[x + 1] = CylinderCode[x];
    }
  }

  
}


void ProcessBuffer(char* B)
{
  byte Header = B[0];    
  if (Header == 1)
  {
    digitalWrite(Button_LED1, bitRead(B[1], 0));
    digitalWrite(Button_LED2, bitRead(B[1], 1));
    digitalWrite(Button_LED3, bitRead(B[1], 2));
    digitalWrite(Button_LED4, bitRead(B[1], 3));
    digitalWrite(FightStick_LED, bitRead(B[1], 4));


    for (int x=0; x < 50; x++)
        {
          leds[x].r = B[12];
          leds[x].g = B[13];
          leds[x].b = B[14];
          
          //If the Light is set to on
          if (bitRead(B[2 + (x / 8)], x % 8))
          {            
            leds[x].r = B[9];
            leds[x].g = B[10];
            leds[x].b = B[11];
          }          
        }

        Target = B[15];
     
  }
  if (Header == 2) {
    CheckCode = true;
  }
  
  
  if (Header > 99)
  {
    int num = (Header - 100) * 5;
    for (int x = 0; x < 5; x++)
    {
      leds[num].r = B[(x*3) + 1];
      leds[num].g = B[(x*3) + 2];
      leds[num].b = B[(x*3) + 3];
      num++;
    }   
  }
  
}






void Render ()
{   
  //fill_rainbow(leds, 50, 0, 32);  
  
  FastLED.show();
  matrix.print(1138);
  matrix.writeDisplay();

  //oled
  OLEDdisplay.clearDisplay();
  int x = Target;
  //moving lines
  OLEDdisplay.drawLine(x, 0, x, 48, WHITE);
  OLEDdisplay.drawLine(126-x, 0, 126-x, 48, WHITE);  

  //x,y,hight,width,roundedness
  OLEDdisplay.drawRoundRect(0, 0, 128, 49, 4, WHITE);
  OLEDdisplay.drawRoundRect(32, 50, 63, 14, 4, WHITE);

      
  //Center circle
  OLEDdisplay.drawCircle(63, 25, x / 3, WHITE);
  //center lines
  OLEDdisplay.drawLine(63, 0, 63, 48, WHITE);
  OLEDdisplay.drawLine(0, 25, 127, 25, WHITE);  
  
  OLEDdisplay.setTextSize(1);
  OLEDdisplay.setTextColor(WHITE);
  //display1.setTextColor(BLACK, WHITE); // 'inverted' text
  
  OLEDdisplay.setCursor(35 ,60);
  
  //OLEDdisplay.println("00000");
  OLEDdisplay.println(String(Target));
  

  OLEDdisplay.display();
}


