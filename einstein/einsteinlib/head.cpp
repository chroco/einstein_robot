#include "head.h"

Head::Head(int pin_turn, int pin_tilt){
	m_Turn.attach(pin_turn);
	m_Tilt.attach(pin_tilt);
	turn(SERVO_CENTER);
	tilt(SERVO_CENTER);
}

void Head::turn(int pos){
	moveServo(&m_Turn,pos,TURN_DELAY);
	//m_Turn.write(pos);
}

void Head::tilt(int pos){
	moveServo(&m_Tilt,pos,TILT_DELAY);
	//	m_Tilt.write(pos);
}
