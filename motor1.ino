int offset1 = 0; //difference in speed between wheels 
int offset2 = 0; //difference in speed between wheels in a turn
int halfcircletime = 2600; //time taken to traverse half circle
int squaretime = 1000; //time for one square side length
int turntime1 = 575; //time for 90 degree turn
int turntime2 = 2000; //parallel segment in 3 point turn
int turntime3 = 1000; //perpendicular segment in 3 point turn
int stoptime = 500; //stopping time

#include <AFMotor.h>

AF_DCMotor motorR(4); //motor pins
AF_DCMotor motorL(3);
  
void stop(void)                    //Stop
{
  motorR.run(RELEASE);
  motorL.run(RELEASE);
  delay(stoptime);
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
void circle ()
{
	//move wheels with different speed
	advance(150,250);
	delay(2*halfcircletime);
}
void square () 
{
	//move in straight line, then turn, four times
	for (int i = 0; i<4; i++) {
		advance(200,200);
		delay(squaretime);
		turn_L (200);
	}
}
void wave ()
{
	//make half circles, with alternating wheel speeds
	for (int i = 0; i<2; i++) {
		advance(150,250);
		delay(halfcircletime);
		advance(250,150);
		delay(halfcircletime);
	}
}
void turn () 
{
	//forward advance
	advance(200,200);
	delay(turntime2);
	//first left turn
	turn_L (200);
	back_off(200,200);
	delay(turntime3);
	//second left turn
	turn_L (200);
	//head back
	advance(200,200);
	delay(turntime2);
}
void setup(void) //set pins
{ 
  motorR.run(RELEASE);
  motorL.run(RELEASE);
} 
void loop(void) 
{
	//loop through each demonstration
	circle();
	stop();
	square();
	stop();
	wave();
	stop();
	turn();
	stop();
}

