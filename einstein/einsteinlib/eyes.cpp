#include "eyes.h"

// Eyes

Eyes::Eyes(
	int pin_EyeServo_Hor,
	int pin_EyeServo_Ver,
	int pin_LeftEyeLED, 
	int pin_RightEyeLED
	):
	m_Pin_LeftEyeLED(pin_LeftEyeLED),
	m_Pin_RightEyeLED(pin_RightEyeLED)
{	
	m_EyeServo_Horizontal.attach(pin_EyeServo_Hor);
	m_EyeServo_Vertical.attach(pin_EyeServo_Ver);
	pinMode(m_Pin_LeftEyeLED, OUTPUT);
	pinMode(m_Pin_RightEyeLED, OUTPUT);
	bothEyes(ON);
}

void Eyes::bothEyes(int state){
	if (state==ON) state = HIGH;
	else if (state==OFF) state = LOW;
	else return;
  digitalWrite(m_Pin_LeftEyeLED,state);
  digitalWrite(m_Pin_RightEyeLED,state);
}

void Eyes::leftEye(int state){
	if (state==ON) state = HIGH;
	else if (state==OFF) state = LOW;
	else return;
  digitalWrite(m_Pin_LeftEyeLED,state);
}

void Eyes::rightEye(int state){
	if (state==ON) state = HIGH;
	else if (state=OFF) state = LOW;
	else return;
  digitalWrite(m_Pin_RightEyeLED,state);
}

void Eyes::move(int pos_horizontal, int pos_vertical){
	moveServo(
		&m_EyeServo_Horizontal,
		pos_horizontal,EYE_DELAY
	);
	moveServo(
		&m_EyeServo_Vertical,
		pos_vertical,EYE_DELAY
	);
}
