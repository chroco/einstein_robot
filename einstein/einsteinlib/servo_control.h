#ifndef SERVO_CONTROL_H
#define SERVO_CONTROL_H

#include "common.h"
#include <Servo.h>

class ServoControl{
	public:
		ServoControl(unsigned int min,unsigned int max);
		void moveServo(int pos, int delay_ms);
		void attach(int pin);
	private:
		unsigned int m_Min;
		unsigned int m_Max;
		bool validPosition(int pos);
		unsigned int fixPosition(int pos);
		Servo m_Servo;
};

#endif
