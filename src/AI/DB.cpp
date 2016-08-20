/*
 * DB.cpp
 *
 *  Created on: 24 juil. 2016
 *      Author: Clément
 */


#include "DB.h"

DB::DB(volatile DBs  *myDBs) {
	// TODO Auto-generated constructor stub


	this->myDBs = myDBs;

}

DB::DB() {
	// TODO Auto-generated destructor stub
}

DB::~DB() {
	// TODO Auto-generated destructor stub
}


int DB::set(int DataType, float value, int room){

	//TODO
	//set time

	this->set(DataType, value, room, 0);

	return 0;
}

int DB::setConf(int DataType, float value, int room){

	myDBs->config[DataType][room] = floor(value * 10 + 0.1) / 10;

	return 0;
}

int DB::setMode(int DataType, int mode, int room){

	myDBs->mode[DataType][room] = mode;

	return 0;
}

int DB::set(int DataType, float value, int room, int time){

	//TODO
	//set time
	myDBs->realTime[DataType][room] = floor(value * 10 + 0.1) / 10;
	return 0;
}

int DB::setUnit(int DataType, string unit){
	//TODO

	myDBs->unit[DataType] = &unit;
	return 0;
}

float DB::get(int DataType, int room){

	return myDBs->realTime[DataType][room];
}

float DB::getConf(int DataType, int room){

	return myDBs->config[DataType][room];
}

int DB::getMode(int DataType, int room){

	return myDBs->mode[DataType][room];
}

string DB::getUnit(int DataType){
	//TODO

	return 	*myDBs->unit[DataType];
}
