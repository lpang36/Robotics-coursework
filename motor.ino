//set motor pin and initial speed
int motorPin = 9;
int motorSpeed;

void setup() {
  //initialize pin and speed
  pinMode(motorPin, OUTPUT);
  motorSpeed = 0;
}

void loop() {
  //run motor at given speed
  analogWrite(motorPin,motorSpeed);
  delay(1000);
  //increase speed
  motorSpeed = motorSpeed+50;
}
