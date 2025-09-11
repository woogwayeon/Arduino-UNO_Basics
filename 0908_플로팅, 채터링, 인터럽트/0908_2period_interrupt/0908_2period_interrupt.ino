// 250908 2교시 interrupt // 인터럽트 (핀 INT)
// 함수랑 비슷하지만 다르다, 인터럽트 서비스 루틴(ISR) 만들 수 있음
// 인터럽트는 우선순위가 높아서 중간에 오면 무조건 그거먼저 시작해야함

// 내부 인터럽트(소프트웨어 인터럽트) : 타이머 인터럽트, 시간마다 실행할 수있음
// 외부 인터럽트(하드웨어 인터럽트) : GPIO(제너럴 ? input / output, 2번 3번핀이 인터럽트 핀임 여기서는)상태를 모니터링, 하드웨어

#include <MsTimer2.h> // 타이머인터럽트(내부, 소프트)
// 루프에 뭐가 있던지 얘는 1초마다 계속 실행된다

void isr()
{
  static boolean state = HIGH;
  static int data = 0;
  digitalWrite(13, state);
  state = !state;

  Serial.print(data); // 시리얼 찍어보기
  data++;
}

void setup() {

  // 1. setup에 설정해줌
  MsTimer2::set(100, isr); // 1초마다 실행

  // 2. 시작
  MsTimer2::start();
  pinMode(13, OUTPUT); // 읽어들이는거니 input
  Serial.begin(9600);
}

// loop문이 없어도 위의 isr이라는 함수가 계속 실행되고 있다
void loop() {
  
}


/*
# 플로팅 현상 (스위치 연결시 00000000~ 뜨는것)
MCU가 전류 흐르는지 흐르지 않는지 알 수 없다 : 레벨변화를 알수가 없음 
-> 이런 현상을 막기 위해 저항을 달아주면 조절이 가능하다 : 풀업(저항이 위에 있으면 // 대기상태 1), 폴다운(저항이 아래 있으면 GND // 대기상태 0) 저항
회로에 따라서 코드가 달라짐 (당연함 if문 조건이 달라질테니까..)
*/