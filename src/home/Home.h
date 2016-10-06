/*
 * Home.h
 *
 *  Created on: 4 oct. 2016
 *      Author: Clément
 */

#ifndef HOME_HOME_H_
#define HOME_HOME_H_

#include <list>
#include "Room.h"

namespace std {

class Home {
public:
	Home();
	virtual ~Home();

	int addRoom(Room room);


	int delRoomByID(int id);


private:

	list<Room> rooms;
};

} /* namespace std */

#endif /* HOME_HOME_H_ */
