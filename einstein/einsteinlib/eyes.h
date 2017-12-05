#ifndef EYES_H
#define EYES_H

#include "common.h"

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
		Servo m_EyeServo_Horizontal;
		Servo m_EyeServo_Vertical;
		int m_Pin_LeftEyeLED;
		int m_Pin_RightEyeLED;
};

#endif
