#ifndef COMMON_H
#define COMMON_H

#include <Arduino.h>
#include <Servo.h>

// Digital Pins

#define PIN_EYES_HORIZONTAL			0
#define PIN_EYES_VERTICAL				1
#define PIN_BROW_RIGHT					2
#define PIN_BROW_LEFT						3
#define PIN_JAW_RIGHT						4	
#define PIN_JAW_LEFT						5
#define PIN_HEAD_TURN						6
#define PIN_HEAD_TILT						7
#define PIN_ARM_RIGHT_SHOULDER	8
#define PIN_ARM_RIGHT_ROTATE		9
#define PIN_ARM_RIGHT_ELBOW			10
#define PIN_MOTOR_FRONT_RIGHT		11
#define PIN_MOTOR_REAR_RIGHT		12 
#define PIN_MOTOR_FRONT_LEFT		13

// Analog Pins

#define PIN_EYE_RIGHT 					A0
#define PIN_EYE_LEFT  					A1
#define PIN_MOTOR_ENABLE_RIGHT	A2
#define PIN_MOTOR_ENABLE_LEFT		A3 
#define PIN_MOTOR_REAR_LEFT			A4 

// Servos

#define SERVO_MIN 		0
#define SERVO_CENTER 	90
#define SERVO_MAX 		180

// DC Motor

#define MOTOR_SPEED 	200

// Misc defines

#define DEFAULT_DELAY 	10
#define MOUTH_DELAY 		0
#define TURN_DELAY 			DEFAULT_DELAY
#define TILT_DELAY 			DEFAULT_DELAY
#define BROW_DELAY 			0
#define SHOULDER_DELAY 	DEFAULT_DELAY
#define ROTATE_DELAY 		DEFAULT_DELAY
#define BEND_DELAY 			DEFAULT_DELAY
#define EYE_DELAY 			0

#define OFF 0
#define ON  1

#endif
