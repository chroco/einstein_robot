#include "servo_control.h"

/*--------------------------------------------------------------
Function: ServoControl (Constructor)
Inputs:
	unsigned int min: Sets the minimum value for the servo
	unsigned int max: Sets the maximum value for the servo
Output: None
Description: Setup the minimum and maximum value for the servo
--------------------------------------------------------------*/
ServoControl::ServoControl(unsigned int min,unsigned int max)
	:m_Min(min),m_Max(max)
{

}

/*--------------------------------------------------------------
Function: validPosition
Inputs:
	int pos: position to check for validility
Output:
	(bool) Returns true if the position is valid for the servo
Description: Checks to see if the position is valid for the servo
--------------------------------------------------------------*/
bool ServoControl::validPosition(int pos){
	//Check position value and return true if valid
	return (pos >= m_Min && pos <= m_Max);
}

/*--------------------------------------------------------------
Function: fixPosition
Inputs:
	int pos: out of bounds position that needs to be fixed
Output:
	(unsigned int) Returns with either the valid max or min
Description: Corrects out of bounds position value by changing
them to either the max or min position of the servo
--------------------------------------------------------------*/
unsigned int ServoControl::fixPosition(int pos){
	//Check out of bounds position and return valid postion
	return (pos < m_Min) ? m_Min : m_Max;
}

/*--------------------------------------------------------------
Function: moveServo
Inputs:
	int pos: position to move the servo to
	int delay_ms: delay (milliseconds) for the movement
Output: None (void)
Description: Moves the position of the servo over a defined period
of time
--------------------------------------------------------------*/
void ServoControl::moveServo(int pos, int delay_ms){
	//Write the current servo value to a temporary value
	int temp_pos = m_Servo.read();
	
	//Check to see if the desired position is the current position
	if (temp_pos == pos){
		return;
	}
	
	//Check to see if the position is invalid
	if (!validPosition(pos)){
		//Fix the invalid position to make it valid
		pos=fixPosition(pos);
	}
	
	//Check if the current position is less then the desired location
	if(temp_pos < pos){
		//Move the servo to the desired position by increasing the servo value
		for(;temp_pos <= pos;++temp_pos){
			m_Servo.write(temp_pos);
			delay(delay_ms);
		}
	//Else the current position is greater then the desired location
	}else{
		//Move the servo to the desired position by decreasing the servo value
		for(;temp_pos >= pos;--temp_pos){
			m_Servo.write(temp_pos);
			delay(delay_ms);
		}
	}
}

/*--------------------------------------------------------------
Function: attach
Inputs:
	int pin: pin being attach to the servo
Output: None (void)
Description: Attaches a pin to a desired servo
--------------------------------------------------------------*/
void ServoControl::attach(int pin){
	//Attach a pin to a servo
	m_Servo.attach(pin);
}

