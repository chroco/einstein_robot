#include <einstein.h>
#include <Servo.h>

Einstein *einstein;

void setup(){
	einstein = new Einstein();

}


void loop(){
	einstein->turnHead(45);
//	pinMode(A2, OUTPUT);
	delay(500);
	einstein->turnHead(135);
	delay(500);
}
