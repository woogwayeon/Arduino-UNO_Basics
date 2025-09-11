#include <Servo.h>

Servo myservo;

void setup() 
{
  pinMode(A0, INPUT);
  myservo.attach(3);
}

void loop() 
{ 
  int res = analogRead(A0);
  
  for(int i=0; i<180; i++)
  {
    myservo.write(i);
    delay(20);
  }
}
