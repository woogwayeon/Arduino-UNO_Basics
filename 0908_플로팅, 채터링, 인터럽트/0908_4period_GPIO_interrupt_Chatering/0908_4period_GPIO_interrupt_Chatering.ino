// 250908 4교시 외부인터럽트 interrupt // 인터럽트 (핀 INT) - 얘는 하드웨어 제어

/*
  # 채터링
  이렇게 눌렀다가 해도 켜지고.. 막 두번눌러야하고 그런것(파동 때문임) : 채터링 현상
  // 아까 플로팅은 계속 000000찍히고 그런것, 풀업 풀다운 해서 해결함
*/

// 함수랑 비슷하지만 다르다, 인터럽트 서비스 루틴(ISR) 만들 수 있음
// 인터럽트는 우선순위가 높아서 중간에 오면 무조건 그거먼저 시작해야함

// 내부 인터럽트(소프트웨어 인터럽트) : 타이머 인터럽트, 시간마다 실행할 수있음
// 외부 인터럽트(하드웨어 인터럽트) : GPIO(제너럴 ? input / output, 2번 3번핀이 인터럽트 핀임 여기서는)상태를 모니터링, 하드웨어

// 외부인터럽트 쓰려면 2번 아니면 3번 핀 써야함
// 아두이노 TX : 송신 / RX : 수신 

const int duration = 500;
unsigned long pre_time = 0;
unsigned long cur_time = 0;

void isr()
{
  static boolean led = HIGH;

  // 채터링 현상을 막기 위해 중간에 진동으로 오류생기는? 정도를 지속시간으로 설정해주고
  // 현재 시간에서 이전 시간 빼고 
  if(cur_time - pre_time >= duration)
  {
    // Serial.print("interrupt "); -> 글자 디버깅
    Serial.print(led);         //  -> 1과 0으로 디버깅
    pre_time = cur_time;
    digitalWrite(13, led);
    led = !led;
  }
}

void setup() {
  // attachInterrupt -> 인자 3개
  attachInterrupt(0, isr, FALLING); 
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

// loop문이 없어도 위의 isr이라는 함수가 계속 실행되고 있다
void loop() {
  // 시스템이 부팅되고나서부터 시간을 체크함(millis 단위)
  cur_time = millis();  
}


