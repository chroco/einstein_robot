
// Einstein Head and Right Arm Arduino Code ECE478 - Fall16
// Naser Alshami and Srijana Sapkota
// Using arduino Uno R3 with Sensor Shield
// This is a build up and several enhancements on the previous group Arduino source code.


#include <Servo.h>  // servo library

// Servo variables using wire labeling
Servo E7, E2;   // E7 = Eyes Up/Down, E2 = Eyes Left/Right
Servo F4, F5, F6, F11, F12; // Fingers F4 = thumb
Servo N9, N10;  // N10 = Neck Side Tilt, N9 = Rotate Head ("No" motion)
Servo S0, S1; // S0 = Shoulder Up/Down, S1 = Shoulder rotation
Servo J8, J3; // J8 = Elbow Joint, J3 = Wrist Joint
Servo U13;

int pos=0;

void setup(){
//  assigning variable to i/o pins
  S0.attach(0); // move shoulder up/down
  S1.attach(1); // rotate shoulder
  E2.attach(2); // moves eyes left/right
  J3.attach(3); // wrist joint
  F4.attach(4); // Thumb finger ,finger 1
  F5.attach(5); // Finger 2
  F6.attach(6); // Finger 3
  E7.attach(7); // moves eyes up/down
  J8.attach(8); // elbow joint
  N9.attach(9); // rotate neck left/right "No"
  N10.attach(10); // tilt neck side to side
  F11.attach(11); // Finger 4
  F12.attach(12); // Finger 5
  
  N9.write(100);
  N10.write(20);

  pinMode(A2, OUTPUT); // left eye led
  pinMode(A3, OUTPUT); // right eye led
  digitalWrite(A2, HIGH); // Turn left eye LED on
  digitalWrite(A3, HIGH); // Turn right eye LED on

//initial_state_arm();
//initial_state_hand();
}

void loop(){

  test();

//      Arm movements functions

//elbow();
//wrist();
//wave();
//shoulderUp();
//shoulderRotate();

//counting();
//nofingers();
//all_wave();
//dance();
//myturn();

//      Head movements functions

//  eyesON();
//  eyesOFF();
//  eyesBlink();
//  eyeWink();
//  browRight();
//  shiftyEyes();
//  eyesLeft();
//  UpDownEyes();
//  mouthOpenCloseSlow();
//  mouthOpenCloseFast();
//  motionNo();
//  NeckTilt();

}

void test(){

  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    J3.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    J3.write(pos);                    // tell servo to go to position in variable 'pos'
    delay(15);                        // waits 15ms for the servo to reach the position
  }
}

void myturn() {
    S1.write(120);
//  J8.write(30);

   for (pos = 0; pos <= 180; pos += 1) {   // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    S0.write(pos);                         // tell servo to go to position in variable 'pos'
    J8.write(pos/2);
    delay(15);                             // waits 15ms for the servo to reach the position
  }
   for (pos = 0; pos <= 180; pos += 1) {   // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    S1.write(pos);                         // tell servo to go to position in variable 'pos'
    delay(15);                             // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) {    // goes from 180 degrees to 0 degrees
    S1.write(pos);                         // tell servo to go to position in variable 'pos'
    delay(15);                             // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) {    // goes from 180 degrees to 0 degrees
    S0.write(pos);                         // tell servo to go to position in variable 'pos'
    J8.write(pos/2);
    delay(15);                             // waits 15ms for the servo to reach the position
  }
  }

void sweep_eyes() {
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    E2.write(pos);                    // tell servo to go to position in variable 'pos'
    E7.write(pos);                    // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    E2.write(pos);                    // tell servo to go to position in variable 'pos'
    E7.write(pos);                    // tell servo to go to position in variable 'pos'

    delay(15);                        // waits 15ms for the servo to reach the position
  }
}

void initial_state_arm() {
  S0.write(160);  // Shoulder down
  S1.write(150);
  J8.write(60);  
}

void initial_state_hand() {
  J3.write(100);
  F4.write(180);
  F5.write(180);
  F6.write(180);
  F11.write(180);
  F12.write(180);
}

