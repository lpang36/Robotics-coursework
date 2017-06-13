int offset1 = 35; //difference in speed between wheels 
int offset2 = 35; //difference in speed between wheels in a turn
int turntime1 = 900; //time for 90 degree turn
int pos = 90; //initial sensor orientation
int pos2 = 90;
int speed = 100;

#include <AFMotor.h>
#include <Servo.h>

//initialize wheel servo
Servo myservo;
Servo attack;
AF_DCMotor motorR(1); 
AF_DCMotor motorL(2);

//initialize ultrasound sensor and servo
int pin = 9; // connected to the Trig on the module, this serves as both Trigger and Echo
int servoPin = 10;
int attackPin = 11;

void setup()
{
  //initialize all pins
  Serial.begin(9600);
  pinMode(pin, OUTPUT);
  digitalWrite(pin, HIGH); // Trig pin is normally HIGH
  motorR.run(RELEASE);
  motorL.run(RELEASE);
  myservo.attach(servoPin);
  myservo.write(pos);
  attack.attach(attackPin);
  attack.write(pos2);
}
void stop(char n)                    //Stop
{
  motorR.run(RELEASE);
  motorL.run(RELEASE);
}   
void advance(char a)          //Move forward
{
  motorR.setSpeed(a);
  motorL.setSpeed(a+offset1);
  motorR.run(FORWARD);
  motorL.run(FORWARD);
  speed = a;
}  
void back_off (char a)          //Move backward
{
  motorR.setSpeed(a);
  motorL.setSpeed(a+offset1);
  motorR.run(BACKWARD);
  motorL.run(BACKWARD);
  speed = -a;
}
int turn (char a,char angle)             //Turn Left
{
  if (angle<0) {
  motorL.run(RELEASE);
  motorR.setSpeed(a);  
  motorR.run(FORWARD);
  }
  else {
  motorR.run(RELEASE);
  motorL.setSpeed(a);  
  motorL.run(FORWARD);
  }
  return abs(200.0/a*angle/90.0*turntime1);
}
//distance detected by sensor
float distance(int pin)
{
  unsigned long time;
  unsigned long sizeofpulse;
  float range;

  pinMode(pin, OUTPUT); //return digital pin to OUTPUT mode after reading
  digitalWrite(pin, LOW);
  delayMicroseconds(25);
  digitalWrite(pin, HIGH); //Trig pin pulsed LOW for 25usec
  time = micros(); //record timer
  pinMode(pin, INPUT); //change pin to INPUT to read the echo pulse 
  sizeofpulse = pulseIn(pin, LOW, 18000); //should be approx 150usec, timeout at 18msec
  time = micros() - time - sizeofpulse; // amount of time elapsed since we sent the trigger pulse and detect the echo pulse, then subtract the size of the echo pulse
  range = (time*340.29/2/10000)-3; // convert to distance in centimeters
  return range;
}
void battle() {
  long event = millis();
  advance(300);
  while(millis()-event<500) {
  attack.write(180);
  attack.write(90);
  }
  event = millis();
  back_off(300);
  while(millis()-event<500) {
  attack.write(180);
  attack.write(90);
  }
}
void track() {
  int delay = turn(speed,pos-90);
  delay(delay);
  advance(speed+10,speed+10);
}
void decision(int range) {
  if (range<5) {
    battle();
  }
  else if (range<25) {
    track();
  }
}
void scan() {
  for (pos; pos<181; pos++) {
    myservo.write(pos);
    float range = distance(pin);
    decision(range);
    delay(1);
  }
  for (pos; pos>-1; pos--) {
    myservo.write(pos);
    float range = distance(pin);
    decision(range);
    delay(1);
  }
}
void loop()
{
  //move forward
  advance(speed,speed);
  scan();
  delay(10);
}