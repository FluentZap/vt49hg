#include "FastLED.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_LEDBackpack.h>
#include <Aurebesh6p.h>
#include <Fonts/FreeSans9pt7b.h>

FASTLED_USING_NAMESPACE

#ifndef _BV
  #define _BV(bit) (1<<(bit))
#endif

//Console


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


int LED_1_Power;
int LED_2_Power;
int LED_3_Power;
int LED_4_Power;



void BuildBuffer();
bool CheckBuffer(byte[12], byte[12]);
void CopyBuffer(byte[12], byte[12]);
void SendByteBuffer(byte[12]);


long LastRender;
long LastUpdate;

byte SendBuffer[12];
byte TempBB[12];
char *buff;


int lastCount = 50;
volatile int virtualPosition = 50;



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
  
  
  byte SendBuffer[12];  

  
  //Serial.begin(115200);
  Serial.begin(115200);
    
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
  


  //if (digitalRead(26) == LOW) fill_rainbow( leds, NUM_LEDS, gHue, 7);
  //if (digitalRead(22) == LOW) fadeToBlackBy( leds, NUM_LEDS, 10);      
  if (millis() > (LastRender + 1000 / FRAMES_PER_SECOND))
  {    
    Render();    
    LastRender = millis();
  }

  
  if (millis() > (LastUpdate + 1000 / UPDATES_PER_SECOND))
  {      
      BuildBuffer();
      CopyBuffer(TempBB, SendBuffer);
      SendByteBuffer(TempBB);
      /*  
      if (CheckBuffer(TempBB, SendBuffer))
      {
        CopyBuffer(TempBB, SendBuffer);
        SendByteBuffer(TempBB);
      }
  */
      LastUpdate = millis();
  }
}


void SendByteBuffer(byte bb[12])
{  
  Serial.print("VT");
  Serial.write(bb, 13);
}


void CopyBuffer(byte bb[12], byte bb2[12])
{
  for (int x = 0; x < 12; x++)
  {
    bb2[x] = bb[x];
  }  
}



bool CheckBuffer(byte bb[12], byte bb2[12])
{
  bool change = false;
  for (int x = 0; x < 12; x++)
  {
    if (!(bb[x] == bb2[x])) change = true;
  }
  return change;
}



void BuildBuffer()
{
  //Toggels [0]
  bitWrite(TempBB[0], 0, (digitalRead(ToggleDuel_1_U) == LOW));
  bitWrite(TempBB[0], 1, (digitalRead(ToggleDuel_1_D) == LOW));
  bitWrite(TempBB[0], 2, (digitalRead(ToggleDuel_2_U) == LOW));
  bitWrite(TempBB[0], 3, (digitalRead(ToggleDuel_2_D) == LOW));  
  bitWrite(TempBB[0], 4, (digitalRead(ToggleDuel_3_U) == LOW));
  bitWrite(TempBB[0], 5, (digitalRead(ToggleDuel_3_D) == LOW));
  bitWrite(TempBB[0], 6, (digitalRead(ToggleDuel_4_U) == LOW));
  bitWrite(TempBB[0], 7, (digitalRead(ToggleDuel_4_D) == LOW));

  //LED Toggels
  bitWrite(TempBB[1], 0, (digitalRead(ToggleLit_1) == LOW));
  bitWrite(TempBB[1], 1, (digitalRead(ToggleLit_2) == LOW));
  bitWrite(TempBB[1], 2, (digitalRead(ToggleLit_3) == LOW));
  bitWrite(TempBB[1], 3, (digitalRead(ToggleLit_4) == LOW));
  bitWrite(TempBB[1], 4, (digitalRead(ToggleLit_5) == LOW));

  //Toggels Top left Top Right
  bitWrite(TempBB[2], 0, (digitalRead(ToggleLitTL_1) == LOW));
  bitWrite(TempBB[2], 1, (digitalRead(ToggleLitTL_2) == LOW));
  bitWrite(TempBB[2], 2, (digitalRead(ToggleLitTR_1) == LOW));
  bitWrite(TempBB[2], 3, (digitalRead(ToggleLitTR_2) == LOW));
  //Rot Buttons
  bitWrite(TempBB[2], 4, (digitalRead(Rot_1SW) == LOW));
  bitWrite(TempBB[2], 5, (digitalRead(Rot_2SW) == LOW));

 

  bitWrite(TempBB[3], 0, (digitalRead(Button_LED1_SW) == LOW));
  bitWrite(TempBB[3], 1, (digitalRead(Button_LED2_SW) == LOW));
  bitWrite(TempBB[3], 2, (digitalRead(Button_LED3_SW) == LOW));
  bitWrite(TempBB[3], 3, (digitalRead(Button_LED4_SW) == LOW));

  
  bitWrite(TempBB[4], 0, (digitalRead(LTogBox1) == LOW));
  bitWrite(TempBB[4], 1, (digitalRead(LTogBox2) == LOW));
  bitWrite(TempBB[4], 2, (digitalRead(LTogBox3) == LOW));
  bitWrite(TempBB[4], 3, (digitalRead(LTogBox4) == LOW));
  bitWrite(TempBB[4], 4, (digitalRead(LTogBox5) == LOW));
  bitWrite(TempBB[4], 5, (digitalRead(LTogBox6) == LOW));
  bitWrite(TempBB[4], 6, (digitalRead(LTogBox7) == LOW));
  bitWrite(TempBB[4], 7, (digitalRead(LTogBox8) == LOW));
  
  bitWrite(TempBB[5], 0, (digitalRead(RTogBox1) == LOW));
  bitWrite(TempBB[5], 1, (digitalRead(RTogBox2) == LOW));
  bitWrite(TempBB[5], 2, (digitalRead(RTogBox3) == LOW));
  bitWrite(TempBB[5], 3, (digitalRead(RTogBox4) == LOW));
  bitWrite(TempBB[5], 4, (digitalRead(RTogBox5) == LOW));
  bitWrite(TempBB[5], 5, (digitalRead(RTogBox6) == LOW));
  bitWrite(TempBB[5], 6, (digitalRead(RTogBox7) == LOW));
  bitWrite(TempBB[5], 7, (digitalRead(RTogBox8) == LOW));  

  bitWrite(TempBB[6], 0, (digitalRead(FightStickUP) == LOW));
  bitWrite(TempBB[6], 1, (digitalRead(FightStickDOWN) == LOW));
  bitWrite(TempBB[6], 2, (digitalRead(FightStickLEFT) == LOW));
  bitWrite(TempBB[6], 3, (digitalRead(FightStickRIGHT) == LOW));
    
  TempBB[7] = 0;
  TempBB[8] = 0;
  TempBB[9] = 0;
  TempBB[10] = 0;
  TempBB[11] = 0;
  TempBB[12] = 0;  
}









void Render ()
{
  fill_rainbow( leds, NUM_LEDS, 12, 7);
  
  FastLED.show();
  matrix.print(1138);
  matrix.writeDisplay();

  //oled
  OLEDdisplay.clearDisplay();
  int x = 20;
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
  
  OLEDdisplay.setCursor(35 ,59);
  
  OLEDdisplay.println("00000");

  OLEDdisplay.display();
}

