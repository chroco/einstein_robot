#include <einstein.h>
#include <Servo.h>

Einstein *einstein;

void setup(){
	einstein = new Einstein();
}


void loop(){
	delay(2000);
	einstein->turnHead(45);
//	einstein->tiltHead(45);
	delay(2000);
	einstein->turnHead(135);
//	einstein->tiltHead(135);
	einstein->blink(500);
}
