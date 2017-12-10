#include <einstein.h>

// Einstein 

/*------------------------------------------------------
Function: Enstein (Constructor)
Inputs: None
Output: None
Description: Constructor function for the Einstein class
------------------------------------------------------*/
Einstein::Einstein(){
//*
	//Create a new instance of Einstein's arm
	m_pRightArm = new Arm(
		PIN_ARM_RIGHT_SHOULDER,
		PIN_ARM_RIGHT_ROTATE,
		PIN_ARM_RIGHT_ELBOW
	);
//*/
	//Create a new instance of Einstein's mouth, brow, and head
	m_pMouth = new Mouth(PIN_JAW_LEFT,PIN_JAW_RIGHT);
	m_pBrow = new Brow(PIN_BROW_LEFT,PIN_BROW_RIGHT);
	m_pHead = new Head(PIN_HEAD_TURN,PIN_HEAD_TILT);
//*
	//Create a new instance of Einstein's eyes
	m_pEyes = new Eyes(
		PIN_EYES_HORIZONTAL,
		PIN_EYES_VERTICAL,
		PIN_EYE_LEFT,
		PIN_EYE_RIGHT
	);
//*/
	//Create a new instance of Joyride to control base movement
	m_pJoyride = new Joyride();
}

/*------------------------------------------------------
Function: blink
Inputs:
	int duration: duration that the eye LEDs stay off
Output: None (void)
Description: Blinks Einstein's eyes by turning off then on
the LEDs in the eyes
------------------------------------------------------*/
void Einstein::blink(int duration){
	//Turn off both eye LED's and delay for a given time
	m_pEyes->bothEyes(OFF);
	delay(duration);
	
	//Turn on both eye LED's
	m_pEyes->bothEyes(ON);
}

/*------------------------------------------------------
Function: moveEyes
Inputs:
	int pos_h: horizontal position to move the eyes to
	int pos_v: vertical position to move the eyes to
Output:	None (void)
Description: Moves both of Einstein's eyes to a given
vertical and horizontal location
------------------------------------------------------*/
void Einstein::moveEyes(int pos_h,int pos_v){
	//Move the eyes to a given vertical and horizontal location
	m_pEyes->move(pos_h,pos_v);
}

/*------------------------------------------------------
Function: raiseBrow
Inputs: None
Output: None (void)
Description: Raises both of Einstein's eye brows
------------------------------------------------------*/
void Einstein::raiseBrow(){
	//Raise both of Einstein's eye brows
	m_pBrow->move(0,180);
}

/*------------------------------------------------------
Function: lowerBrow
Inputs: None
Output: None (void)
Description: Lowers both of Einstein's eye brows
------------------------------------------------------*/
void Einstein::lowerBrow(){
	//Lowers both of Einstein's eyes brows
	m_pBrow->move(180,0);
}

/*------------------------------------------------------
Function: moveRightArm
Inputs:
	int pos_shoulder: position to rotate the shoulder to
	int pos_rotate: position to rotate the arm to
	int pos_elbow: position to bend the elbow to
Output: None (void)
Description: Moves Einstein's arm to a given position
------------------------------------------------------*/
void Einstein::moveRightArm(
	int pos_shoulder,
	int pos_rotate,
	int pos_elbow
){
	//Moves the shoulder to a given location
	m_pRightArm->pitch(pos_shoulder);
	
	//Rotates the arm to a given location
	m_pRightArm->rotate(pos_rotate);
	
	//Moves the elbow to a given location
	m_pRightArm->bend(pos_elbow);
}

/*------------------------------------------------------
Function: pitchRightArm
Inputs:
	int pos: position to rotate the shoulder to
Output: None (void)
Description: Rotates Einstein's shoulder to a given position
------------------------------------------------------*/
void Einstein::pitchRightArm(int pos){
	//Rotate the shoulder to a given position
	m_pRightArm->pitch(pos);
}

/*------------------------------------------------------
Function: rotateRightArm
Inputs:
	int pos: position to rotate the arm to
Output: None (void)
Description: Rotates Einstein's arm to a given position
------------------------------------------------------*/
void Einstein::rotateRightArm(int pos){
	//Rotate the arm to a given position
	m_pRightArm->rotate(pos);
}

/*------------------------------------------------------
Function: bendRightArm
Inputs:
	int pos: position to move the elbow to
Output: None (void)
Description: Move Einstein's elbow to a given postion
------------------------------------------------------*/
void Einstein::bendRightArm(int pos){
	//Move the elbow to a given position
	m_pRightArm->bend(pos);
}

/*------------------------------------------------------
Function: smile
Inputs: None
Output: None (void)
Description: Moves Einstein's mouth to the smiling position
------------------------------------------------------*/
void Einstein::smile(){
	//Moves the mouth to a smiling position
	m_pMouth->move(0,180);
}

/*------------------------------------------------------
Function: frown
Inputs: None
Output: None (void)
Description: Moves Einstein's mouth to the frowning position
------------------------------------------------------*/
void Einstein::frown(){
	//Moves the mouth to a frowning position
	m_pMouth->move(180,0);
}

/*------------------------------------------------------
Function: speak
Inputs: None
Output: None (void)
Description: Moves Einstein's mouth to the speaking position
------------------------------------------------------*/
void Einstein::speak(int duration){
	//Moves the mouth into the speaking position
	m_pMouth->move(180,0);
}

/*------------------------------------------------------
Function: neutralBrow
Inputs: None
Output: None (void)
Description: Places Einstein's eye brows in their relaxed 
positon (neutral)
------------------------------------------------------*/
void Einstein::neutralBrow(){
	//Centers the eye brows 
	m_pBrow->move(SERVO_CENTER,SERVO_CENTER);
}

/*------------------------------------------------------
Function: turnHead
Inputs:
	int pos: position to turn the head to
Output: None (void)
Description: Turns Einstein's head to a given position
------------------------------------------------------*/
void Einstein::turnHead(int pos){
	//Turns the head to a given position
	m_pHead->turn(pos);
}

/*------------------------------------------------------
Function: tiltHead
Inputs:
	int pos: position to tilt the head to
Output: None (void)
Description: Tilts Einstein's head to a given position
------------------------------------------------------*/
void Einstein::tiltHead(int pos){
	//Tilts Einstein's head to a given position
	m_pHead->tilt(pos);
}

/*------------------------------------------------------
Function: forward
Inputs: None
Output: None (void)
Description: Moves Einstein's base forward
------------------------------------------------------*/
void Einstein::forward(){
	//Moves Einstein forward
	m_pJoyride->forward();
}

/*------------------------------------------------------
Function: reverse
Inputs: None
Output: None (void)
Description: Moves Einstein's base in reverse
------------------------------------------------------*/
void Einstein::reverse(){
	//Moves Einstein backwards
	m_pJoyride->reverse();
}

/*------------------------------------------------------
Function: stop
Inputs: None
Output: None (void)
Description: Stops Einstein's base from moving
------------------------------------------------------*/
void Einstein::stop(){
	//Stop Einstein's base movement
	m_pJoyride->stop();
}
