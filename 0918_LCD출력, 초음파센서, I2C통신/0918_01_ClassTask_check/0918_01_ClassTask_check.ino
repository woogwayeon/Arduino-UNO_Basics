#include <Servo.h>

Servo myservo;

const int duration = 150;  // 튕김 방지용
unsigned long pre = 0;     // 이전
unsigned long cur = 0;     // 지금
unsigned long last = 0;    // 마지막 클릭


int cnt = 0;
int flag = 1;

const int checkTime = 500; // 클릭판정 대기타임

void servoISR()
{
  unsigned long now = millis();
  if (now - pre >= duration)
  {
    cnt++;
    pre = now;
  }
  if(cnt % 2 == 1)
  {
    flag = 0;
  }
  else
  {
    flag = 1;
  }
}

void setup()
{
  attachInterrupt(0, servoISR, FALLING); // 2번핀 : 인터럽트 0번
  myservo.attach(13);
  myservo.write(0);
  Serial.begin(9600);
}

void loop()
{
  cur = millis();

  if(flag)
  {
    cnt++;
    myservo.write(90);
    Serial.println("90도");
    if(cnt == 1) cnt = 0;
  }
  else
  {
    cnt++;
    myservo.write(180);
    Serial.println("180도");
    if(cnt <= 2) cnt = 0;
  }
}
