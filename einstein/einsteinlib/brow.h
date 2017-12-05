#ifndef BROW_H
#define BROW_H

#include "common.h"

class Brow{
	public:
		Brow(int pin_left, int pin_right);
		void move(int left, int right);
	private:
		Servo m_RightBrow;
		Servo m_LeftBrow;
};

#endif
