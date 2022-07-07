/*
        _          _ ______ _____ _____ 
       (_)        | |  ____|  __ \_   _|
  _ __  ___  _____| | |__  | |  | || |  
 | '_ \| \ \/ / _ \ |  __| | |  | || |  
 | |_) | |>  <  __/ | |____| |__| || |_ 
 | .__/|_/_/\_\___|_|______|_____/_____|
 | |                                    
 |_|                                    
                             
www.pixeledi.eu | twitter.com/pixeledi
Happy Birthday ATtiny| V1.0 | 06/2022

*/

// RGB LED version A (common cathode), the long pin must be connected to GND. the outermost foot next to GND is red
// the inner foot next to GND is green, then comes blue

#include <Arduino.h>

const byte LEDblue = 0;   // blau
const byte LEDred = 4;   // rot
const byte LEDgreen = 1; // grün
const byte button = 2;

// Zahlenwert zwischen 0 (LED aus) und 255 – gibt die Leuchtstärke der einzelnen Farbe an

unsigned long lastTimeButtonChange = millis();
unsigned long buttonDelay = 50; // 30 - 50 funzt gut
byte buttonState = LOW;
byte cnt = 0;

void colourToLed(byte red, byte green, byte blue)
{
  analogWrite(LEDred, red);
  analogWrite(LEDgreen, green);
  analogWrite(LEDblue, blue);
}

void setup()
{
  pinMode(LEDblue, OUTPUT);
  pinMode(LEDred, OUTPUT);
  pinMode(LEDgreen, OUTPUT);
  pinMode(button, INPUT);

  colourToLed(0, 150, 150);
}

void loop()
{
  unsigned long TimeNow = millis();
  if (TimeNow - lastTimeButtonChange > buttonDelay)
  {
    byte newButtonState = digitalRead(button);
    if (newButtonState != buttonState)
    {
      lastTimeButtonChange = TimeNow;
      buttonState = newButtonState;
      cnt++;
    }
  }

  if (digitalRead(button) == HIGH && cnt == 1)
  {
    colourToLed(150, 150, 0);
  }

  else if (digitalRead(button) == HIGH && cnt == 3) // he counts plus 1 for high, another for low, and another for high again.
  {
    colourToLed(255, 102, 0);
  }

  else if (digitalRead(button) == HIGH && cnt >= 5 && cnt != 13)
  {
    colourToLed(255, 255, 0);
    delay(50);
    colourToLed(255, 153, 0);
    delay(50);
    colourToLed(150, 0, 0);
    delay(50);
    colourToLed(128, 0, 0);
    delay(50);
    colourToLed(150, 0, 0);
  }

  else if (digitalRead(button) == HIGH && cnt == 13)
  {
    colourToLed(255, 153, 204);
    delay(80);
    colourToLed(150, 150, 0);
    delay(80);
    colourToLed(0, 255, 0);
    delay(80);
    colourToLed(0, 128, 0);
    delay(80);
    colourToLed(0, 128, 0);
    delay(80);
    colourToLed(0, 255, 255);
    delay(80);
    colourToLed(255, 0, 255);
    delay(80);
    colourToLed(128, 0, 128);
    delay(80);
  }

  else
  {
    colourToLed(0, 150, 150);
  }
}
