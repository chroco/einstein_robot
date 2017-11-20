#include <einstein.h>

// Eyes

Eyes::Eyes(
	int pin_Eyes_X,
	int pin_Eyes_Y,
	int pin_LeftEye, 
	int pin_RightEye)
	:m_Pin_LeftEye(pin_LeftEye),m_Pin_RightEye(pin_RightEye)
{	
	m_Eyes_X.attach(pin_Eyes_X);
	m_Eyes_Y.attach(pin_Eyes_Y);
	pinMode(m_Pin_LeftEye, OUTPUT);
	pinMode(m_Pin_RightEye, OUTPUT);
}

void Eyes::blink(int duration){
	bothEyes(OFF);
	delay(duration);
	bothEyes(ON);
}

void Eyes::bothEyes(int state){
	if (state==ON) state = HIGH;
	else if (state=OFF) state = LOW;
	else return;
  digitalWrite(m_Pin_LeftEye,state);
  digitalWrite(m_Pin_RightEye,state);
}

void Eyes::leftEye(int state){
	if (state==ON) state = HIGH;
	else if (state=OFF) state = LOW;
	else return;
  digitalWrite(m_Pin_LeftEye,state);
}

void Eyes::rightEye(int state){
	if (state==ON) state = HIGH;
	else if (state=OFF) state = LOW;
	else return;
  digitalWrite(m_Pin_RightEye,state);
}

// Head

Head::Head(int pin_turn, int pin_tilt){
	m_Turn.attach(pin_turn);
	m_Tilt.attach(pin_tilt);
}

void Head::turn(int pos){
	m_Turn.write(pos);
}

void Head::tilt(int pos){
	m_Tilt.write(pos);
}

// Einstein 

Einstein::Einstein(){
	m_pHead = new Head(INIT_TURN,INIT_TILT);
	m_pEyes = new Eyes(
			PIN_EYES_X,PIN_EYES_Y,PIN_LEFT_EYE,PIN_RIGHT_EYE
	);
}

void Einstein::turnHead(int pos){
	m_pHead->turn(pos);
}

void Einstein::tiltHead(int pos){
	m_pHead->tilt(pos);
}

void Einstein::blink(int duration){
	m_pEyes->blink(duration);
}


