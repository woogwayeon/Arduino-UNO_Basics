#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); 
// 메시지를 보내는거니까 주소도 검색할수있는데 i2c는 아무튼 마스터, 슬레이브 통신 둘이서 하는거라 슬레이브주소가 0x27이거다

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("hello world");
}

// I2C 2선식 직렬 통신 그래서 2c다! SCL, SDA 이렇게 해서 선을 줄일 수 있음!
