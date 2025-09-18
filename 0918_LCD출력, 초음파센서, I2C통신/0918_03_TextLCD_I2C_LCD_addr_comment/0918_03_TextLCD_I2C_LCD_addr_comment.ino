#include <Wire.h>

#include <LiquidCrystal_I2C.h>

// I2C 프로토콜 자체가 8비트(1byte) 단위로 데이터를 전송하기 때문이며, 
// 이 8비트 중 7비트는 슬레이브 장치를 고유하게 식별하는 주소로 사용되고, 
// 나머지 1비트는 데이터 쓰기/읽기 비트 (최상위비트 일해라!)
// 레지스터주소지정으로 주소를 정해주고,

// LiquidCrystal_I2C lcd(0x27, 16, 2); 
// 메시지를 보내는거니까 주소도 검색할수있는데 i2c는 아무튼 마스터, 슬레이브 통신 둘이서 하는거라 슬레이브주소가 0x27이거다
// I2C devicce found at address 0x100111 ! -> 이렇게 출력된다 그래서 2진수 16진수로 바꾸면 0x27

void setup() {
  
  Wire.begin(); // 가져온 라이브러리 (Wire가 I2C를 위해 있는 라이브러리임)
  Serial.begin(9600);

}

void loop() {
  
  byte error, address; // 에러 및 주소 변수
  int nDevices = 0;
  
  for(address = 1; address < 127; address++)
  {
    Wire.beginTransmission(address);    // 특정 주소로 통신 시작
    error = Wire.endTransmission();     // 통신 시도 및 결과 반환

    if(error == 0)       // error 값이 0이면 통신 성공
    {
      Serial.print("I2C devicce found at address 0x");
      
      if(address < 16)   // 16진수로 0-F까지는 앞에 0 붙여서 출력함
      {
        Serial.print("0");
      }
      
      Serial.print(address, BIN); // 주소 2진수로 출력
      // Serial.print(변수, BIN) 형식 10진수를 2진수나 16진수 문자열로 출력, BIN이랑 HEX는 상수
      Serial.println(" !");

      nDevices++;         // 찾은 장치 갯수 증가

    }
    else if(error == 4)   // 에러 코드 4는 주소찾기 실패 의미한다!
    {
      Serial.print("Unknown error at addreses 0x");
      
      if(address < 16)    // 16진수로 0-F 까지 앞에 0을 붙여서 출력함
      {
        Serial.print("0");
      }
      
      Serial.println(address, HEX); // 주소 16진수로
    }

    if(nDevices == 0)     // 장치를 찾지 못했을 때 메시지 출력
    {
      Serial.println("No I2C devices found\n");   
    }
    else
    {
      Serial.println("down\n");
    }

    delay(5000);  // 5초마다 스캔 다시 실행

  }

}

// I2C 2선식 직렬 통신 그래서 2c다! SCL, SDA 이렇게 해서 선을 줄일 수 있음!
