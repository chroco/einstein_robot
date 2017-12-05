#include "arm.h"

// Arm

Arm::Arm(
	int pin_shoulder,
	int pin_rotate,
	int pin_elbow
){
	
	m_Shoulder.attach(pin_shoulder);
	m_Rotate.attach(pin_rotate);
	m_Elbow.attach(pin_elbow);
	m_pShoulder = new ServoControl(SHOULDER_MIN,SHOULDER_MAX);
	m_pRotate = new ServoControl(ROTATE_MIN,ROTATE_MAX);
	m_pElbow = new ServoControl(ELBOW_MIN,ELBOW_MAX);
	move(SERVO_CENTER,SERVO_CENTER,SERVO_CENTER);
}

void Arm::pitch(int pos){
	m_pShoulder->moveServo(pos,SHOULDER_DELAY);
}

void Arm::rotate(int pos){
	m_pRotate->moveServo(pos,ROTATE_DELAY);
}

void Arm::bend(int pos){
	m_pElbow->moveServo(pos,BEND_DELAY);
}

void Arm::move(
	int pos_shoulder,
	int pos_rotate,
	int pos_elbow
){
	pitch(pos_shoulder);
	rotate(pos_rotate);
	bend(pos_elbow);
}
