
int trig = 9;
int echo = 8;
int duration;
float meter;

void setup() 
{
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  pinMode(echo, INPUT);
  delay(6000);
  Serial.println("Distance : ");

}

void loop() 
{
  // 켜고 끄고 해줘야 한다 (초음파 들어옴)
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  // duration = duration / 58;
  Serial.println(duration);
  delay(100);

  if(duration >= 38000){}
}

// I2C 2선식 직렬 통신 그래서 2c다! SCL, SDA 이렇게 해서 선을 줄일 수 있음!
