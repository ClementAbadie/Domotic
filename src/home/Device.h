/*
 * Device.h
 *
 *  Created on: 4 oct. 2016
 *      Author: Clément
 */

#ifndef HOME_DEVICE_H_
#define HOME_DEVICE_H_

#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Device {
public:
	Device(string label, int ID, int type, int MESt, int COMt, int room,	int mode,	int state,	int PIN, int VAL, int RNG);
	virtual ~Device();

	int setID();


	int getID();
	string getLabel();
};



#endif /* HOME_DEVICE_H_ */
