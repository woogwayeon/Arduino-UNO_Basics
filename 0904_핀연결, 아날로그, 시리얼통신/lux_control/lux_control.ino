int lux = 0;
int i = 0;
char str[4] = "";

void setup() {
  // put your setup code here, to run once:

  // pinMode(8, OUTPUT); // 처음인자 pin, 입출력
  // gpio는 핀으로 조절
  // gpio 설정(입력(아두이노 외부에서 입력), 출력(아두이노에서 핀으로 전압출력))

  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  // 해당하는 숫자에 맞춰 밝기 조절, analogWrite(핀번호, 값)

  if (Serial.available()) 
  {
    char data = Serial.read();
    Serial.print(data);

    if (data != '\n') 
    {
      str[i++] = data;
      str[i] = '\0';
    }

    if (data == '\n') 
    {
      lux = atoi(str);
      analogWrite(9, lux);

      i = 0;                        
      str[0] = '\0';
    }
  }
}
