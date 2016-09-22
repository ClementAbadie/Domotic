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
#include <stdio.h>
#include <stdlib.h>
#include <SQLAPI.h>
#include "../conf/conf.h"
#include "../tools/Tools.h"



#include <MYSQL/mysql.h>

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
 * DTTn : DaTa Type Number  (NUMERIC)
 * UNT : UNiT (TEXT)
 * LBL : LaBeL (TEXT)
 * MIN : MINimal value that the data can be  (NUMERIC)
 * MAX : MAXimal value that the data can be  (NUMERIC)
 *
 * Rooms table :
 * ROOn : ROOm Number (AutoNumber)
 * LBL : LaBeL (TEXT)
 *
 * Sensors table :
 * SNSn : SeNSor Number (AutoNumber)
 * DTTn : type of value that the sensor measure (NUMERIC)
 * ROOn : location of the sensor (NUMERIC)
 * LBL : LaBeL (text)
 *
 * Actuators table :
 * ACTn : ACTuator Number (AutoNumber)
 * DTTn : type of value that the actuator can change (NUMERIC)
 * ROOn : location of the sensor (NUMERIC)
 * LBL : LaBeL (text)
 * ACT : ACTion
 * MOD : MODe (0 man 1 auto)
 * STA : STAte (0 off 1 on)
 *
 * Measures table :
 * DTTn : DaTa Type Number  (NUMERIC)
 * ROOn : ROOm Number (NUMERIC)
 * VAL : VALue (NUMERIC)
 * DAT : Date And Time (DATETIME)
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

	friend class Test;
public:
	DB();
	DB(volatile DBs  *myDBs);

	virtual ~DB();

	int set(int DataType, float value, int room);
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
    //Déclaration du pointeur de structure de type MYSQL
    MYSQL mysql;

    MYSQL_RES *result = NULL;
    MYSQL_ROW row = 0;

	int Connect();
	int Close();
	int TableToConsole(string table);
	int TableClear(string table);
	int setDatasTable();
};

#endif /* AI_DB_H_ */
