/* Smart Watch Project
   Thomas Varnish
   
   Christmas Tree
*/

/* Includes */
#include <G4D.h>
#include <SoftwareSerial.h>

#define POWER_PIN   8
#define RESET_PIN   9
#define SOFT_TX     3
#define SOFT_RX     2

SoftwareSerial oledSerial(SOFT_RX, SOFT_TX);
G4D display(POWER_PIN, RESET_PIN, &oledSerial);

/* Variables */


/* Function */


/* Main Program */
void setup()
{
  Serial.begin(9600);
  delay(100);
  
  oledSerial.begin(57600);
  
  display.powerUp();
  display.clear();
}

void loop()
{
}

