const int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void digitalfun() {
  for (int x=100; x<=2000; x+=100) {
    digitalWrite(ledPin, HIGH);
    delay(x);
    digitalWrite(ledPin, LOW);
    delay(500);
  }
}

void analogfun() {
  for (int x=0; x<255; x++) {
    analogWrite(ledPin, x);
    delay(200);
  }
}

void loop() {
  digitalfun();
  analogfun();
}
