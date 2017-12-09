#ifndef MOUTH_H
#define MOUTH_H

#include "common.h"
#include "servo_control.h"

#define MOUTH_MIN	75 
#define MOUTH_MAX 105

class Mouth{
	public:
		Mouth(int pin_left, int pin_right);
		void move(int left, int right);
	private:
		ServoControl *m_pRightJaw;
		ServoControl *m_pLeftJaw;
};

#endif
