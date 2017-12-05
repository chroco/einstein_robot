#ifndef HEAD_H
#define HEAD_H

#include "common.h"

class Head{
	public:
		Head(int pin_turn,int pin_tilt);
		void turn(int pos);
		void tilt(int pos);
	private:
		Servo m_Turn;
		Servo m_Tilt;
};

#endif
