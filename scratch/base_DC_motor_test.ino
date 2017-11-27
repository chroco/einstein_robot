//Setup Motor A (front and rear) pins
int enableA = A2;
int pinIn1 = 11;
int pinIn2 = 12;

//Setup Motor B (front and rear) pins
int enableB = A3;
int pinIn3 = 13;
int pinIn4 = A4;

void setup() {
  // put your setup code here, to run once:
  pinMode(enableA, OUTPUT);
  pinMode(pinIn1, OUTPUT);
  pinMode(pinIn2, OUTPUT);
  pinMode(enableB, OUTPUT);
  pinMode(pinIn3, OUTPUT);
  pinMode(pinIn4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Turn on motorA and motorB
  analogWrite(enableA, 200);
  analogWrite(enableB, 200);
  digitalWrite(pinIn1, LOW);
  digitalWrite(pinIn2, HIGH);
  digitalWrite(pinIn3, HIGH);
  digitalWrite(pinIn4, LOW);
  delay(1000);
  digitalWrite(pinIn1, LOW);
  digitalWrite(pinIn2, LOW);
  digitalWrite(pinIn3, LOW);
  digitalWrite(pinIn4, LOW);
  delay(1000);
  digitalWrite(pinIn1, HIGH);
  digitalWrite(pinIn2, LOW);
  digitalWrite(pinIn3, LOW);
  digitalWrite(pinIn4, HIGH);
  delay(1000);
  digitalWrite(pinIn1, LOW);
  digitalWrite(pinIn2, LOW);
  digitalWrite(pinIn3, LOW);
  digitalWrite(pinIn4, LOW);
  delay(1000);
}
