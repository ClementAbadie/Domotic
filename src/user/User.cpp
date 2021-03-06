/*
 * User.cpp
 *
 *  Created on: 28 juil. 2016
 *      Author: Cl�ment
 */

#include "User.h"
#include "../admin.h"

DB User::myDB = DB();

User::User(volatile DBs  *myDBs) {
	//Auto-generated constructor stub
	User::myDB = DB(myDBs);

}

User::~User() {
	// TODO Auto-generated destructor stub
}

int User::setDB(volatile DBs  *myDBs){

	User::myDB = DB(myDBs);
	return 0;
}


string User::execute(string order) {

	//TODO
	int nb = 0;
	int state = 0;
	int manage = 0;

	if(sscanf(order.c_str(),"P: %i %i",&nb,&state))
	{

		int chaconToVal[5][MAX_ROOM] = {0};

		chaconToVal[1][room_salon] = val_humidity;


		if(state==0||state==1){
			ChaconPlug(1,nb,state);
		}
		User::myDB.setMode(chaconToVal[nb][room_salon],state,room_salon);
	}
	else if(sscanf(order.c_str(),"M: %i",&manage))
	{

	      switch ( manage )
	      {
	         case 0:
	            break;
	         case 1:
	            break;
	         case 2:
	            break;
	         case 9:
	        	 domotic_restart();
	            break;
	         //default:
	      }
	}

	return order;

}


string User::atConnect() {

	ostringstream ss;

	ss << User::myDB.get(val_temperature,room_salon)  <<  " " <<  User::myDB.getUnit(val_temperature) << endl;
	ss << User::myDB.get(val_humidity,room_salon)  <<  " " <<  User::myDB.getUnit(val_humidity) << endl;
	ss << User::myDB.get(val_pressure,room_salon)  <<  " " <<  User::myDB.getUnit(val_pressure) << endl;
	ss << endl;
	return ss.str();
}

string User::atConnect1() {

	ostringstream ss;

	if(OLD){
	ss << "Temperature : " << User::myDB.get(val_temperature,room_salon)  <<  " C" << endl;
	}
	else
	{
		ss << "Temp�rature : " << User::myDB.get(val_temperature,room_salon)  <<  " " <<  User::myDB.getUnit(val_temperature) << endl;
	}
	return ss.str();

}
string User::atConnect2() {

	ostringstream ss;
	if(OLD){
	ss << "Pression : " << User::myDB.get(val_pressure,room_salon)  <<  " mBar" << endl;
	}
	else
	ss << "Pression : " << User::myDB.get(val_pressure,room_salon)  << " " <<  User::myDB.getUnit(val_pressure) << endl;

	return ss.str();

}

string User::atConnect3() {

	ostringstream ss;
	if(OLD){
	ss << "Humidite : " << User::myDB.get(val_humidity,room_salon)  <<  " %" << endl;
	}
	else
	ss << "Humidit� : " << User::myDB.get(val_humidity,room_salon)  << " " <<  User::myDB.getUnit(val_humidity) << endl;

	return ss.str();

}
