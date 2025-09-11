#include <Servo.h>

Servo myservo;

const int duration = 150;
unsigned long pre = 0;
unsigned long cur = 0;

int cnt;
int flag = 0;

// 인터럽트 함수
void servoISR()
{
  if(cur - pre >= duration)
  {
    Serial.println(cnt); 
    pre = cur;
    cnt++;
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

  if(flag) // 1번 눌렀을 경우
  {
    myservo.write(90);
    delay(1000);
  }
  else  // 2번 눌렀을 경우
  {
    myservo.write(180);
    delay(1000);
  }  
  
  // delay(1000);
}