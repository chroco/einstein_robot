#include "brow.h"

// Brow

#define LEFT_BROW_MIN		45
#define LEFT_BROW_MAX		135
#define RIGHT_BROW_MIN	0
#define RIGHT_BROW_MAX	185

Brow::Brow(int pin_left, int pin_right){
	m_pRightBrow = new ServoControl(RIGHT_BROW_MIN,RIGHT_BROW_MAX);
	m_pLeftBrow = new ServoControl(LEFT_BROW_MIN,LEFT_BROW_MAX);
	m_pRightBrow->attach(pin_right);
	m_pLeftBrow->attach(pin_left);
	move(SERVO_CENTER,SERVO_CENTER);
}

void Brow::move(int pos_left, int pos_right){
	m_pRightBrow->moveServo(pos_right,BROW_DELAY);
	m_pLeftBrow->moveServo(pos_left,BROW_DELAY);
}
