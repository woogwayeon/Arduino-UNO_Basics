#include <Wire.h>

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); 
// 메시지를 보내는거니까 주소도 검색할수있는데 i2c는 아무튼 마스터, 슬레이브 통신 둘이서 하는거라 슬레이브주소가 0x27이거다

void setup() {
  
  Wire.begin();
  Serial.begin(9600);

}

void loop() {
  
  byte error, address;
  int nDevices = 0;
  
  for(address = 1; address < 127; address++)
  {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if(error == 0)
    {
      Serial.print("I2C devicce found at address 0x");
      
      if(address < 16)
      {
        Serial.print("0");
      }
      
      Serial.print(address, BIN);
      Serial.println(" !");

      nDevices++;

    }
    else if(error == 4)
    {
      Serial.print("Unknown error at addreses 0x");
      
      if(address < 16)
      {
        Serial.print("0");
      }
      
      Serial.println(address, HEX);
    }

    if(nDevices == 0)
    {
      Serial.println("No I2C devices found\n");
    }
    else
    {
      Serial.println("down\n");
    }

    delay(5000);

  }

}

// I2C 2선식 직렬 통신 그래서 2c다! SCL, SDA 이렇게 해서 선을 줄일 수 있음!
