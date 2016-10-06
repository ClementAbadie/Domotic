/*
 * Room.h
 *
 *  Created on: 4 oct. 2016
 *      Author: Clément
 */

#ifndef HOME_ROOM_H_
#define HOME_ROOM_H_
#include <list>
#include <iostream>
#include <cstddef>
#include <iostream>

#include "../conf/Conf.h"
#include "Device.h"

using namespace std;

class Room {
public:
	Room(string label);
	virtual ~Room();

	int addDevice(Device & device);
	Device *getDeviceByID(int deviceID);
	int setID(int ID);

	string devicesToString();

	int delDeviceByID(int id);

private:
	list<Device> devices;
	string label;
	int devicesNb;
};



#endif /* HOME_ROOM_H_ */
