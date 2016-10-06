/*
 * Sensor.h
 *
 *  Created on: 4 oct. 2016
 *      Author: Clément
 */

#ifndef SENSORS_SENSOR_H_
#define SENSORS_SENSOR_H_

#include <string>
#include <list>
#include <iomanip>
#include <math.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

using namespace std;

class Sensor {
public:
	Sensor();
	virtual ~Sensor();


	int getRoomName();
	int getPIN();
	int getID();
	int getMEST();
	string getUnit();
	string getLabel();

	int setRoom(int room);
	int setPIN(int PIN);
	int setMEST(int MEST);
	int setUnit(string unit);
	int setLabel(string label);

};


#endif /* SENSORS_SENSOR_H_ */
