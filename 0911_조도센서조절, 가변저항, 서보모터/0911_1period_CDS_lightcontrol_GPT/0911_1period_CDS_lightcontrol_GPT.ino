/*
  조도센서 : 조도 센서의 아날로그 출력을 ADC가 변환해줌
*/
// LED 로 밝을때 26-50
// 평상시 18-25
// 손으로 가렸을때 0-13

// 상수 선언
const int LED_BRIGHT = 255;
const int LED_DIM = 80;
const int LED_OFF = 0;

const int LED_PIN = 10;
const int SENSOR_PIN = A0;

void setup() 
{
  pinMode(SENSOR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{  
  int cds = analogRead(SENSOR_PIN);
  cds = map(cds, 0, 1023, 0, 255); // 어두우면 값 작아짐
  Serial.println(cds);
  
  int bright;

  if(cds>0 && cds<15) // 손으로 가렸을 때
  {
    bright = LED_BRIGHT;
  }
  else if(cds>15 && cds<30) // 평상시
  {
    bright = LED_DIM;
  }
  else // 밝을 때
  {
    bright = LED_OFF;
  }

  analogWrite(LED_PIN, bright);

  delay(1000);
}

// AI -> 코드에 대한 최적화 요청, 내가 가진 패턴뿐만 아니라 다른 시각으로 접근 가능

// JSP 쓰자