#include <Servo.h>;

Servo myServo1;
Servo myServo2;
int pos = 0;
int count[3] = {0, 0, 0};
int iter;
boolean toggleValue[3];

void setup()
{
 Serial.begin(9600);
 myServo1.attach(9);
 myServo2.attach(10); 
 pinMode(2, OUTPUT);
}

void loop()
{
  for(iter = 1; iter <= 3; iter++)
  {
    detect(iter);
    toggle(iter); 
    act(); 
  }  
}

void detect(int i)
{
  int lightVal = analogRead(i);
  if(lightVal < 300)
  {
    count[i]++;
  }
}

void toggle(int i)
{
  if(count[i] == 1)
  {
    toggleValue[i] = true;
  }
  else
  {
    toggleValue[i] = false;
  }  
}

void act()
{
  if(toggleValue[1] == true)
  {
    myServo1.write(90);
  }
  else
  {
    myServo1.write(0);
  }
  
  if(toggleValue[2] == true)
  {
    myServo2.write(90);
  }
  else
  {
    myServo2.write(0);
  }
  
  if(toggleValue[3] == true)
  {
    digitalWrite(2, HIGH);
  }
  else
  {
    digitalWrite(2, LOW);
  }
}
