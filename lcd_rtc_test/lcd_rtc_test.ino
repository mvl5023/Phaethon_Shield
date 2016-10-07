// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
#include <Wire.h>
#include "RTClib.h"
#include <Adafruit_RGBLCDShield.h>
#include <utility/Adafruit_MCP23017.h>

Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

// These #defines make it easy to set the backlight color
#define RED 0x1
#define YELLOW 0x3
#define GREEN 0x2
#define TEAL 0x6
#define BLUE 0x4
#define VIOLET 0x5
#define WHITE 0x7

RTC_DS1307 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void setup () 
{
  while (!Serial); // for Leonardo/Micro/Zero

  Serial.begin(57600);
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
  lcd.begin(16, 2);
  lcd.setBacklight(VIOLET);
}

uint8_t i=0;
void loop () 
{
  DateTime now = rtc.now();
    
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(" (");
  Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
  Serial.print(") ");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();
    
  Serial.print(" since midnight 1/1/1970 = ");
  Serial.print(now.unixtime());
  Serial.print("s = ");
  Serial.print(now.unixtime() / 86400L);
  Serial.println("d");
    
  // calculate a date which is 7 days and 30 seconds into the future
  DateTime future (now + TimeSpan(7,12,30,6));
    
  Serial.print(" now + 7d + 30s: ");
  Serial.print(future.year(), DEC);
  Serial.print('/');
  Serial.print(future.month(), DEC);
  Serial.print('/');
  Serial.print(future.day(), DEC);
  Serial.print(' ');
  Serial.print(future.hour(), DEC);
  Serial.print(':');
  Serial.print(future.minute(), DEC);
  Serial.print(':');
  Serial.print(future.second(), DEC);
  Serial.println();
    
  Serial.println();

  lcd.clear();
  lcd.setCursor(1,0);  
  lcd.print(now.month());
  lcd.print('/');
  lcd.print(now.day());
  lcd.print('/');
  lcd.print(now.year());
  lcd.setCursor(1,1);
  lcd.print(now.hour());
  lcd.print(':');
  lcd.print(now.minute());
  lcd.print(':');
  lcd.print(now.second());
  

  uint8_t buttons = lcd.readButtons();

  if (buttons)
  {    
    if (buttons & BUTTON_UP) 
    {      
      lcd.setBacklight(RED);
    }
    if (buttons & BUTTON_DOWN) 
    {      
      lcd.setBacklight(YELLOW);
    }
    if (buttons & BUTTON_LEFT) 
    {      
      lcd.setBacklight(GREEN);
    }
    if (buttons & BUTTON_RIGHT) 
    {      
      lcd.setBacklight(TEAL);
    }
    if (buttons & BUTTON_SELECT) 
    {      
      lcd.setBacklight(VIOLET);
    }
  }
    
  delay(3000);
}
