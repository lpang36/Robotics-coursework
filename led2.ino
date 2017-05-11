const int pins[] = {11,10,9,6,5,3}; //array for led pin positions
int x; //delay for digital
int y; //brightness for analog

void setup() {
  //initialize delay and brightness
  x = 1000;
  y = 10;
  //initialize led pins
  for (int i=0; i<6; i++) {
    pinMode(pins[i],OUTPUT);
  }
}

//digital method
void digital(int x) {
  //turn on each led in a row
  for (int i=0; i<6; i++) {
    digitalWrite(pins[i],HIGH);
    //modify delay
    delay(x);
  }
  //turn off all leds
  for (int i=0; i<6; i++) {
    digitalWrite(pins[i],LOW);
  }
}

//analog method
void analog(int y) {
  //turn on each led in a row
  for (int i=0; i<6; i++) {
    //modify brightness
    analogWrite(pins[i],y);
    delay(100);
  }
  //turn off all leds
  for (int i=0; i<6; i++) {
    analogWrite(pins[i],0);
  }
}

void loop() {
  //run digital and analog methods
  digital(x);
  //decrease delay
  x = x-200;
  //reset delay 
  if (x==0) x=1000;
  analog(y);
  //increase brightness
  y = y+40;
  //reset brightness
  if (y>256) y=10;
}
