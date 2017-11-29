#ifndef EINSTEIN_H	
#define EINSTEIN_H	

#include <Arduino.h>
#include <Servo.h>

// Digital Pins

#define PIN_EYES_HORIZONTAL			0
#define PIN_EYES_VERTICAL				1
#define PIN_BROW_RIGHT					2
#define PIN_BROW_LEFT						3
#define PIN_JAW_RIGHT						4	
#define PIN_JAW_LEFT						5
#define PIN_HEAD_TURN						6
#define PIN_HEAD_TILT						7
#define PIN_ARM_RIGHT_SHOULDER	8
#define PIN_ARM_RIGHT_ROTATE		9
#define PIN_ARM_RIGHT_ELBOW			10
#define PIN_MOTOR_FRONT_RIGHT		11
#define PIN_MOTOR_REAR_RIGHT		12 
#define PIN_MOTOR_FRONT_LEFT		13

// Analog Pins

#define PIN_EYE_RIGHT 					A0
#define PIN_EYE_LEFT  					A1
#define PIN_MOTOR_ENABLE_RIGHT	A2
#define PIN_MOTOR_ENABLE_LEFT		A3 
#define PIN_MOTOR_REAR_LEFT			A4 

// Servos

#define SERVO_MIN 		0
#define SERVO_CENTER 	90
#define SERVO_MAX 		180

// DC Motor

#define MOTOR_SPEED 	200

// Misc defines

#define DEFAULT_DELAY 	10
#define MOUTH_DELAY 		0
#define TURN_DELAY 			DEFAULT_DELAY
#define TILT_DELAY 			DEFAULT_DELAY
#define BROW_DELAY 			0
#define SHOULDER_DELAY 	DEFAULT_DELAY
#define ROTATE_DELAY 		DEFAULT_DELAY
#define BEND_DELAY 			DEFAULT_DELAY
#define EYE_DELAY 			0

#define OFF 0
#define ON  1

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

class Arm{
	public:
		Arm(
			int pin_shoulder,
			int pin_rotate,
			int pin_elbow
		);
		void levelArm(int pos);
		void rotate(int pos);
		void bend(int pos);
		void move(
			int pos_shoulder,
			int pos_rotate,
			int pos_elblow
		);
	private:
		Servo m_Shoulder;
		Servo m_Rotate;
		Servo m_Elbow;
};

class Mouth{
	public:
		Mouth(int pin_left, int pin_right);
		void move(int left, int right);
	private:
		Servo m_RightJaw;
		Servo m_LeftJaw;
};

class Brow{
	public:
		Brow(int pin_left, int pin_right);
		void move(int left, int right);
	private:
		Servo m_RightBrow;
		Servo m_LeftBrow;
};

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
		void smile();
		void frown();
		void speak(int duration);
		void raiseBrow();
		void lowerBrow();
		void neutralBrow();
		void turnHead(int pos);
		void tiltHead(int pos);
		void blink(int duration);
		void forward();
		void reverse();
		void stop();
		void moveRightArm(
			int pos_shoulder,
			int pos_rotate,
			int pos_elbow
		);	
		void rotateArm(int pos);
		void bendArm(int pos);
		void levelArm(int pos);
	private:
		Arm *m_pRightArm;
		Mouth *m_pMouth;
		Brow *m_pBrow;
		Eyes *m_pEyes;
		Head *m_pHead;
		Joyride *m_pJoyride;

};

#endif
