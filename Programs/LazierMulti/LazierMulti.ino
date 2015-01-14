#include <Servo.h> 
int line1Pin = 0; //analog pin 0
int line2Pin = 1;
int line3Pin = 2;

boolean on[3];
Servo myServo;  
int pos = 0;


void setup()
{
  Serial.begin(9600);
  myServo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop()
{
  detect(0);
  detect(1);
  act();
}

void detect(int i) 
{
    int lightVal = analogRead(i);
    if (lightVal > 300) 
    {
      on[i] = true;
    } 
    else 
    {
      on[i] = false;
    }
}

void act() 
{
  if (on[1] == true) 
  {
    myServo.write(90);
  } 
  else 
  {
    myServo.write(0);
  }
}
