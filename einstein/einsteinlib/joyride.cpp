#include "joyride.h"

DCMotor::DCMotor(int enable,int front,int rear)
	:m_Enable(enable),m_Front(front),m_Rear(rear)
{
	pinMode(m_Enable,OUTPUT);
	pinMode(m_Front,OUTPUT);
	pinMode(m_Rear,OUTPUT);
	analogWrite(m_Enable,MOTOR_SPEED);
}

void DCMotor::forward(){
	digitalWrite(m_Front,LOW);
	digitalWrite(m_Rear,HIGH);
}

void DCMotor::reverse(){
	digitalWrite(m_Front,HIGH);
	digitalWrite(m_Rear,LOW);
}

void DCMotor::stop(){
	digitalWrite(m_Front,LOW);
	digitalWrite(m_Rear,LOW);
}

Joyride::Joyride(){
	m_pRightMotor = new DCMotor(
		PIN_MOTOR_ENABLE_RIGHT,
		PIN_MOTOR_FRONT_RIGHT,
		PIN_MOTOR_REAR_RIGHT
	);
	m_pLeftMotor = new DCMotor(
		PIN_MOTOR_ENABLE_LEFT,
		PIN_MOTOR_FRONT_LEFT,
		PIN_MOTOR_REAR_LEFT
	);
}

void Joyride::forward(){
	m_pRightMotor->forward();
	m_pLeftMotor->forward();
}

void Joyride::reverse(){
	m_pRightMotor->reverse();
	m_pLeftMotor->reverse();
}

void Joyride::stop(){
	m_pRightMotor->stop();
	m_pLeftMotor->stop();
}

void Joyride::turnRight(int value){
	// TODO: implement me
}

void Joyride::turnLeft(int value){
	// TODO: implement me
}


