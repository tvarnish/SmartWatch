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

int rad;
int hour = 0;
//int minutes = 0;
//int minuteradius = 50;
int hourradius = 58;

/* FUNCTIONS */
void DrawClock()
{
  display.circle(64, 64, 60, 0, 255, 0);
  display.circle(64, 64, 59, 0, 0, 0);
}

void DrawRadar()
{
  int counter = 0;
  int hourCounter = hour;
  for (int i = 5; i < 255; i = i + 10)
  {
    hourCounter ++;
    display.line(64, 64, 64 + hourradius * sin(hourCounter * pi/30.0), 64 - hourradius * cos(hourCounter * pi/30.0), 0, i, 0);
    counter ++;
  }
  //display.line(64, 64, 64 + minuteradius * sin(hour*pi/30.0), 64 - minuteradius * cos(minutes * pi/30.0), 0, 255, 0);
  //delay(100);
  hourCounter = hour;
  for (int i = 0; i < counter; i = i + 1)
  {
    display.line(64, 64, 64 + hourradius * sin(hourCounter * pi/30.0), 64 - hourradius * cos(hourCounter * pi/30.0), 0, 0, 0);
  }
  //display.line(64, 64, 64 + minuteradius * sin(hour*pi/30.0), 64 - minuteradius * cos(minutes * pi/30.0), 0, 0, 0);
}

/* MAIN PROGRAM */
void setup()
{  
        Serial.begin(9600);
        delay(50);
        
  	oledSerial.begin(57600);

	display.powerUp();
        display.clear();
        
        DrawClock();
}

/* LOOP */
void loop()
{
  hour ++;
  //minutes ++;
  DrawRadar();
}
