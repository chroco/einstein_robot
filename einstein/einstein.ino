#include <einstein.h>
#include <Servo.h>

Einstein *einstein;

void testHead(Einstein *);
void defaultHeadPosition(Einstein *);
void testEyes(Einstein *);
void testBrows(Einstein *);
void testMouth(Einstein *);
void testArm(Einstein *);
void testJoyride(Einstein *);

void setup(){
	einstein = new Einstein();
//	einstein->rotateRightArm(135);
//	delay(3000);
//	testBrows(einstein);
}

void loop(){
//	testHead(einstein);
	defaultHeadPosition(einstein);
	testEyes(einstein);
	testBrows(einstein);
	testMouth(einstein);
//	testJoyride(einstein);
//	testArm(einstein);
	delay(500);
}

void defaultHeadPosition(Einstein *e){
	delay(2000);
	e->turnHead(90);
	e->tiltHead(90);
}

void testHead(Einstein *e){
	delay(2000);
	e->turnHead(55);
	e->tiltHead(55);
//	e->turnHead(90);
//	e->tiltHead(90);
	delay(2000);
	e->turnHead(125);
	e->tiltHead(125);
}

void testEyes(Einstein *e){
	e->blink(500);
//*	
//	e->moveEyes(EYES_HORIZONTAL_MIN,SERVO_CENTER);
	delay(1000);
	e->moveEyes(EYES_HORIZONTAL_MAX,SERVO_CENTER);
	delay(1000);
	e->moveEyes(SERVO_CENTER,EYES_VERTICAL_MIN);
	delay(1000);
	e->moveEyes(SERVO_CENTER,EYES_VERTICAL_MAX);
	delay(1000);
//*/
//	e->moveEyes(SERVO_CENTER,125);
//	delay(1000);
}

void testBrows(Einstein *e){
	e->raiseBrow();
	delay(2000);
	e->lowerBrow();
	delay(2000);
}

void testMouth(Einstein *e){
	e->smile();
	delay(2000);
	e->frown();
	delay(2000);
}

void testArm(Einstein *e){
//	e->bendArm(135);
//	e->rotateArm(135);
//	e->pitchRightArm(0);
//	delay(2000);
//	e->bendArm(45);
	e->rotateRightArm(125);
	e->pitchRightArm(0);
	delay(2000);
//	e->rotateRightArm(0);
//	e->pitchRightArm(180);
	delay(2000);
}

void testJoyride(Einstein *e){
	e->forward();
	delay(2000);
	e->stop();
	delay(2000);
	e->reverse();
	delay(2000);
	e->stop();
}

