#ifndef ARM_H
#define ARM_H

#include "common.h"
#include "servo_control.h"

#define SHOULDER_MIN	20
#define SHOULDER_MAX	SERVO_MAX
#define ROTATE_MIN		90
#define ROTATE_MAX		125	
#define ELBOW_MIN			10
#define ELBOW_MAX			170

//Arm class to control the shoulder and elbow movement
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
