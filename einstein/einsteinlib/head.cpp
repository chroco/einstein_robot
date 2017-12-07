#include "head.h"

Head::Head(int pin_turn, int pin_tilt){
	m_pTurn->attach(pin_turn);
	m_pTilt->attach(pin_tilt);
	m_pTurn = new ServoControl(HEAD_TURN_MIN,HEAD_TURN_MAX);
	m_pTilt = new ServoControl(HEAD_TURN_MIN,HEAD_TURN_MAX);
	turn(SERVO_CENTER);
	tilt(SERVO_CENTER);
}

void Head::turn(int pos){
	m_pTurn->moveServo(pos,TURN_DELAY);
}

void Head::tilt(int pos){
	m_pTilt->moveServo(pos,TILT_DELAY);
}
