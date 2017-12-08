#include "brow.h"

// Brow

Brow::Brow(int pin_left, int pin_right){
	m_pRightBrow = new ServoControl(SERVO_MIN,SERVO_MAX);
	m_pLeftBrow = new ServoControl(SERVO_MIN,SERVO_MAX);
	m_pRightBrow->attach(pin_right);
	m_pLeftBrow->attach(pin_left);
	move(SERVO_CENTER,SERVO_CENTER);
}

void Brow::move(int pos_left, int pos_right){
	m_pRightBrow->moveServo(pos_right,BROW_DELAY);
	m_pLeftBrow->moveServo(pos_left,BROW_DELAY);
}
