#ifndef EINSTEIN_H	
#define EINSTEIN_H	

#include <Servo.h>

#define PIN_NECK_TURN 9
#define PIN_NECK_TILT 10

#define INIT_TURN
#define INIT_TILT


class Einstein{
	public:
		Einstein();
	private:
		Head *m_pHead;
};

class Head{
	public:
		Head();
		void turn(int pos);
		void tilt(int pos);
	private:
//		Eye *m_pRightEye;
//		Eye *m_pLeftEye;
//		Eyebrow *m_pRightEyebrow;
//		Eyebrow *m_pLeftEyebrow;
		Servo m_NeckTurn;
		Servo m_NeckTilt;

};

/*
class Eye{
	public:
		Eye(int pin);
		void blink();


	private:
		Servo 
};

class Eyebrow{
	public:
		Eyebrow(int pin);

	private:

};
//*/

#endif
