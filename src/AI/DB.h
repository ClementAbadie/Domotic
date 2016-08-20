/*
 * DB.h
 *
 *  Created on: 24 juil. 2016
 *      Author: Clément
 */

#ifndef AI_DB_H_
#define AI_DB_H_

#include "DBvar.h"
#include "DBstruct.h"
#include <string>
#include <list>
#include <iomanip>
#include <math.h>
#include <iostream>

using namespace std;

class DB {
public:
	DB();
	DB(volatile DBs  *myDBs);

	virtual ~DB();

	int set(int DataType, float value, int room);
	int set(int DataType, float value, int room, int time);
	int setConf(int DataType, float value, int room);
	int setMode(int DataType, int mode, int room);
	int setUnit(int value, string unit);

	float get(int DataType, int room);
	float getConf(int DataType, int room);
	int getMode(int DataType, int room);
	string getUnit(int DataType);

private:
		//val  room
	//float realTime[MAX_DATA_TYPE][MAX_ROOM];
	//float config[MAX_CONFIG_VALUE][MAX_ROOM];
	DBs volatile *myDBs;
	//list<string> unit;


};

#endif /* AI_DB_H_ */
