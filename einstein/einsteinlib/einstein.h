#ifndef EINSTEIN_H	
#define EINSTEIN_H	

#include <Arduino.h>
#include <Servo.h>

#define OFF 0
#define ON  1

#define PIN_LEFT_EYE  1
#define PIN_RIGHT_EYE 2
#define PIN_HEAD_TURN 9
#define PIN_HEAD_TILT 10

#define PIN_EYES_X 		A2
#define PIN_EYES_Y 		A3

#define SERVO_MIN 		0
#define SERVO_CENTER 	90
#define SERVO_MAX 		180

#define INIT_TURN 		SERVO_CENTER
#define INIT_TILT 		SERVO_CENTER

class Eyes{
	public:
		Eyes(
			int pin_Eyes_X,
			int pin_Eyes_Y,
			int pin_LeftEye, 
			int pin_RightEye
		);
		void blink(int duration);
		void bothEyes(int state);
		void leftEye(int state);
		void rightEye(int state);
	private:
		Servo m_Eyes_X;
		Servo m_Eyes_Y;
		int m_Pin_LeftEye;
		int m_Pin_RightEye;
};

class Head{
	public:
		Head(int pin_turn,int pin_tilt);
		void turn(int pos);
		void tilt(int pos);
	private:
		Servo m_Turn;
		Servo m_Tilt;
};

class Einstein{
	public:
		Einstein();
		void turnHead(int pos);
		void tiltHead(int pos);
		void blink(int duration);
	private:
		Head *m_pHead;
		Eyes *m_pEyes;
};

#endif
