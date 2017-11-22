#include <einstein.h>

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
	m_EyeServo_Hor.attach(pin_EyeServo_Hor);
	m_EyeServo_Hor.attach(pin_EyeServo_Ver);
	pinMode(m_Pin_LeftEyeLED, OUTPUT);
	pinMode(m_Pin_RightEyeLED, OUTPUT);
	bothEyes(ON);
}

void Eyes::blink(int duration){
	bothEyes(OFF);
	delay(duration);
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

// Head

Head::Head(int pin_turn, int pin_tilt){
	m_Turn.attach(pin_turn);
	m_Tilt.attach(pin_tilt);
	turn(SERVO_CENTER);
	tilt(SERVO_CENTER);
}

void Head::turn(int pos){
	m_Turn.write(pos);
}

void Head::tilt(int pos){
	m_Tilt.write(pos);
}

// Einstein 

Einstein::Einstein(){
	m_pHead = new Head(PIN_HEAD_TURN,PIN_HEAD_TILT);
	m_pEyes = new Eyes(
		PIN_EYES_HOR,PIN_EYES_VER,PIN_LEFT_EYE,PIN_RIGHT_EYE
	);
}

void Einstein::turnHead(int pos){
	if(pos >= SERVO_MIN && pos <= SERVO_MAX)
		m_pHead->turn(pos);
}

void Einstein::tiltHead(int pos){
	if(pos >= SERVO_MIN && pos <= SERVO_MAX)
		m_pHead->tilt(pos);
}

void Einstein::blink(int duration){
	m_pEyes->blink(duration);
}


