#ifndef EINSTEIN_H	
#define EINSTEIN_H	

#include <Arduino.h>
#include <Servo.h>

// Digital Pins

#define PIN_EYES_HOR 	1
#define PIN_EYES_VER 	2
#define PIN_HEAD_TURN 9
#define PIN_HEAD_TILT 10

// Analog Pins

#define PIN_RIGHT_EYE A0
#define PIN_LEFT_EYE  A1

// Servos

#define SERVO_MIN 		0
#define SERVO_CENTER 	90
#define SERVO_MAX 		180

// Initialization 

#define INIT_TURN 		SERVO_CENTER
#define INIT_TILT 		SERVO_CENTER

// Misc defines

#define OFF 0
#define ON  1

class Eyes{
public:
	Eyes(
		int pin_EyeServo_Hor,
		int pin_EyeServo_Ver,
		int pin_LeftEyeLED, 
		int pin_RightEyeLED
	);
	void blink(int duration);
	void bothEyes(int state);
	void leftEye(int state);
	void rightEye(int state);
private:
	Servo m_EyeServo_Hor;
	Servo m_EyeServo_Ver;
	int m_Pin_LeftEyeLED;
	int m_Pin_RightEyeLED;
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
