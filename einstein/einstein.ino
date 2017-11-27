#include <einstein.h>
#include <Servo.h>

Einstein *einstein;

void testHead(Einstein *);
void testEyes(Einstein *);
void testEyesbrows(Einstein *);
void testMouth(Einstein *);

void setup(){
	einstein = new Einstein();
}

void loop(){
	testHead(einstein);
	testEyes(einstein);
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

void testEyesbrows(Einstein *e){

}

void testMouth(Einstein *e){

}

