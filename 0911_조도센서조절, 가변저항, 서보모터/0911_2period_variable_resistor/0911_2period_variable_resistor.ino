void setup() 
{
  pinMode(A2, INPUT);
  
  pinMode(3, OUTPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{  
  int res = analogRead(A2);
  Serial.println(res);

  res = map(res, 0, 1023, 0, 255);
  analogWrite(10, res);

  delay(100);
}
