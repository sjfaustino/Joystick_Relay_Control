/*
  Remote control Emitter for Construal 3M
  Uses State machine to only allow moving in one direction at a time
*/

#include <SoftwareSerial.h>
#define RX 10
#define TX 11
SoftwareSerial mySerial(RX, TX);

int Xin = A0; // X Input Pin
int Yin = A1; // Y Input Pin

void setup ()
{
  Serial.begin (9600);
  mySerial.begin(9600);

}
void loop ()
{
  int xVal, yVal, buttonVal;

  xVal = round(analogRead (Xin) * 3 / 1024);
  yVal = round(analogRead (Yin) * 3 / 1024);

  //  Serial.print("X = ");
  //  Serial.println (xVal);

  //  Serial.print ("Y = ");
  //  Serial.println (yVal);

  if (xVal == 1 && yVal == 1) {
    Serial.println("centered");
    mySerial.print("0");
  }
  else if (xVal == 1 && yVal == 0) {
    Serial.println("forward");
    mySerial.print("4");
  }
  else if (xVal == 1 && yVal == 2) {
    Serial.println("back");
        mySerial.print("5");
  }
  else if (xVal == 0 && yVal == 1) {
    Serial.println("right");
    mySerial.print("6");
  }
  else if (xVal == 2 && yVal == 1) {
    Serial.println("left");
    mySerial.print("7");
  } // Ignore all other position combinations

  delay (500);
}
