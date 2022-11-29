#define pinControle1 26
#define pinControle2 33
#define pinControle3 27
#define pinControle4 25

#define pinLED1 23
#define pinLED2 19
#define pinLED3 18
#define pinLED4 5

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);  // padrao 0x27

bool estadoCanal1;
bool estadoCanal2;
bool estadoCanal3;
bool estadoCanal4;

bool estadoCanal1Ant;
bool estadoCanal2Ant;
bool estadoCanal3Ant;
bool estadoCanal4Ant;

bool canal1;
bool canal2;
bool canal3;
bool canal4;



void setup()
{
  pinMode(pinControle1, INPUT);
  pinMode(pinControle2, INPUT);
  pinMode(pinControle3, INPUT);
  pinMode(pinControle4, INPUT);

  pinMode(pinLED1, OUTPUT);
  pinMode(pinLED2, OUTPUT);
  pinMode(pinLED3, OUTPUT);
  pinMode(pinLED4, OUTPUT);
  
  lcd.init();                      
  lcd.backlight();
  
  lcd.setCursor(0,0);
  lcd.print("[A]:     [B]:");
  lcd.setCursor(0,1);
  lcd.print("[C]:     [D]:");
}


void loop()
{
  estadoCanal1 = digitalRead(pinControle1);
  if (estadoCanal1 && !estadoCanal1Ant) { canal1 = !canal1; }
  estadoCanal1Ant = estadoCanal1;

  estadoCanal2 = digitalRead(pinControle2);
  if (estadoCanal2 && !estadoCanal2Ant) { canal2 = !canal2; }
  estadoCanal2Ant = estadoCanal2;

  estadoCanal3 = digitalRead(pinControle3);
  if (estadoCanal3 && !estadoCanal3Ant) { canal3 = !canal3; }
  estadoCanal3Ant = estadoCanal3;

  estadoCanal4 = digitalRead(pinControle4);
  if (estadoCanal4 && !estadoCanal4Ant) { canal4 = !canal4; }
  estadoCanal4Ant = estadoCanal4;
  
  lcd.setCursor(4,0); 
  if (canal1) { lcd.print("on "); } else { lcd.print("off"); } 

  lcd.setCursor(13,0); 
  if (canal2) { lcd.print("on "); } else { lcd.print("off"); }  

  lcd.setCursor(4,1); 
  if (canal3) { lcd.print("on "); } else { lcd.print("off"); }

  lcd.setCursor(13,1); 
  if (canal4) { lcd.print("on "); } else { lcd.print("off"); }

  digitalWrite(pinLED1, canal1);
  digitalWrite(pinLED2, canal2);
  digitalWrite(pinLED3, canal3);
  digitalWrite(pinLED4, canal4);  
}
