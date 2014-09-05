/* Smart Watch Project
   Thomas Varnish
   
   Christmas Tree
*/

/* Includes */
#include <G4D.h>
#include <SoftwareSerial.h>
#include <Time.h>

#define POWER_PIN   8
#define RESET_PIN   9
#define SOFT_TX     3
#define SOFT_RX     2

SoftwareSerial oledSerial(SOFT_RX, SOFT_TX);
G4D display(POWER_PIN, RESET_PIN, &oledSerial);

/* Variables */


/* Function */
void ColourFizz()
{
  for(int x = 0; x < 2000; x ++)
  {
    int x = random(0, 128);
    int y = random(0, 128);
    int rC = 255;
    int gC = 0;
    int bC = 0;

    display.pixel(x, y, rC, gC, bC);
  }
}

void GetTime()
{
  
}

/* Main Program */
void setup()
{
  Serial.begin(9600);
  delay(100);
  
  oledSerial.begin(57600);
  
  display.powerUp();
  display.clear();
  
  //display.circle(64, 64, 60, 0, 0, 255);
  //display.circle(64, 64, 40, 255, 255, 255);
  //display.circle(64, 64, 20, 255, 0, 0);
  
  //delay(2000);
}

void loop()
{
}

