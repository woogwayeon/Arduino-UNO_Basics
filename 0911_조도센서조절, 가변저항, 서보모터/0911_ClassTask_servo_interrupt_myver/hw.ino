#include <Servo.h>

Servo myservo;

const int duration = 150;  // 튕김방지용
unsigned long pre = 0;  // 이전
unsigned long cur = 0;  // 지금
unsigned long last = 0;  // 마지막

int cnt = 0;

const int checkTime = 500; // 클릭판단

void servoISR()
{
  long cur2 = millis();

  if (cur2 - pre >= duration) 
  {
    pre = cur2;
    cnt++;
  }
}

void setup() 
{
  attachInterrupt(0, servoISR, FALLING);
  myservo.attach(13);
  myservo.write(0);
  Serial.begin(9600);
}

void loop() 
{ 
  cur = millis();

  if (cur - last > checkTime) 
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
    last = cur;
  }
}