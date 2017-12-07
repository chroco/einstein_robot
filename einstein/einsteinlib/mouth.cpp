#include "mouth.h"

// Mouth

Mouth::Mouth(int pin_left, int pin_right){
	m_pRightJaw->attach(pin_right);
	m_pLeftJaw->attach(pin_left);
	m_pRightJaw = new ServoControl(MOUTH_MIN,MOUTH_MAX);
	m_pLeftJaw = new ServoControl(MOUTH_MIN,MOUTH_MAX);
	move(SERVO_CENTER,SERVO_CENTER);
}

void Mouth::move(int pos_left, int pos_right){
	m_pRightJaw->moveServo(pos_right,MOUTH_DELAY);
	m_pLeftJaw->moveServo(pos_left,MOUTH_DELAY);
}

