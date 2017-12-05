#include "brow.h"

// Brow

Brow::Brow(int pin_left, int pin_right){
	m_RightBrow.attach(pin_right);
	m_LeftBrow.attach(pin_left);
//	moveServo(&m_RightBrow,SERVO_CENTER,BROW_DELAY);
//	moveServo(&m_LeftBrow,SERVO_CENTER,BROW_DELAY);
	move(SERVO_CENTER,SERVO_CENTER);
}

void Brow::move(int pos_left, int pos_right){
	moveServo(&m_RightBrow,pos_right,BROW_DELAY);
	moveServo(&m_LeftBrow,pos_left,BROW_DELAY);
//	m_RightBrow.write(pos_right);
//	m_LeftBrow.write(pos_left);
}
