#ifndef EYES_H
#define EYES_H

#include "common.h"
#include "servo_control.h"

#define EYES_MIN SERVO_MIN
#define EYES_MAX SERVO_MAX

class Eyes{
	public:
		Eyes(
			int pin_EyeServo_Hor,
			int pin_EyeServo_Ver,
			int pin_LeftEyeLED, 
			int pin_RightEyeLED
		);
		void bothEyes(int state);
		void leftEye(int state);
		void rightEye(int state);
		void move(int pos_horizontal, int pos_vertical);
	private:
		ServoControl *m_pEyesServo_Horizontal;
		ServoControl *m_pEyesServo_Vertical;
		int m_Pin_LeftEyeLED;
		int m_Pin_RightEyeLED;
};

#endif
