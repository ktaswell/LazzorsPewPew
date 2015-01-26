#include <Servo.h> 
#include <Timer.h>

/*
int line1Pin = 0; pin numbers
int line2Pin = 1;
int line3Pin = 2;
*/

boolean on[3];
boolean toggleValue[3];
int countToggle[3] = {0, 0, 0};
int count = 0;  

Timer t1;
Timer t2;
Servo myServo1;
Servo myServo2;
int pos = 0;


void setup()
{
  Serial.begin(9600);
  myServo1.attach(9);  // attaches the servo on pin 9 to the servo object
  myServo2.attach(10);
    
  t.every()  
    
  pinMode(2, OUTPUT);
}

void loop()
{   
  
  detect(0);
  toggle(0);
  act();
      
  detect(1);
  toggle(1);
  act();
    
  detect(2);
  toggle(2);
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

void toggle(int i)
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
  if (toggleValue[0] == true) 
  {
    myServo1.write(90);
  } 
  else 
  {
    myServo1.write(0);
  }
  if(toggleValue[1] == true)
  {
     digitalWrite(2, HIGH);
  }
  else
  {
     digitalWrite(2, LOW);
  }
  if(toggleValue[2] == true)
  {
    myServo2.write(90);
  }
  else
  {
    myServo2.write(0);
  }
}
