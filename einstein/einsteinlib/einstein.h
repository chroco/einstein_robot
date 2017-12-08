#ifndef EINSTEIN_H	
#define EINSTEIN_H	

#include "common.h"
#include "head.h"
#include "arm.h"
#include "mouth.h"
#include "brow.h"
#include "joyride.h"
#include "eyes.h"

class Einstein{
	public:
		Einstein();
		void blink(int duration);
		void moveEyes(int pos_h,int pos_v);
		void raiseBrow();
		void lowerBrow();
		void smile();
		void frown();
		void speak(int duration);
		void neutralBrow();
		void turnHead(int pos);
		void tiltHead(int pos);
		void forward();
		void reverse();
		void stop();
		void moveRightArm(
			int pos_shoulder,
			int pos_rotate,
			int pos_elbow
		);	
		void rotateRightArm(int pos);
		void bendRightArm(int pos);
		void pitchRightArm(int pos);
	private:
		Arm *m_pRightArm;
		Mouth *m_pMouth;
		Brow *m_pBrow;
		Eyes *m_pEyes;
		Head *m_pHead;
		Joyride *m_pJoyride;

};

#endif
