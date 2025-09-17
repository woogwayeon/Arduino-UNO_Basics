#include <Servo.h>

Servo myservo;

const int duration = 150; 
unsigned long pre = 0;  // 이전
unsigned long cur = 0;  // 지금
unsigned long last = 0;  // 마지막

int cnt = 0;

const int checkTime = 300; 

void servoISR()
{
  if (cur - pre >= duration) 
  {
    pre = cur;
    cnt++;
    last = cur; 
  }
}

void setup() 
{
  attachInterrupt(0, servoISR, FALLING);
  myservo.attach(3);
  Serial.begin(9600);
}

void loop() 
{ 
  cur = millis();

  if (cnt > 0 && (cur - last > checkTime)) 
  {
    if (cnt == 1) 
    { 
      myservo.write(90);
      Serial.println("90도");
    } 
    else if (cnt == 2) 
    {
      myservo.write(180);
      Serial.println("180도");
    }
    cnt = 0;
  }
}