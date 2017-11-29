#include <einstein.h>

bool validPosition(int pos){
	return (pos >= SERVO_MIN && pos <= SERVO_MAX);
}

void moveServo(Servo *servo,int pos, int delay_ms){
	int temp_pos = servo->read();
	if (!validPosition(pos) || temp_pos == pos){
		return;
	}else if(temp_pos < pos){
		for(;temp_pos <= pos;++temp_pos){
			servo->write(temp_pos);
			delay(delay_ms);
		}
	}else{
		for(;temp_pos >= pos;--temp_pos){
			servo->write(temp_pos);
			delay(delay_ms);
		}
	}
}

DCMotor::DCMotor(int enable,int front,int rear)
	:m_Enable(enable),m_Front(front),m_Rear(rear)
{
	pinMode(m_Enable,OUTPUT);
	pinMode(m_Front,OUTPUT);
	pinMode(m_Rear,OUTPUT);
	analogWrite(m_Enable,MOTOR_SPEED);
}

void DCMotor::forward(){
	digitalWrite(m_Front,HIGH);
	digitalWrite(m_Rear,LOW);
}

void DCMotor::reverse(){
	digitalWrite(m_Front,LOW);
	digitalWrite(m_Rear,HIGH);
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

void turnRight(int value){
	// TODO: implement me
}

void turnLeft(int value){
	// TODO: implement me
}

// Arm

Arm::Arm(
	int pin_shoulder,
	int pin_rotate,
	int pin_elbow
){
	m_Shoulder.attach(pin_shoulder);
	m_Rotate.attach(pin_rotate);
	m_Elbow.attach(pin_elbow);
	move(SERVO_CENTER,SERVO_CENTER,SERVO_CENTER);
}

void Arm::vertPosition(int pos){
	moveServo(&m_Shoulder,pos,SHOULDER_DELAY);
	//	m_Shoulder.write(pos);
}

void Arm::rotate(int pos){
	moveServo(&m_Rotate,pos,ROTATE_DELAY);
		//m_Rotate.write(pos);
}

void Arm::bend(int pos){
	moveServo(&m_Elbow,pos,BEND_DELAY);
		//m_Elbow.write(pos);
}

void Arm::move(
	int pos_shoulder,
	int pos_rotate,
	int pos_elbow
){
	vertPosition(pos_shoulder);
	rotate(pos_rotate);
	bend(pos_elbow);
}

// Mouth

Mouth::Mouth(int pin_left, int pin_right){
	m_RightJaw.attach(pin_right);
	m_LeftJaw.attach(pin_left);
	move(SERVO_CENTER,SERVO_CENTER);
}

void Mouth::move(int pos_left, int pos_right){
	moveServo(&m_RightJaw,pos_right,MOUTH_DELAY);
	moveServo(&m_LeftJaw,pos_left,MOUTH_DELAY);
	//m_RightJaw.write(left);
	//m_LeftJaw.write(right);
}

// Brow

Brow::Brow(int pin_left, int pin_right){
	m_RightBrow.attach(pin_right);
	m_LeftBrow.attach(pin_left);
//	moveServo(&m_RightBrow,SERVO_CENTER,BROW_DELAY);
//	moveServo(&m_LeftBrow,SERVO_CENTER,BROW_DELAY);
	move(SERVO_CENTER,SERVO_CENTER);
}

void Brow::move(int pos_left, int pos_right){
	moveServo(&m_RightBrow,pos_right,BROW_DELAY);
	moveServo(&m_LeftBrow,pos_left,BROW_DELAY);
//	m_RightBrow.write(pos_right);
//	m_LeftBrow.write(pos_left);
}

// Eyes

Eyes::Eyes(
	int pin_EyeServo_Hor,
	int pin_EyeServo_Ver,
	int pin_LeftEyeLED, 
	int pin_RightEyeLED
	):
	m_Pin_LeftEyeLED(pin_LeftEyeLED),
	m_Pin_RightEyeLED(pin_RightEyeLED)
{	
	m_EyeServo_Horizontal.attach(pin_EyeServo_Hor);
	m_EyeServo_Vertical.attach(pin_EyeServo_Ver);
	pinMode(m_Pin_LeftEyeLED, OUTPUT);
	pinMode(m_Pin_RightEyeLED, OUTPUT);
	bothEyes(ON);
}

void Eyes::bothEyes(int state){
	if (state==ON) state = HIGH;
	else if (state==OFF) state = LOW;
	else return;
  digitalWrite(m_Pin_LeftEyeLED,state);
  digitalWrite(m_Pin_RightEyeLED,state);
}

void Eyes::leftEye(int state){
	if (state==ON) state = HIGH;
	else if (state==OFF) state = LOW;
	else return;
  digitalWrite(m_Pin_LeftEyeLED,state);
}

void Eyes::rightEye(int state){
	if (state==ON) state = HIGH;
	else if (state=OFF) state = LOW;
	else return;
  digitalWrite(m_Pin_RightEyeLED,state);
}

void Eyes::move(int pos_horizontal, int pos_vertical){
	moveServo(
		&m_EyeServo_Horizontal,
		pos_horizontal,EYE_DELAY
	);
	moveServo(
		&m_EyeServo_Vertical,
		pos_vertical,EYE_DELAY
	);
}

// Head

Head::Head(int pin_turn, int pin_tilt){
	m_Turn.attach(pin_turn);
	m_Tilt.attach(pin_tilt);
	turn(SERVO_CENTER);
	tilt(SERVO_CENTER);
}

void Head::turn(int pos){
	moveServo(&m_Turn,pos,TURN_DELAY);
	//m_Turn.write(pos);
}

void Head::tilt(int pos){
	moveServo(&m_Tilt,pos,TILT_DELAY);
	//	m_Tilt.write(pos);
}

// Einstein 

Einstein::Einstein(){
//*
	m_pRightArm = new Arm(
		PIN_ARM_RIGHT_SHOULDER,
		PIN_ARM_RIGHT_ROTATE,
		PIN_ARM_RIGHT_ELBOW
	);
//*/
//	m_pMouth = new Mouth(PIN_JAW_LEFT,PIN_JAW_RIGHT);
//	m_pBrow = new Brow(PIN_BROW_LEFT,PIN_BROW_RIGHT);
//	m_pHead = new Head(PIN_HEAD_TURN,PIN_HEAD_TILT);
/*
	m_pEyes = new Eyes(
		PIN_EYES_HORIZONTAL,
		PIN_EYES_VERTICAL,
		PIN_EYE_LEFT,
		PIN_EYE_RIGHT
	);
//*/
}

void Einstein::moveRightArm(
	int pos_shoulder,
	int pos_rotate,
	int pos_elbow
){
	m_pRightArm->vertPosition(pos_shoulder);
	m_pRightArm->rotate(pos_rotate);
	m_pRightArm->bend(pos_elbow);
}

void Einstein::smile(){
	m_pMouth->move(0,180);
}

void Einstein::frown(){
	m_pMouth->move(180,0);
}

void Einstein::speak(int duration){
	// TODO: implement me
}

void Einstein::raiseBrow(){
	m_pBrow->move(180,0);
}

void Einstein::lowerBrow(){
	m_pBrow->move(135,45);
}

void Einstein::neutralBrow(){
	m_pBrow->move(SERVO_CENTER,SERVO_CENTER);
}

void Einstein::turnHead(int pos){
	m_pHead->turn(pos);
}

void Einstein::tiltHead(int pos){
	m_pHead->tilt(pos);
}

void Einstein::blink(int duration){
	m_pEyes->bothEyes(OFF);
	delay(duration);
	m_pEyes->bothEyes(ON);
}


