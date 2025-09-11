// LED 로 밝을때 26-50
// 평상시 18-25
// 손으로 가렸을때 0-13

void setup() {
  pinMode(A0, INPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int cds = analogRead(A0);
  cds = map(cds, 0, 1023, 0, 255); // 어두우면 값 작아짐
  Serial.println(cds);
  delay(1000);

  if(cds>0 && cds<15)
  {
    analogWrite(10, 255);
  }
  else if(cds>15 && cds<30)
  {
    analogWrite(10, 80);
  }
  else
  {
    analogWrite(10, 0);
  }
  // delay(1000);
}

// AI -> 코드에 대한 최적화 요청, 내가 가진 패턴뿐만 아니라 다른 시각으로 접근 가능

// JSP 쓰자