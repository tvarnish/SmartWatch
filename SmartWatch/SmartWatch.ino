/* Smart Watch Project 
   Thomas Varnish
*/

/* INCLUDES */
#include <G4D.h>
#include <SoftwareSerial.h>

#define POWER_PIN    8
#define RESET_PIN    9
#define SOFT_TX      3
#define SOFT_RX      2

SoftwareSerial oledSerial(SOFT_RX, SOFT_TX);
G4D display(POWER_PIN,RESET_PIN,&oledSerial);

/* VARIABLES */
const float pi = 3.1415;

int buttonState = 0;
int i;
int x;
int hAngle;
int hX;
int hY;
int cX = 64;
int cY = 64;
int hLength = 45;

float h = 0.0;

/* FUNCTIONS */
void ColourBackground()
{
  display.setBackground(50, 50, 88);
}

void DrawHollowCircle(int x, int i)
{
  display.circle(64, 64, x, 255, 255, 255);
  display.circle(64, 64, x - i, 0, 0, 0);
}

void DrawClockLines()
{
  display.line( 64, 124, 64, 114, 255, 255, 255);
  display.line( 64, 4, 64, 14, 255, 255, 255);
  display.line( 124, 64, 114, 64, 255, 255, 255);
  display.line( 4, 64, 14, 64, 255, 255, 255);
}

void DrawHourHand()
{
  h = h + 0.25;
  hAngle = 2.0 * pi * h / 12.0;
  hX = cX + hLength * sin(hAngle);
  hY = cY - hLength * cos(hAngle);
  display.line( cX, cY, hX, hY, 255, 0, 0);
  delay(100);
  display.line( cX, cY, hX, hY, 0, 0, 0);
}

/* MAIN PROGRAM */
void setup()
{  
        Serial.begin(9600);
        delay(100);
        
  	oledSerial.begin(57600);

	display.powerUp();
        display.clear();
        //ColourBackground();
        DrawHollowCircle(60, 1);
        DrawClockLines();
}

/* LOOP */
void loop()
{
  // Needs fixing
  while (true)
  {
    h ++;
    DrawHourHand();
  }
}
