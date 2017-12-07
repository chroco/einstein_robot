#ifndef HEAD_H
#define HEAD_H

#include "common.h"
#include "servo_control.h"

#define HEAD_TURN_MIN SERVO_MIN
#define HEAD_TURN_MAX SERVO_MAX

class Head{
	public:
		Head(int pin_turn,int pin_tilt);
		void turn(int pos);
		void tilt(int pos);
	private:
		ServoControl *m_pTurn;
		ServoControl *m_pTilt;
};

#endif
