int offset1 = 0; //difference in speed between wheels 
int offset2 = 0; //difference in speed between wheels in a turn
int turntime1 = 900; //time for 90 degree turn
int pos = 90; //initial sensor orientation
int pos2 = 90; //initial attacking arm orientation
int spd = 100; //initial speed

#include <AFMotor.h>
#include <Servo.h>

//initialize wheel and attacking arm servo
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
  spd = a;
}  
void back_off (char a)          //Move backward
{
  motorR.setSpeed(a);
  motorL.setSpeed(a+offset1);
  motorR.run(BACKWARD);
  motorL.run(BACKWARD);
  spd = -a;
}
int turn (char a,char angle)             //Turn given angle
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
  //output required time to make the turn 
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
//engage opponent
void battle() {
  long event = millis();
  //ram opponent at high speed
  advance(300);
  while(millis()-event<500) {
  attack.write(180); //use attacking arm
  attack.write(90);
  }
  event = millis();
  //retreat 
  back_off(300);
  while(millis()-event<500) {
  attack.write(180);
  attack.write(90);
  }
}
//approach opponent at increased speed
void track() {
  int delay1 = turn(spd,pos-90); //move in direction of opponent
  delay(delay1);
  advance(spd+10);
}
//make decision based on distance
void decision(int range) {
  if (range<5) {
    battle();
  }
  else if (range<25) {
    track();
  }
}
//scan for opponent
void scan() {
  //pan ultrasonic sensor
  for (pos; pos<181; pos++) {
    myservo.write(pos);
    float range = distance(pin);
    decision(range); //make decision based on distance
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
  //move forward and scan for opponent
  advance(spd);
  scan();
  delay(10);
}
