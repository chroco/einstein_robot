#ifndef EINSTEIN_H	
#define EINSTEIN_H	

#include <Arduino.h>
#include <Servo.h>

// Digital Pins

#define PIN_EYES_HORIZONTAL		0
#define PIN_EYES_VERTICAL			1
#define PIN_EYEBROW_RIGHT			2
#define PIN_EYEBROW_LEFT			3
#define PIN_JAW_RIGHT					4	
#define PIN_JAW_LEFT					5
#define PIN_HEAD_TURN					6
#define PIN_HEAD_TILT					7
#define PIN_ARM_SHOULDER			8
#define PIN_ARM_ROTATE				9
#define PIN_ARM_ELBOW					10

// Analog Pins

#define PIN_EYE_RIGHT A0
#define PIN_EYE_LEFT  A1

// Servos

#define SERVO_MIN 		0
#define SERVO_CENTER 	90
#define SERVO_MAX 		180

// Misc defines

#define DEFAULT_DELAY 	50
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

class Arm{
	public:
		Arm(
			int pin_shoulder,
			int pin_rotate,
			int pin_elbow
		);
		void vertPosition(int pos);
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

class Eyebrows{
	public:
		Eyebrows(int pin_left, int pin_right);
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
		void moveRightArm(
			int pos_shoulder,
			int pos_rotate,
			int pos_elbow
		);
		void smile();
		void frown();
		void speak(int duration);
		void raiseEyebrows();
		void lowerEyebrows();
		void neutralEyebrows();
		void turnHead(int pos);
		void tiltHead(int pos);
		void blink(int duration);
	private:
		Head *m_pHead;
		Eyes *m_pEyes;
		Mouth *m_pMouth;
		Eyebrows *m_pEyebrows;
		Arm *m_pArm;

};

#endif
