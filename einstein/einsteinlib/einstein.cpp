#include <einstein.h>

// Einstein 

Einstein::Einstein(){
//*
	m_pRightArm = new Arm(
		PIN_ARM_RIGHT_SHOULDER,
		PIN_ARM_RIGHT_ROTATE,
		PIN_ARM_RIGHT_ELBOW
	);
//*/
	m_pMouth = new Mouth(PIN_JAW_LEFT,PIN_JAW_RIGHT);
	m_pBrow = new Brow(PIN_BROW_LEFT,PIN_BROW_RIGHT);
	m_pHead = new Head(PIN_HEAD_TURN,PIN_HEAD_TILT);
//*
	m_pEyes = new Eyes(
		PIN_EYES_HORIZONTAL,
		PIN_EYES_VERTICAL,
		PIN_EYE_LEFT,
		PIN_EYE_RIGHT
	);
//*/
//	m_pJoyride = new Joyride();
}

void Einstein::moveRightArm(
	int pos_shoulder,
	int pos_rotate,
	int pos_elbow
){
	m_pRightArm->pitch(pos_shoulder);
	m_pRightArm->rotate(pos_rotate);
	m_pRightArm->bend(pos_elbow);
}

void Einstein::pitchRightArm(int pos){
	m_pRightArm->pitch(pos);
}

void Einstein::rotateRightArm(int pos){
	m_pRightArm->rotate(pos);
}

void Einstein::bendRightArm(int pos){
	m_pRightArm->bend(pos);
}

void Einstein::smile(){
	m_pMouth->move(0,180);
}

void Einstein::frown(){
	m_pMouth->move(180,0);
}

void Einstein::speak(int duration){
	// TODO: implement me
}

void Einstein::raiseBrow(){
	m_pBrow->move(180,0);
}

void Einstein::lowerBrow(){
	m_pBrow->move(135,45);
}

void Einstein::neutralBrow(){
	m_pBrow->move(SERVO_CENTER,SERVO_CENTER);
}

void Einstein::turnHead(int pos){
	m_pHead->turn(pos);
}

void Einstein::tiltHead(int pos){
	m_pHead->tilt(pos);
}

void Einstein::blink(int duration){
	m_pEyes->bothEyes(OFF);
	delay(duration);
	m_pEyes->bothEyes(ON);
}

void Einstein::forward(){
	m_pJoyride->forward();
}

void Einstein::reverse(){
	m_pJoyride->reverse();
}

void Einstein::stop(){
	m_pJoyride->stop();
}
