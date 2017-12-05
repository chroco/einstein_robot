#include "mouth.h"

// Mouth

Mouth::Mouth(int pin_left, int pin_right){
	m_RightJaw.attach(pin_right);
	m_LeftJaw.attach(pin_left);
	move(SERVO_CENTER,SERVO_CENTER);
}

void Mouth::move(int pos_left, int pos_right){
	moveServo(&m_RightJaw,pos_right,MOUTH_DELAY);
	moveServo(&m_LeftJaw,pos_left,MOUTH_DELAY);
	//m_RightJaw.write(left);
	//m_LeftJaw.write(right);
}
