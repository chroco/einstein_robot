#ifndef BROW_H
#define BROW_H

#include "common.h"
#include "servo_control.h"

#define BROW_MIN SERVO_MIN
#define BROW_MAX SERVO_MAX

class Brow{
	public:
		Brow(int pin_left, int pin_right);
		void move(int left, int right);
	private:
		ServoControl *m_pRightBrow;
		ServoControl *m_pLeftBrow;
};

#endif
