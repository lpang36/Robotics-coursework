//led input pins
const int red = 9;
const int green = 10;
const int blue = 11;
//temperature sensor pin
const int temp = 0;
//intensities of each colour
int ri = 0;
int gi = 0;
int bi = 0;

void setup() {
  //no setup needed
}

//method to get voltage of the sensor pin
float getVoltage(int pin){
 return (analogRead(pin) * .004882814); //converting from a 0 to 1023 digital range
                                        // to 0 to 5 volts (each 1 reading equals ~ 5 millivolts
}

void loop() {
  //convert voltage to temperature
  float t = getVoltage(temp);
  t = (t-0.5)*100;
  //convert temperature to colour
  t = map(t,30,25,0,255);
  t = constrain(t,0,255);
  //send colour to led
  ri = t;
  bi = 255-t;
  analogWrite(red,ri);
  analogWrite(blue,bi);
  delay(10);
}
