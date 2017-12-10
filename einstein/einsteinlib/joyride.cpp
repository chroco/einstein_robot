#include "joyride.h"

/*-------------------------------------------------------------
Function: DCMotor (Constructor)
Inputs:
	int enable: pin to set the velocity of the motor with PWM
	int front: pin to enable forward movement
	int rear: pin to enable reverse movement
Ouput: 	None
Description: Constructor function for the DCMotor class
--------------------------------------------------------------*/
DCMotor::DCMotor(int enable,int front,int rear)
	:m_Enable(enable),m_Front(front),m_Rear(rear)
{
	//Set the pins to outputs and set the motor speed
	pinMode(m_Enable,OUTPUT);
	pinMode(m_Front,OUTPUT);
	pinMode(m_Rear,OUTPUT);
	analogWrite(m_Enable,MOTOR_SPEED);
}

/*-------------------------------------------------------------
Function: forward
Inputs: None
Ouput: None (void)
Description: Move a single DC motor in the forward direction
--------------------------------------------------------------*/
void DCMotor::forward(){
	//Write to the pins to move the DC motor forward
	digitalWrite(m_Front,LOW);
	digitalWrite(m_Rear,HIGH);
}

/*-------------------------------------------------------------
Function: reverse
Inputs: None
Ouput: None (void)
Description: Move a single DC motor in the reverse direction
--------------------------------------------------------------*/
void DCMotor::reverse(){
	//Write to the pins to move the DC motor in reverse
	digitalWrite(m_Front,HIGH);
	digitalWrite(m_Rear,LOW);
}

/*-------------------------------------------------------------
Function: stop
Inputs: None
Ouput: None (void)
Description: Stops a single DC motor
--------------------------------------------------------------*/
void DCMotor::stop(){
	//Write to the pins to stop the DC motors
	digitalWrite(m_Front,LOW);
	digitalWrite(m_Rear,LOW);
}

/*-------------------------------------------------------------
Function: Joyride (Constructor)
Inputs: None
Ouput: None
Description: Constructor function for the Joyride class used for 
moving Einstein
--------------------------------------------------------------*/
Joyride::Joyride(){
	//Setup the right DC motor
	m_pRightMotor = new DCMotor(
		PIN_MOTOR_ENABLE_RIGHT,
		PIN_MOTOR_FRONT_RIGHT,
		PIN_MOTOR_REAR_RIGHT
	);
	//Setup the left DC motor
	m_pLeftMotor = new DCMotor(
		PIN_MOTOR_ENABLE_LEFT,
		PIN_MOTOR_FRONT_LEFT,
		PIN_MOTOR_REAR_LEFT
	);
}

/*-------------------------------------------------------------
Function: forward
Inputs: None
Ouput: None (void)
Description: Moves both DC motors forward
--------------------------------------------------------------*/
void Joyride::forward(){
	//Set both DC motors to move forward
	m_pRightMotor->forward();
	m_pLeftMotor->forward();
}

/*-------------------------------------------------------------
Function: reverse
Inputs: None
Ouput: None (void)
Description: Moves both DC motors in reverse
--------------------------------------------------------------*/
void Joyride::reverse(){
	//Set both DC motors to move in reverse
	m_pRightMotor->reverse();
	m_pLeftMotor->reverse();
}

/*-------------------------------------------------------------
Function: stop
Inputs: None
Ouput: None (void)
Description: Stops both DC motors
--------------------------------------------------------------*/
void Joyride::stop(){
	//Set both DC motors to stop
	m_pRightMotor->stop();
	m_pLeftMotor->stop();
}

/*-------------------------------------------------------------
Function: turnRight
Inputs: None
Ouput: None (void)
Description: Stops the left DC motor and moves the right DC motor
forward
--------------------------------------------------------------*/
void Joyride::turnRight(int value){
	//Set right DC motor to move forward
	m_pRightMotor->forward();
	m_pLeftMotor->stop();
}

/*-------------------------------------------------------------
Function: turnLeft
Inputs: None
Ouput: None (void)
Description: Stops the right DC motor and moves the left DC motor
forward
--------------------------------------------------------------*/
void Joyride::turnLeft(int value){
	//Set left DC motor to move forward
	m_pRightMotor->stop();
	m_pLeftMotor->forward();
}
