/*
 * Actuator.h
 *
 *  Created on: 4 oct. 2016
 *      Author: Clément
 */

#ifndef ACTUATORS_ACTUATOR_H_
#define ACTUATORS_ACTUATOR_H_

#include <string>
#include <list>
#include <iomanip>
#include <math.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>


using namespace std;

class Actuator {
public:
	Actuator();
	virtual ~Actuator();

	int getMode();
	int getState();
	int getRoom();
	int getPIN();
	int getID();
	int getMEST();
	int getAsserVAL();
	int getAsserRNG();
	string getUnit();
	string getLabel();

	int setMode(int mode);
	int setState(int state);
	int setRoom(int room);
	int setPIN(int PIN);
	int setMEST(int MEST);
	int setAsserVAL(int value);
	int setAsserRNG(int range);
	int setUnit(string unit);
	int setLabel(string label);

};



#endif /* ACTUATORS_ACTUATOR_H_ */
