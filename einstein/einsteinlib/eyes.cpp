#include "eyes.h"

// Eyes

/*--------------------------------------------------------------
Function: Eyes (Constructor)
Inputs:
	int pin_EyeServo_Hor: pin for the horizonal eye movement
	int pin_EyeServo_Ver: pin for the vertical eye movement
	int pin_LeftEyeLED: pin for the left eye LED
	int pin_RightEyeLED: pin for the right eye LED
Output:	None
Description: Constructor function for the Eyes class 
--------------------------------------------------------------*/
Function:
Eyes::Eyes(
	int pin_EyeServo_Hor,
	int pin_EyeServo_Ver,
	int pin_LeftEyeLED, 
	int pin_RightEyeLED
	):
	m_Pin_LeftEyeLED(pin_LeftEyeLED),
	m_Pin_RightEyeLED(pin_RightEyeLED)
{	
	//Create a new instance of ServoControl to control the movement of the eyes
	m_pEyesServo_Horizontal = new ServoControl(EYES_HORIZONTAL_MIN,EYES_HORIZONTAL_MAX);
	m_pEyesServo_Vertical = new ServoControl(EYES_VERTICAL_MIN,EYES_VERTICAL_MAX);
		
	//Attach the servos to their pins
	m_pEyesServo_Horizontal->attach(pin_EyeServo_Hor);
	m_pEyesServo_Vertical->attach(pin_EyeServo_Ver);
		
	//Set the pins for the LEDs to outputs and turn on both eyes
	pinMode(m_Pin_LeftEyeLED, OUTPUT);
	pinMode(m_Pin_RightEyeLED, OUTPUT);
	bothEyes(ON);
}

/*--------------------------------------------------------------
Function: bothEyes
Inputs:
	int state: state that both eyes LEDs are being set to
Output:	None (void)
Description: Turn the LEDs in both eyes on and off
--------------------------------------------------------------*/
void Eyes::bothEyes(int state){
	//Check to see if the LEDs are being turned on
	if (state==ON) state = HIGH;
	
	//Check to see if the LEDs are being turned off
	else if (state==OFF) state = LOW;
	
	//Invalid state
	else return;
	
  //Write the current state to both LEDs
  digitalWrite(m_Pin_LeftEyeLED,state);
  digitalWrite(m_Pin_RightEyeLED,state);
}

/*--------------------------------------------------------------
Function: leftEye
Inputs:
	int state: state that the left eyes LED is being set to
Output:	None (void)
Description: Turns the LED in the left eye on and off
--------------------------------------------------------------*/
void Eyes::leftEye(int state){
	//Check to see if the left eye LED is being turned on
	if (state==ON) state = HIGH;
	
	//Check to see if the left eye LED is being turned off
	else if (state==OFF) state = LOW;
	
	//Invalid state
	else return;
  
  //Write the current state to the left eye LED
  digitalWrite(m_Pin_LeftEyeLED,state);
}

/*--------------------------------------------------------------
Function: rightEye
Inputs:
	int state: state that the right eyes LED is being set to
Output:	None (void)
Description: Turns the LED in the right eye on and off
--------------------------------------------------------------*/
void Eyes::rightEye(int state){
	//Check to see if the right eye LED is being turned on
	if (state==ON) state = HIGH;
	
	//Check to see if the right eye LED is being turned off
	else if (state=OFF) state = LOW;
	
	//Invalid state
	else return;
	
  //Write the current state to the right eye LED
  digitalWrite(m_Pin_RightEyeLED,state);
}

/*--------------------------------------------------------------
Function: move
Inputs:
	int pos_horizontal: horizontal position to move the eyes to
	int pos_vertical: vertical position to move the eyes to
Output:	None (void)
Description: Move both eyes to a given horizontal and vertical
position
--------------------------------------------------------------*/
void Eyes::move(int pos_horizontal, int pos_vertical){
	//Move Einstein's eyes horizontally to a position at a defined speed
	m_pEyesServo_Horizontal->moveServo(pos_horizontal,EYE_DELAY);
	
	//Move Einstein's eyes vertically to a position at a defined speed
	m_pEyesServo_Vertical->moveServo(pos_vertical,EYE_DELAY);
}
