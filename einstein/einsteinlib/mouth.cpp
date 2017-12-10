#include "mouth.h"

// Mouth

/*--------------------------------------------------------------
Function: Mouth
Inputs:
	int pin_left: pin for the left jaw movement
	int pin_right: pin for the right jaw movement
Output: None
Description: Constructor function for the Mouth class
--------------------------------------------------------------*/
Mouth::Mouth(int pin_left, int pin_right){
	//Create a new instance of ServoControl to control the movement of the mouth
	m_pRightJaw = new ServoControl(MOUTH_MIN,MOUTH_MAX);
	m_pLeftJaw = new ServoControl(MOUTH_MIN,MOUTH_MAX);
	
	//Attach the servos to their pins
	m_pRightJaw->attach(pin_right);
	m_pLeftJaw->attach(pin_left);
	
	//Center the positioning of the mouth
	move(SERVO_CENTER,SERVO_CENTER);
}

/*--------------------------------------------------------------
Function: move
Inputs:
	int pos_left: position to move the right eye to
	int pos_right: position to move the left eye to
Output: None (void)
Description: Moves Einstein's mouth to a given position
--------------------------------------------------------------*/
void Mouth::move(int pos_left, int pos_right){
	//Moves the right jaw to a position at a defined speed
	m_pRightJaw->moveServo(pos_right,MOUTH_DELAY);
	
	//Moves the left jaw to a position at a defined speed
	m_pLeftJaw->moveServo(pos_left,MOUTH_DELAY);
}

