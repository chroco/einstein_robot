#ifndef SERVO_CONTROL_H
#define SERVO_CONTROL_H

class ServoControl{
	public:
		ServoControl();
		void moveServo(Servo *servo,int pos, int delay_ms);
	private:
		bool validPosition(int pos);
		Servo m_Servo;
};



#endif
