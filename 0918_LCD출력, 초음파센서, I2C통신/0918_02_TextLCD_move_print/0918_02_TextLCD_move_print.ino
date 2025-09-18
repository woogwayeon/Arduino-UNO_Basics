#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  Serial.begin(9600);
  lcd.begin(16, 2); // 16by2라 col 16, row 2
  lcd.print("Fighting!"); // 위치지정을 안하고 찍으면 그냥 위에 찍힘
}

void loop() {
  // put your main code here, to run repeatedly:
  int cds = analogRead(A0);
  cds = map(cds, 0, 1023, 0, 255); // 어두우면 값 작아짐
  Serial.println(cds);

  lcd.setCursor(0,0); // 위치 - 2번째줄 처음부터 찍겠다

  // lcd.print(cds);
  
  for(int i=0; i<9; i++)
  {
    lcd.scrollDisplayLeft();
    delay(300);
  }

  for(int i=0; i<31; i++)
  {
    lcd.scrollDisplayRight();
    delay(300);
  }

  for(int i=0; i<22; i++)
  {
    lcd.scrollDisplayLeft();
    delay(300);
  }

  delay(500);
}

// 포텐쇼미터 값? CdS값 두번째 줄에 띄우기