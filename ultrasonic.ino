int offset1 = 35; //difference in speed between wheels 
int offset2 = 35; //difference in speed between wheels in a turn
int turntime1 = 900; //time for 90 degree turn
int pos = 90; //initial sensor orientation
bool forward = true; //direction
long event = 0; //last event 

#include <AFMotor.h>
#include <Servo.h>

//initialize wheel servo
Servo myservo;
AF_DCMotor motorR(1); 
AF_DCMotor motorL(2);

//initialize ultrasound sensor and servo
int pin = 9; // connected to the Trig on the module, this serves as both Trigger and Echo
int servoPin = 10;

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
}
void stop()                    //Stop
{
  motorR.run(RELEASE);
  motorL.run(RELEASE);
  delay(1000);
}   
void advance(char a,char b)          //Move forward
{
  motorR.setSpeed(a);
  motorL.setSpeed(b+offset1);
  motorR.run(FORWARD);
  motorL.run(FORWARD);
}  
void back_off (char a,char b)          //Move backward
{
  motorR.setSpeed(a);
  motorL.setSpeed(b+offset1);
  motorR.run(BACKWARD);
  motorL.run(BACKWARD);
}
void turn_L (char a)             //Turn Left
{
  motorL.run(RELEASE);
  motorR.setSpeed(a);  
  motorR.run(FORWARD);
  delay(turntime1);
}
void turn_R (char a)             //Turn Right
{
  motorR.run(RELEASE);
  motorL.setSpeed(a+offset2);
  motorL.run(FORWARD);
  delay(turntime1);
}
//adjust ultrasonic sensor orientation based on direction
void servoTurn () {
  if (pos==0) {
    myservo.write(90);
    pos = 90;
    return;
  }
  else if (pos==90) {
    myservo.write(0);
    pos = 0;
  }
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
void loop()
{
  //move forward
  float range = distance(pin);
  advance(200,200);
  //turn right if object is detected and adjust sensor orientation
  if (forward&&range<10&&millis()-event>1000) {
     stop();
     turn_R (200);
     stop();
     servoTurn();
     forward = false;
     event = millis(); //record last event to eliminate bugs
  }
  //return to moving forward if detected object is no longer present
  else if (!forward&&range>30&&millis()-event>1000) { 
     delay(500);
     stop();
     turn_L (200);
     stop();
     servoTurn();
     forward = true;
     event = millis();
  }
  delay(10);
}
