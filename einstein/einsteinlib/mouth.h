#ifndef MOUTH_H
#define MOUTH_H

#include "common.h"

class Mouth{
	public:
		Mouth(int pin_left, int pin_right);
		void move(int left, int right);
	private:
		Servo m_RightJaw;
		Servo m_LeftJaw;
};

#endif
