#include "FastLED.h"
#include "LedControl.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
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
#define UPDATES_PER_SECOND  1


#define OLED_RESET 4

//Adafruit_LEDBackpack matrix = Adafruit_LEDBackpack();
Adafruit_SSD1306 OLEDdisplay(OLED_RESET);

LedControl matrix=LedControl(28, 32, 30, 4);
LedControl seg=LedControl(34, 38, 36, 2);





enum LED_ID
{
ToggleLit_1LED_1 = 14,
ToggleLit_1LED_2 = 15,
ToggleLit_2LED_1 = 13,
ToggleLit_2LED_2 = 16
};



//int Pot_1Pos, Pot_2Pos, Pot_3Pos, Pot_4Pos;
//int Pot_1LastPos, Pot_2LastPos, Pot_3LastPos, Pot_4LastPos;

bool ToggleDuel_1_T;
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

//ResponsiveAnalogRead analog(A14, true);

void setup() {
  delay(3000); // 3 second delay for recovery
  
  // tell FastLED about the LED strip configuration
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  
  // set master brightness control
  FastLED.setBrightness(BRIGHTNESS);

  matrix.shutdown(0, false);
  matrix.shutdown(1, false);
  matrix.shutdown(2, false);
  matrix.shutdown(3, false);
  seg.shutdown(0, false);
  seg.shutdown(1, false);
  
  matrix.setIntensity(0,8);
  matrix.setIntensity(1,8);
  matrix.setIntensity(2,8);
  matrix.setIntensity(3,8);
  
  seg.setIntensity(0,8);
  seg.setIntensity(1,8);

  matrix.clearDisplay(0);
  matrix.clearDisplay(1);
  matrix.clearDisplay(2);
  matrix.clearDisplay(3);

  seg.clearDisplay(0);
  seg.clearDisplay(1);
  

 //BUTTON LED 32, 34, 36

  for ( int id = 3; id <= 68; id++)
  {
    if (id != 5)pinMode(id, INPUT_PULLUP);
  }

  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(35, OUTPUT);
  pinMode(37, OUTPUT);
  pinMode(40, OUTPUT);
  pinMode(43, OUTPUT);
  pinMode(46, OUTPUT);
  pinMode(47, OUTPUT);  
  pinMode(58, OUTPUT);
  pinMode(59, OUTPUT);
  pinMode(60, OUTPUT);
  pinMode(61, OUTPUT);

  digitalWrite(25, HIGH);
  digitalWrite(26, HIGH);
  digitalWrite(35, HIGH);
  digitalWrite(37, HIGH);
  digitalWrite(40, HIGH);
  digitalWrite(43, HIGH);  
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);  
  digitalWrite(58, HIGH);
  digitalWrite(59, HIGH);
  digitalWrite(60, HIGH);
  digitalWrite(61, HIGH);

  
  //pinMode(27, OUTPUT);
  
  //Leds
  //pinMode(24, OUTPUT);
  //pinMode(32, OUTPUT);
  //pinMode(34, OUTPUT);
  //pinMode(36, OUTPUT);

  //pinMode(A4, OUTPUT);
  //digitalWrite(A4, HIGH);
  
  byte SendBuffer[12];
  
  //Serial.begin(115200);
  Serial.begin(115200);
    
  //OLEDdisplay.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  //OLEDdisplay.setFont(&FreeSans9pt7b);  


  
  //attachInterrupt(digitalPinToInterrupt(PinA), isr, LOW);
  //attachInterrupt(digitalPinToInterrupt(PinA), isr, LOW);
  //attachInterrupt(digitalPinToInterrupt(PinA), isr, LOW);
  //attachInterrupt(digitalPinToInterrupt(PinA), isr, LOW);
  
}



void loop()
{ 
///*
  for ( int id = 6; id <= 53; id++)
  {    
    if (digitalRead(id) == LOW)
    {
      Serial.println(id);
      Serial.println("IS ON");       
      delay(500);
    }
  }

  for ( int id = 0; id <= 14; id++)
    {    
      if (digitalRead(id+54) == LOW)
      {
        Serial.println(id+54);
        Serial.println("IS ON");       
        delay(500);
      }
    }
    
/*
    BuildBuffer();
    if (CheckBuffer(TempBB, SendBuffer))
    {
      CopyBuffer(TempBB, SendBuffer);
      SendByteBuffer(TempBB);
    }
*/

  //if (digitalRead(26) == LOW) fill_rainbow( leds, NUM_LEDS, gHue, 7);    
  //if (digitalRead(22) == LOW) fadeToBlackBy( leds, NUM_LEDS, 10);      
  if (millis() > (LastRender + 1000 / FRAMES_PER_SECOND))
  {    
    Render();    
    LastRender = millis();
  }

  
  if (millis() > (LastUpdate + 1000 / UPDATES_PER_SECOND))
  {      
      //SendByteBuffer(TempBB);      
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
  TempBB[0] = 0;
  TempBB[1] = 0;
  TempBB[4] = 0;
  TempBB[5] = 0;
  TempBB[6] = 0;
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

     
/*
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
  //OLEDdisplay.display();
*/
}

