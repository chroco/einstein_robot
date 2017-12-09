#include <einstein.h>
#include <Servo.h>

Einstein *einstein;

void testHead(Einstein *);
void testEyes(Einstein *);
void testBrows(Einstein *);
void testMouth(Einstein *);
void testArm(Einstein *);
void testJoyride(Einstein *);

// behaviors
void noMeansNo(Einstein *);
void defaultHeadPosition(Einstein *);
void iDontKnow(Einstein *);
void talking(Einstein *);
void wackAMole(Einstein *);
void armThing(Einstein *);

void setup(){
	einstein = new Einstein();
}

void loop(){
//	testHead(einstein);
//	defaultHeadPosition(einstein);
//	testEyes(einstein);
//	testBrows(einstein);
//	testMouth(einstein);
	testJoyride(einstein);
//	testArm(einstein);
//	noMeansNo(einstein);
//	iDontKnow(einstein);
	lecturing(einstein);
//	armThing(einstein);

	delay(100);
}

void noMeansNo(Einstein *e){
	int i=0;
	for(;i<6;++i){
		e->turnHead(55);
		delay(100);
		e->turnHead(125);
		delay(100);
	}
}

void defaultHeadPosition(Einstein *e){
	delay(2000);
	e->turnHead(90);
	e->tiltHead(90);
}

void iDontKnow(Einstein *e){
	int i=0;
	for(;i<6;++i){
		e->tiltHead(55);
		delay(100);
		e->tiltHead(125);
		delay(100);
	}
}

void lecturing(Einstein *e){
	e->raiseBrow();
	e->frown();
	e->blink(300);
	e->turnHead(100);
	e->smile();
	e->lowerBrow();	
	e->moveEyes(SERVO_CENTER,EYES_VERTICAL_MIN);
	delay(1000);
	e->frown();
	e->smile();
	e->turnHead(80);
	e->moveEyes(SERVO_CENTER,EYES_VERTICAL_MAX);
	delay(1000);
	e->frown();
	e->lowerBrow();
	e->smile();
	e->moveEyes(SERVO_CENTER,EYES_VERTICAL_MIN);
	delay(1000);
	e->moveEyes(SERVO_CENTER,EYES_VERTICAL_MAX);
	delay(1000);
}

void wackAMole(Einstein *e){
	e->rotateRightArm(180);
	e->pitchRightArm(0);
	delay(100);
	e->pitchRightArm(180);
	delay(100);
}

void armThing(Einstein *e){
	e->rotateRightArm(180);
	e->pitchRightArm(0);
	e->bendRightArm(45);
	e->rotateRightArm(70);
	e->pitchRightArm(180);
	e->bendRightArm(135);
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
	delay(1000);
	e->stop();
	delay(2000);
	e->reverse();
	delay(1000);
	e->stop();
	delay(2000);
}

