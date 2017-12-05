#include "servo_control.h"

ServoControl::ServoControl(unsigned int min,unsigned int max)
	:m_Min(min),m_Max(max)
{

}

bool ServoControl::validPosition(int pos){
	return (pos >= SERVO_MIN && pos <= SERVO_MAX);
}

void ServoControl::moveServo(int pos, int delay_ms){
	int temp_pos = m_Servo->read();
	if (!validPosition(pos) || temp_pos == pos){
	return;
	}else if(temp_pos < pos){
		for(;temp_pos <= pos;++temp_pos){
			m_Servo->write(temp_pos);
			delay(delay_ms);
		}
	}else{
		for(;temp_pos >= pos;--temp_pos){
			m_Servo->write(temp_pos);
			delay(delay_ms);
		}
	}
}