void all_wave() {
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    J3.write(pos);              // tell servo to go to position in variable 'pos'
    S1.write(pos);
    E2.write(pos);              // tell servo to go to position in variable 'pos'
    E7.write(pos);                    // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    J3.write(pos);              // tell servo to go to position in variable 'pos'
    S1.write(pos);
    E2.write(pos);              // tell servo to go to position in variable 'pos'
    E7.write(pos);                    // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

void elbow() { 
  J8.write(30); // Tight
  delay(1000);
  J8.write(60); // Middle
  delay(1000);
  J8.write(90); // Straight
  delay(1000);
}

void wave() {
  J3.write(10);
  delay(500);
  J3.write(160);
  delay(500);  
}

void nofingers() {
  F4.write(0);
  F5.write(180);
  F6.write(0);
  F11.write(0);
  F12.write(0);
  wave();
}

void wrist() {
  J3.write(10); // Wrist rightwards
  delay(1000);
  J3.write(40);
  delay(1000);
  J3.write(70);
  delay(1000);
  J3.write(100);
  delay(1000);
  J3.write(130);
  delay(1000);
  J3.write(160);  // Wrist leftwards
  delay(1000);

}

void shoulderUp(){
  S0.write(120);
  J8.write(30);

   for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    S0.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    S0.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
//  S0.write(30);
//  delay(5000);
//  S0.write(60);
//  delay(5000);
//  S0.write(80);   // Shoulder straight
//  delay(3000);
//  S0.write(120);
//  delay(5000);
//  S0.write(150);
//  delay(5000);
//  S0.write(160);  // Shoulder down
//  delay(4000);
//  S0.write(100);
//  delay(4000);
//  S0.write(40);    // Shoulder up
//  delay(4000);

}
void shoulderRotate() {
  S0.write(160);  // Shoulder down
  delay(100);
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    S1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    S1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
//  S1.write(175);    // Near body
//  delay(5000);
//  S1.write(150);
//  delay(5000);
//  S1.write(120);
//  delay(5000);
//  S1.write(90);
//  delay(5000);
//  S1.write(60);
//  delay(5000);
//  S1.write(30);
//  delay(5000);
//  S1.write(50);    // Away from body
//  delay(5000);
}

void counting(){
  for (int x = 0; x < 3; x++)
  {
    F4.write(180);
    delay(1000);
    F5.write(180);
    delay(1000);
    F6.write(180);
    delay(1000);
    F11.write(180);
    delay(1000);
    F12.write(180);
    delay(1000);
    F4.write(0);
    F5.write(0);
    F6.write(0);
    F11.write(0);
    F12.write(0);
    delay(1000);
  }
}

void dance(){
  S0.write(100);   // Shoulder straight
  J8.write(10);
  F4.write(180);
  J3.write(180);
  F5.write(180);
  F6.write(0);
  F11.write(0);
  F12.write(180);
  for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    S1.write(pos*2);              // tell servo to go to position in variable 'pos'
    J8.write(pos);
    N10.write(pos);
    J3.write(pos);
    E2.write(pos*2);              // tell servo to go to position in variable 'pos'
    E7.write(pos*2);                    // tell servo to go to position in variable 'pos'
    F5.write(pos*2);
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 90; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    S1.write(pos*2);              // tell servo to go to position in variable 'pos'
    J8.write(pos);
    N10.write(pos);
    J3.write(pos);
    E2.write(pos*2);              // tell servo to go to position in variable 'pos'
    E7.write(pos*2);                    // tell servo to go to position in variable 'pos'
    F5.write(pos*2);
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}
/*
void motionNo(){
  neckNeutral();
  delay(500);
  neckTurnRight();
  delay(500);
  neckTurnLeft();
  delay(500);
  neckTurnRight();
  delay(500);
  neckNeutral();
  delay(500);
}
void NeckTilt(){
neckTiltLeft();
 delay(500);
// neckNeutral();
 // delay(500);
 neckTiltRight();
  delay(500);
  neckTiltLeft();
  delay(500);
  neckTiltRight();
  //delay(500);
  neckNeutral();
  delay(1500);
}
*/
void mouthOpenCloseFast(){
   U13.write(100);
  delay(200);
  U13.write(150);
  delay(200);
}
void mouthOpenCloseSlow(){
   U13.write(100);
  delay(500);
  U13.write(150);
  delay(500);
}
void mouthOpen(){
   U13.write(100);
  delay(200);

}
void mouthClose(){
  U13.write(150);
  delay(200);
}
/*
void shiftyEyes(){
//  eyesNeutral();
  //delay(500);
  eyesRight();
  delay(500);
//  eyesNeutral();
//  delay(500);
  eyesLeft();
  delay(500);
}
void UpDownEyes(){
  eyesUp();
  delay(500);
  eyesDown();
   delay(500);
}
void neckNeutral(){
  N9.write(90);
  delay(500);
  N10.write(60);
}
void neckTurnRight(){
  N9.write(145);
}
void neckTurnLeft(){
  N9.write(20);
}
void neckTiltLeft(){
N10.write(100);
}
void neckTiltRight(){
N10.write(30);
}
void eyesNeutral(){
E2.write(50);
delay(500);
 E7.write(165);
}
void eyesLeft(){
E2.write(110); // E2.write(80);
}
void eyesRight(){
E2.write(10);
}
void eyesUp(){
E7.write(180);
}
void eyesDown(){
E7.write(15);
}
void browRight(){
  B4.write(200);
  delay(1000);
  B4.write(10);
  delay(1000);
}
*/
void eyesBlink(){
  eyesON();
  delay(4000);
  eyesOFF();
  delay(500);
}
void eyesON(){
  digitalWrite(A2,HIGH ); // Turn on left eye LED
  digitalWrite(A3,HIGH);  // Turn on right eye LED
}
void eyesOFF(){
  digitalWrite(A2, LOW); // Turn on left eye LED
  digitalWrite(A3,LOW); // Turn on right eye LED
}
void eyeWink(){
  digitalWrite(A3,LOW); // Turn off right eye LED
  delay(1000);
  digitalWrite(A3,HIGH); // Turn on right eye LED
  delay(1000);
}
