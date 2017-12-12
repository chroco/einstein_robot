#ifndef JOYRIDE_H
#define JOYRIDE_H

#include "common.h"

class DCMotor{
	public:
		DCMotor(int enable,int front,int rear);
		void forward();
		void reverse();
		void stop();
	private:
		int m_Enable;
		int m_Front;
		int m_Rear;
};

class Joyride{
	public:
		Joyride();
		void forward();
		void reverse();
		void stop();
		void turnRight(int value);
		void turnLeft(int value);
	private:
		DCMotor *m_pRightMotor;
		DCMotor *m_pLeftMotor;
};



#endif
