void setup() {
  // put your setup code here, to run once:

  // pinMode(8, OUTPUT); // 처음인자 pin, 입출력
  // gpio는 핀으로 조절
  // gpio 설정(입력(아두이노 외부에서 입력), 출력(아두이노에서 핀으로 전압출력))

  pinMode(9, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  // digitalWrite(8, HIGH); // 아웃풋이니까 write HIGH / LOW
  // delay(500); // program이 그냥 멈춤 밀리초단위 ms
  // digitalWrite(8, LOW); // 아웃풋이니까 write HIGH / LOW
  // delay(500); // 꺼지는것도 딜레이

  // putty Test
  // Serial.print(10);
  // digitalWrite(8, HIGH);
  // delay(500);
  // digitalWrite(8, LOW);
  // delay(500);

  // 이렇게 하면 버퍼가 계속 비워져서 -1만 계속뜬다 그래서 available() 쓸거임
  // int data = Serial.read(); 
  // Serial.print(data);


  // if(Serial.available())
  // {
  //   char data = Serial.read(); 
  //   Serial.print(data);
  // }

  // 1을 보내면 led 켜고 다른거 보내면 끄기 (= 통신은 1바이트씩 이루어진다)
  // if(Serial.available())
  // {
  //  char data = Serial.read();
    
  //   if(data == '1')
  //   {
  //     digitalWrite(8, HIGH);
  //     Serial.print(data);
  //   }
  //   else
  //   {
  //     digitalWrite(8, LOW);
  //     Serial.print(data);
  //   }
  //  }

    // String inCome;
    
    // if(Serial.available())
    // {
    //   char data = Serial.read();
      
    //   if(data == '\n')
    //   {
    //     Serial.print(inCome);
    //     int lumin = inCome.toInt();
    //     analogWrite(9, lumin);
    //     inCome = "";
    //   }
    //   else
    //   {
    //     inCome += data;
    //   }

    // }

    char temp[4];
    int lux;
    int i = 0;

    if(Serial.available())
    {
      char data;

      // while(data != '\n')
      // {
      //   data = Serial.read();
      //   temp[i++] = data;
      // }
      // temp[i] = '\0';

      if(data == '\n')
      {
        data = Serial.read();
        temp[i] = '\0';
        lux = atoi(temp);
        Serial.print(temp);
        analogWrite(9, lux);
      }
      else
      {
        temp[i++] = data;
      }

    }

}
