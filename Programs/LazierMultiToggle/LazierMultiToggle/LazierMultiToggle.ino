#include <Servo.h> 

/*
int line1Pin = 0; pin numbers
int line2Pin = 1;
int line3Pin = 2;
*/

boolean on[3];
boolean toggleValue[3];
int countToggle[3] = {0, 0, 0};
int count = 0;
Servo myServo;  
int pos = 0;
int i;


void setup()
{
  Serial.begin(9600);
  myServo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop()
{  
  detect(0);
  detect(1);
  detect(2);
  toggle();
  act();
}

void detect(i) 
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

void toggle(i)
{
    if(on[i] == true && count < 1)
    {
       countToggle[i] += 1; 
       count = 1;
    }
    else if(on[i] == false)
    {
      count = 0;
    }
    if(countToggle[i] == 1)
    {
      toggleValue[i] = true;
    }
    else if(countToggle[i] == 2)
    {
       countToggle[i] = 0;
       toggleValue[i] = false;
    }
}

void act() 
{
  if (toggleValue[1] == true) 
  {
    myServo.write(90);
  } 
  else 
  {
    myServo.write(0);
  }
  if(toggleValue[2] == true)
  {
      
  }
  else
  {
  }
}
