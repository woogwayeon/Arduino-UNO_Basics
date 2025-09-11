// 250908 4교시 외부인터럽트 interrupt // 인터럽트 (핀 INT) - 얘는 하드웨어 제어

// 함수랑 비슷하지만 다르다, 인터럽트 서비스 루틴(ISR) 만들 수 있음
// 인터럽트는 우선순위가 높아서 중간에 오면 무조건 그거먼저 시작해야함

// 내부 인터럽트(소프트웨어 인터럽트) : 타이머 인터럽트, 시간마다 실행할 수있음
// 외부 인터럽트(하드웨어 인터럽트) : GPIO(제너럴 ? input / output, 2번 3번핀이 인터럽트 핀임 여기서는)상태를 모니터링, 하드웨어

// 외부인터럽트 쓰려면 2번 아니면 3번 핀 써야함
// 아두이노 TX : 송신 / RX : 수신 

int count = 0;

void isr()
{
  static boolean led = HIGH;
  digitalWrite(13, led);
  led = !led;
  count = 0;
}

void setup() {
  // attachInterrupt -> 인자 3개
  //  (interrupt_number : 아두이노 핀번호 2번이면 0, 3번이면 1, -> 아트메가328 기준
  //  function, 
  //  mode : RISING(올라가는 상황 - 폴다운일때 누를때 불이 켜짐), FALLING(내려가는 상황 - 풀다운일때 뗄때 불이 켜짐), CHANGE(변화 발생, 무조건 2번));
  attachInterrupt(0, isr, FALLING); 
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

// loop문이 없어도 위의 isr이라는 함수가 계속 실행되고 있다
void loop() {
  
  // 인터럽트 일어날때마다 리셋되는지(?) 찍어보기
  count++;

  // isr() 함수 안에 count = 0; 을 넣어둬서 isr이 실행될때마다 숫자가 리셋되는거 확인
  Serial.print(count); 
  delay(100);
  
}

/*
  이렇게 눌렀다가 해도 켜지고.. 막 두번눌러야하고 그런것(파동 때문임) : 채터링 현상
  // 아까 플로팅은 계속 000000찍히고 그런것, 풀업 풀다운 해서 해결함
*/
