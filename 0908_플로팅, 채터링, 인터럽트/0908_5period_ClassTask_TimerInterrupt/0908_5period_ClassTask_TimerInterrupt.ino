// 250908 5교시 [과제]타이머인터럽트

// 내부 인터럽트(소프트웨어 인터럽트) : 타이머 인터럽트, 시간마다 실행할 수있음
// 외부 인터럽트(하드웨어 인터럽트) : GPIO(제너럴 ? input / output, 2번 3번핀이 인터럽트 핀임 여기서는)상태를 모니터링, 하드웨어

#include <MsTimer2.h> // 타이머인터럽트(내부, 소프트)

int cnt = 0;

void myISR()
{
  static boolean on = 1;
  static boolean off = 0;
  
  if(cnt == 0) 
  {
    digitalWrite(9, on);
    digitalWrite(10, off);
    digitalWrite(11, off);
  }
  if(cnt == 1) 
  {
    digitalWrite(9, off);
    digitalWrite(10, on);
    digitalWrite(11, off);
  }
  if(cnt == 2) 
  {
    digitalWrite(9, off);
    digitalWrite(10, off);
    digitalWrite(11, on);
  }
  if(cnt == 3)
  {
    digitalWrite(9, on);
    digitalWrite(10, on);
    digitalWrite(11, on);
  } 


  Serial.print(cnt);
  cnt++;
  if(cnt == 4) cnt = 0;

}

void setup() {

  // 1. setup에 설정해줌 : MsTimer2::set(밀리초, 함수) -> 시간마다 실행되는거니까 사실상 스위치 필요없음(?)
  MsTimer2::set(1000, myISR);

  // 2. 시작 MsTimer2::start()
  MsTimer2::start();

  pinMode(9, OUTPUT); // RED
  pinMode(10, OUTPUT); // GREEN
  pinMode(11, OUTPUT); // BLUE
  
  Serial.begin(9600);

}

// loop문이 없어도 위의 isr이라는 함수가 계속 실행되고 있다
void loop() {


  
}



