#ifndef ARM_H
#define ARM_H

#include "common.h"
#include "servo_control.h"

class Arm{
	public:
		Arm(
			int pin_shoulder,
			int pin_rotate,
			int pin_elbow
		);
		void pitch(int pos);
		void rotate(int pos);
		void bend(int pos);
		void move(
			int pos_shoulder,
			int pos_rotate,
			int pos_elblow
		);
	private:
		ServoControl *m_pShoulder;
		ServoControl *m_pRotate;
		ServoControl *m_pElbow;
};

#endif
