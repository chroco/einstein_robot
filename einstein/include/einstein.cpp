#include "einstein.h"

Einstein::Einstein(){
	m_pHead = new Head(INIT_TURN,INIT_TILT);
}

Head::Head(int turn, int tilt){
	m_NeckTurn.attach(turn);
	m_NeckTilt.attach(tilt);
}

Head::turn(int pos){
	m_NeckTurn.write(pos);
}

Head::tilt(int pos){
	m_NeckTilt.wriet(pos);
}

