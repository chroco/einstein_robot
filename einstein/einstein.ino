#include <einstein.h>
#include <Servo.h>

Einstein *einstein;

void testHead(Einstein *);
void testEyes(Einstein *);
void testBrows(Einstein *);
void testMouth(Einstein *);
void testArm(Einstein *);

void setup(){
	einstein = new Einstein();
//	delay(3000);
//	testBrows(einstein);
}

void loop(){
//	testHead(einstein);
//	testEyes(einstein);
//	testBrows(einstein);
//	testMouth(einstein);
}

void testHead(Einstein *e){
	delay(2000);
	e->turnHead(45);
	e->tiltHead(45);
	delay(2000);
	e->turnHead(135);
	e->tiltHead(135);
}

void testEyes(Einstein *e){
	e->blink(500);
}

void testBrows(Einstein *e){
	e->raiseBrow();
	delay(2000);
//	e->lowerBrow();
//	delay(2000);
}

void testMouth(Einstein *e){
	e->smile();
	delay(2000);
	e->frown();
	delay(2000);
}

void testArm(Einstein *e){
	
}
