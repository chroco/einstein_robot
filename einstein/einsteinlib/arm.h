#ifndef ARM_H
#define ARM_H

#include "common.h"
#include "servo_control.h"

#define SHOULDER_MIN	SERVO_MIN 
#define SHOULDER_MAX	SERVO_MAX
#define ROTATE_MIN		SERVO_MIN
#define ROTATE_MAX		SERVO_MAX
#define ELBOW_MIN			SERVO_MIN + 10
#define ELBOW_MAX			SERVO_MAX - 10

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
