/*
 * AI.h
 *
 *  Created on: 24 juil. 2016
 *      Author: Clément
 */

#ifndef AI_AI_H_
#define AI_AI_H_

#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>
#include "../Domotic.h"
#include <iostream>
#include "DB.h"
#include "../actuators.h"
#include "../sensors.h"

using namespace std;



class AI {
public:
	AI(volatile DBs  *myDBs);
	virtual ~AI();

	int start(pthread_mutex_t *myMutex);

private:
	int init();
	int refreshAllValues();
	int refreshAllRealTimeValues();
	int CheckTimer(pthread_mutex_t *myMutex);
	int humidityCheck(int room);


	DB myDB;
};

#endif /* AI_AI_H_ */
