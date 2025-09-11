// 250908 5교시 [과제]하드웨어인터럽트 - GPIO 인터럽트

// 내부 인터럽트(소프트웨어 인터럽트) : 타이머 인터럽트, 시간마다 실행할 수있음
// 외부 인터럽트(하드웨어 인터럽트) : GPIO(제너럴 ? input / output, 2번 3번핀이 인터럽트 핀임 여기서는)상태를 모니터링, 하드웨어

const int duration = 100;

unsigned long pre_time = 0;
unsigned long cur_time = 0;

int cnt = 0;
int in;

static boolean on = 1;
static boolean off = 0;

void myISR()
{  
  if(in) 
  {
    if(cur_time - pre_time >= duration)
    {
      if(cnt == 0) 
      {
        digitalWrite(9, on);
        digitalWrite(10, off);
        digitalWrite(11, off);

        Serial.print("RED ");
        Serial.print("+ ");
        Serial.println(cnt);
      }
      if(cnt == 1) 
      {
        digitalWrite(9, off);
        digitalWrite(10, on);
        digitalWrite(11, off);

        Serial.print("GREEN ");
        Serial.print("+ ");
        Serial.println(cnt);
      }
      if(cnt == 2) 
      {
        digitalWrite(9, off);
        digitalWrite(10, off);
        digitalWrite(11, on);

        Serial.print("BLUE ");
        Serial.print("+ ");
        Serial.println(cnt);
      }
      if(cnt == 3)
      {
        digitalWrite(9, on);
        digitalWrite(10, on);
        digitalWrite(11, on);

        Serial.print("WHITE ");
        Serial.print("+ ");
        Serial.println(cnt);
      } 

      // Serial.print(cnt);
      cnt++;
      pre_time = cur_time;
      if(cnt == 4) cnt = 0;
    }
  }
}

void setup() {

  attachInterrupt(0, myISR, FALLING); // 스위치 2번핀 연

  pinMode(9, OUTPUT); // RED
  pinMode(10, OUTPUT); // GREEN
  pinMode(11, OUTPUT); // BLUE
  
  Serial.begin(9600);
}

// loop문이 없어도 위의 isr이라는 함수가 계속 실행되고 있다
void loop() {
  cur_time = millis();  
  in = digitalRead(3);
}



