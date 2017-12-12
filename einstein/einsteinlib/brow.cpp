#include "brow.h"

// Brow

#define LEFT_BROW_MIN		45
#define LEFT_BROW_MAX		135
#define RIGHT_BROW_MIN	0
#define RIGHT_BROW_MAX	185

/*------------------------------------------------------------
Function: Brow (Constructor)
Input:
	int pin_left: pin of the left eye brow
	int pin_right: pin of the right eye brow
Output: None
Description: Constructor function for the Brow class
------------------------------------------------------------*/
Brow::Brow(int pin_left, int pin_right){
	//Create a new instance of ServoControl to control eye brow movement
	m_pRightBrow = new ServoControl(RIGHT_BROW_MIN,RIGHT_BROW_MAX);
	m_pLeftBrow = new ServoControl(LEFT_BROW_MIN,LEFT_BROW_MAX);
	
	//Attach the servos to their pins
	m_pRightBrow->attach(pin_right);
	m_pLeftBrow->attach(pin_left);
	
	//Center the position of both eye brows
	move(SERVO_CENTER,SERVO_CENTER);
}

/*------------------------------------------------------------
Function: move
Input:
	int pos_left: position to move Einstein's left eye brow to
	int pos_right: position to move Einstein's right eye brow to
Output:	None (void)
Description: Moves Einstein's eye brows to a given position
------------------------------------------------------------*/
void Brow::move(int pos_left, int pos_right){
	//Move Einstein's eye brows to a position at a defined speed
	m_pRightBrow->moveServo(pos_right,BROW_DELAY);
	m_pLeftBrow->moveServo(pos_left,BROW_DELAY);
}
