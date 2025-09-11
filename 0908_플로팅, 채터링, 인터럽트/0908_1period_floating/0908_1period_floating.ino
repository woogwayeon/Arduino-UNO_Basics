void setup() {
  // put your setup code here, to run once:

  pinMode(7, INPUT); // 읽어들이는거니 input
  Serial.begin(9600); // 디버깅위해

}

void loop() {
  // put your main code here, to run repeatedly:
  
  int in = digitalRead(7); // 디지털신호 읽어오는거라 디지털 read
  Serial.print(in); // 시리얼모니터에 프린트
  delay(100); // 딜레이를 준다

  if(!digitalRead(7)) 
  {
      
  }


}


/*
# 플로팅 현상 (스위치 연결시 00000000~ 뜨는것)
MCU가 전류 흐르는지 흐르지 않는지 알 수 없다 : 레벨변화를 알수가 없음 
-> 이런 현상을 막기 위해 저항을 달아주면 조절이 가능하다 : 풀업(저항이 위에 있으면 // 대기상태 1), 폴다운(저항이 아래 있으면 GND // 대기상태 0) 저항
회로에 따라서 코드가 달라짐 (당연함 if문 조건이 달라질테니까..)
*/