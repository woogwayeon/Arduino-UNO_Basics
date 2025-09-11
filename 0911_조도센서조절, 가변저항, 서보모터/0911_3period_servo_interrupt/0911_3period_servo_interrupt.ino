#include <Servo.h>

Servo myservo;

const int duration = 150;
unsigned long pre = 0;
unsigned long cur = 0;

int cnt;

// 인터럽트 함수
void servoISR()
{
  if(cur - pre >= duration)
  {
    Serial.println(cnt); 
    pre = cur;
  }
  cnt++;
}

void setup() 
{
  attachInterrupt(0, servoISR, FALLING);
  Serial.begin(9600);
  myservo.attach(3);
}


void loop() 
{ 
  cur = millis();
  myservo.write(res);
  // delay(1000);
}