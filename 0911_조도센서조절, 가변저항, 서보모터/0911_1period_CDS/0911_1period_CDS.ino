void setup() {
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop() {
  int cds = analogRead(A0);
  cds = map(cds, 0, 1023, 0, 255); // 어두우면 값 작아짐
  Serial.println(cds);
  delay(1000);
}
