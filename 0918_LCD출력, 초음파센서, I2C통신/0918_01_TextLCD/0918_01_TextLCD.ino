#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

;void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2); // 16by2라 col 16, row 2
  lcd.print("Hello world"); // 위치지정을 안하고 찍으면 그냥 위에 찍힘
  

}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,1); // 위치 - 2번째줄 처음부터 찍겠다
  lcd.print(millis()/1000);
}
