#include "head.h"

/*--------------------------------------------------------------
Function: Head (constructor)
Inputs:
	int pin_turn: pin to control the turning of Einstein's head
	int pin_tilt: pin to control the tilting of Einstein's head
Output: None
Description: Constructor function for the Head class
--------------------------------------------------------------*/
Head::Head(int pin_turn, int pin_tilt){
	//Create a new instance of ServoControl to control turn and tilt
	m_pTurn = new ServoControl(HEAD_TURN_MIN,HEAD_TURN_MAX);
	m_pTilt = new ServoControl(HEAD_TILT_MIN,HEAD_TILT_MAX);
	
	//Attachs the servos to their pins
	m_pTurn->attach(pin_turn);
	m_pTilt->attach(pin_tilt);
	
	//Centers the positioning of the head
	turn(SERVO_CENTER);
	tilt(SERVO_CENTER);
}

/*--------------------------------------------------------------
Function: turn
Inputs:
	int pos: position to turn Einstein's head to
Output: None (void)
Description: Turns Einstein's head to a given position
--------------------------------------------------------------*/
void Head::turn(int pos){
	//Turns Einstein's head to a postion at a defined speed
	m_pTurn->moveServo(pos,TURN_DELAY);
}

/*--------------------------------------------------------------
Function: tilt
Inputs:
	int pos: position to tilt Einstein's head to
Output: None (void)
Description: Tilts Einstein's head to a given position
--------------------------------------------------------------*/
void Head::tilt(int pos){
	//Tilts Einstein's head to a position at a defined speed
	m_pTilt->moveServo(pos,TILT_DELAY);
}
