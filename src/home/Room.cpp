/*
 * Room.cpp
 *
 *  Created on: 4 oct. 2016
 *      Author: Clément
 */

#include "Room.h"



Room::Room(string label) {

	this->label = label;

}

Room::~Room() {
	// TODO Auto-generated destructor stub
}

int Room::addDevice(Device & device) {

	this->devices.push_back(device);
	devicesNb++;
	return 0;

}

Device *Room::getDeviceByID(int deviceID) {
/*
	for (list<Device*>::iterator p = devices.begin(); p!= devices.end(); p++) {

		if ((*p)->getID() == deviceID)
		{

			if(DEBUG){

			}
			return **p;
		}
	}

	cerr << "getDeviceByID : Devices non found (return nullptr)" << endl;
	*/
	return nullptr;

}

int Room::setID(int ID) {
}

int Room::delDeviceByID(int deviceID) {

/*
		for (list<Device*>::iterator p = devices.begin(); p!= devices.end(); p++) {

			if ((*p)->getID() == deviceID)
			{
	            pt = **p;
				if(DEBUG){
	                cout << "fonction get point return point id: " << deviceID << " value : " << pt.toString() << endl;
				}
				return true;
			}
		}

		cerr << "getPoint : Point non trouve (return NULL)" << endl;
		*/
		return false;

}

string Room::devicesToString() {
}



