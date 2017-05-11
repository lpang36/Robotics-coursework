#include <Servo.h>
//servo object
Servo myservo;
int pos = 0;

void setup() {
  //initialize servo pin
  myservo.attach(9);
}

void loop() {
  //go forward
  for (pos=0;pos<180;pos++) {
    //send input to servo
    myservo.write(pos);
    delay(15);
  }
  //go backward
  for (pos=180;pos>=1;pos--) {
    //send input to servo
    myservo.write(pos);
    delay(15);
  }
}
