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



/* acronyms TCP / DB
 *
 *
 *
 * TMP : temperature
 * PSR : pressure
 * HUM : humidity
 *
 * ACT : actuator
 * SNS : sensor
 *
 *
 *
 * DB
 *
 * Datas descriptors table :
 * DTN : data type number  (NUMERIC)
 * UNT : unit (text)
 * LBL : label (text)
 * MIN : minimal value that the data can be  (NUMERIC)
 * MAX : maximal value that the data can be  (NUMERIC)
 *
 * Rooms table :
 * ROOn : room number (AutoNumber)
 * LBL : label (TEXT)
 *
 * Sensors table :
 * SNSn : sensor number (AutoNumber)
 * DTTn : type of value that the sensor measure (NUMERIC)
 * ROOn : location of the sensor (NUMERIC)
 * LBL : label (text)
 *
 * Actuators table :
 * ACTn : actuator number (AutoNumber)
 * DTTn : type of value that the actuator can change (NUMERIC)
 * ROOn : location of the sensor (NUMERIC)
 * LBL : label (text)
 * ACT : Action
 * MOD : Mode (0 man 1 auto)
 * STA : State (0 off 1 on)
 *
 * Measures table :
 * DTTn : data type number  (NUMERIC)
 * ROOn : room number (NUMERIC)
 * VAL : value (NUMERIC)
 * TIM : time (ttime)
 * DAT : date (tdate)
 *
 *
 * TCP
 *
 * DEV : Device type ( 1 sensor / 2 actuator / 3 asserv)
 * SET : 0 off, 1 on, 2 auto
 * VAL : value of target for auto mode
 * RNG : range for auto mode
 * x : value to communicate
 *
 * TCP trame :
 * DEV x
 *
 * DEV 1, DTTn x, ROOn x, VAL x.x
 *
 * DEV 2, ACTn x, SET x
 * DEV 2, ACTn x, VAL x
 * DEV 2, ACTn x, VAL x, RNG x
 */





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
