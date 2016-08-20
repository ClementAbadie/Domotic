/*
 * AI.cpp
 *
 *  Created on: 24 juil. 2016
 *      Author: Clément
 */

#include "AI.h"


AI::AI(volatile DBs  *myDBs) {
	// TODO Auto-generated constructor stub

	this->myDB = DB(myDBs);



}

AI::~AI() {
	// TODO Auto-generated destructor stub
}


int AI::start(pthread_mutex_t *myMutex) {

	pthread_mutex_lock(myMutex);
	this->init();
	pthread_mutex_unlock(myMutex);



	this->CheckTimer(myMutex);

	return 0;
}


int AI::init() {


	this->myDB.setUnit(val_humidity,"%");
	this->myDB.setUnit(val_pressure,"mBar");
	this->myDB.setUnit(val_temperature,"C");

	this->myDB.setConf(conf_humidityHigh,60.0,room_salon);
	this->myDB.setConf(conf_humidityLow,45.0,room_salon);

	this->myDB.setMode(val_humidity,mode_auto,room_salon);
	this->myDB.setMode(val_pressure,mode_auto,room_salon);
	this->myDB.setMode(val_temperature,mode_auto,room_salon);

	htu_toConsole();
	bmp_toConsole();


	return 0;
}



int AI::CheckTimer(pthread_mutex_t *myMutex) {

	while(1)
	{
            pthread_mutex_lock(myMutex);
			this->refreshAllValues();
			this->humidityCheck(room_salon);
            pthread_mutex_unlock(myMutex);

            sleep(conf_refreshWaitingTime);
	}

return 0;

}

int AI::refreshAllValues(){

	this->refreshAllRealTimeValues();

	return 0;
}

int AI::refreshAllRealTimeValues(){

	this->myDB.set(val_humidity,htu_getHumidity(),room_salon);
	this->myDB.set(val_temperature,(htu_getTemperature()+bmp_getTemperature())/2+calibration_linear_temperature,room_salon);
	this->myDB.set(val_pressure,bmp_getPressure(),room_salon);

	return 0;
}

int AI::humidityCheck(int room) {

	float hum = this->myDB.get(val_humidity,room);

	if(myDB.getMode(val_humidity,room)==mode_auto)
	{

		if(DEBUG){cout << "Hum  AUTO : " << hum; }
		if(this->myDB.getConf(conf_humidityHigh,room)<this->myDB.get(val_humidity,room))
		{
			ChaconPlug(plug_dehumidifier_gr,plug_dehumidifier_nb,1);
			if(DEBUG){cout << " : deshum ON !" << endl;}
		}
		else if(this->myDB.getConf(conf_humidityLow,room)>this->myDB.get(val_humidity,room))
		{
			ChaconPlug(plug_dehumidifier_gr,plug_dehumidifier_nb,0);
			if(DEBUG){cout << " : deshum OFF !" << endl;}
		}
		else
		{
			if(DEBUG){cout << " : Ok" << endl;}
		}


	}
	else
	{
		if(DEBUG){cout << "Hum  MAN : " << hum << endl; }
	}



return 0;

}
