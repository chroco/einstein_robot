#include "arm.h"

/*--------------------------------------------------------------
Function: Arm (Constructor)
Inputs: None
Output: None
Description: Constructor function for the Arm class
--------------------------------------------------------------*/
Arm::Arm(
	int pin_shoulder,
	int pin_rotate,
	int pin_elbow
){
	//Create a new instance of ServoControl to control the movement of the arm
	m_pShoulder = new ServoControl(SHOULDER_MIN,SHOULDER_MAX);
	m_pRotate = new ServoControl(ROTATE_MIN,ROTATE_MAX);
	m_pElbow = new ServoControl(ELBOW_MIN,ELBOW_MAX);
	
	//Attach the servos to their pins
	m_pShoulder->attach(pin_shoulder);
	m_pRotate->attach(pin_rotate);
	m_pElbow->attach(pin_elbow);
	
	//Center the positioning of the arm
	move(SERVO_CENTER,SERVO_CENTER,SERVO_CENTER);
}

/*--------------------------------------------------------------
Function: pitch
Inputs:
	int pos: position to rotate Einstein's shoulder joint to
Output:	None (void)
Description: Rotates Einstein's shoulder to a given position
--------------------------------------------------------------*/
void Arm::pitch(int pos){
	//Rotate Einstein's shoulder to a postion at a defined speed
	m_pShoulder->moveServo(pos,SHOULDER_DELAY);
}

/*--------------------------------------------------------------
Function: rotate
Inputs: 
	int pos: position to rotate Einstein's arm joint to
Output:	None (void)
Description: Rotate Einstein's arm to a given position
--------------------------------------------------------------*/
void Arm::rotate(int pos){
	//Rotate Einstein's arm to a postion at a defined speed
	m_pRotate->moveServo(pos,ROTATE_DELAY);
}

/*--------------------------------------------------------------
Function: bend
Inputs:
	int pos: position to bend Einstein's elbow joint to
Output:	None (void)
Description: Bend Einstein's arm to a given position
--------------------------------------------------------------*/
void Arm::bend(int pos){
	//Bend Einstein's arm to a position at a defined speed
	m_pElbow->moveServo(pos,BEND_DELAY);
}

/*--------------------------------------------------------------
Function: move
Inputs:
	int pos_shoulder: position to rotate Einstein's shoulder joint to
	int pos_rotate: position to rotate Einstein's arm joint to
	int pos_elbow: position to bend Einstein's arm joint to
Output:	None (void)
Description: Moves all of the three joint in Einstein's arm to a given position
--------------------------------------------------------------*/
void Arm::move(
	int pos_shoulder,
	int pos_rotate,
	int pos_elbow
){
	//Move all of the arms joints to the positions given
	pitch(pos_shoulder);
	rotate(pos_rotate);
	bend(pos_elbow);
}
