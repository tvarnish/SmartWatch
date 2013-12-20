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
const int button = 11;

int buttonState = 0;
int i;
int x;

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

/* MAIN PROGRAM */
void setup()
{  
        Serial.begin(9600);
        delay(100);
        
        pinMode(button, INPUT);
        
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
  int x = 64;
  int y = 124;
  while (x != y)
  {
    //DrawHollowCircle(60, 1);
    //DrawClockLines();
    x = x - 1;
    y = y - 1;
    display.line( x, y, 64, 64, 255, 0, 0);
    delay(10);
    display.line( x, y, 64, 64, 0, 0, 0);
  }
}
