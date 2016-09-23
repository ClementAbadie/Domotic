/*
 * Test.cpp
 *
 *  Created on: 28 juil. 2016
 *      Author: Cl�ment
 */

#include "Test.h"

//volatile int counter = 0;

//pthread_mutex_t myMutexTest;
//volatile DBs *myDBsTest;

//dataStruct DS;
	pthread_mutex_t* myMutexTest = ( pthread_mutex_t*) malloc(sizeof( pthread_mutex_t));
	volatile struct DBs* myDBsTest = (volatile struct DBs*) malloc(sizeof(volatile struct DBs));



void *AIfuncTest(void *id)
{
	//DB myDB = DB(*myDBsTest);
	//AI myAI = AI(myDB);
	//myAI.start(myMutexTest);

}

void *USERfuncTest(void *id)
{
	//DB myDB = DB(*myDBsTest);
	//ServerSocket myServer = ServerSocket();
	//myServer.start(56200,myMutexTest,myDB);
/*
	while(1)
	{
            pthread_mutex_lock(&myMutexTest);


            pthread_mutex_unlock(&myMutexTest);
            sleep(1);
	}
	*/
return 0;
}



int multithreadTest()
{

		int id1 = 1, id2 = 2;
        pthread_t aiThread, userThread;
        pthread_mutex_init(myMutexTest,0);
        pthread_create(&aiThread, 0, AIfuncTest, (void*)id1);
        pthread_create(&userThread, 0, USERfuncTest, (void*)id2);

        pthread_join(aiThread, 0);
        pthread_join(userThread, 0);

        pthread_mutex_destroy(myMutexTest);
        return 0;
}
    	/*
            int one = 1, two = 2, three = 3;
            pthread_t thread1, thread2, thread3;
            pthread_mutex_init(&myMutex,0);
            pthread_create(&thread1, 0, mutex_testing, (void*)one);
            pthread_create(&thread2, 0, mutex_testing, (void*)two);
            pthread_create(&thread3, 0, mutex_testing, (void*)three);
            pthread_join(thread1, 0);
            pthread_join(thread2, 0);
            pthread_join(thread3, 0);
            pthread_mutex_destroy(&myMutex);
            return 0;


}
*/

/*
void *mutex_testing(void *param)
{
        int i;
        for(i = 0; i < 5; i++) {
                pthread_mutex_lock(&myMutex);
                counter++;
                cout << "thread " << (int)param << " : counter = " << counter << endl;
                pthread_mutex_unlock(&myMutex);
                sleep(1);
        }
}
*/


Test::Test() {
	// TODO Auto-generated constructor stub


	Test::ToolsTest();
	Test::DBTest();


}

Test::~Test() {
	// TODO Auto-generated destructor stub
}

int Test::ToolsTest()
{

	cout << "Il est " << timeToString() << " et nous sommes le " << dateToString() << endl;



return 0;
}

int Test::DBTest()
{


	cout << "Test begin" << endl;

	//User::setDB(myDBsTest);
	DB myDB = DB();

	if(!myDB.Connect())
	{

		myDB.setMeasuresTypesTable();

		myDB.TableToConsole("measuresTypes");

		myDB.set(val_humidity,63.56,room_salon);
		myDB.set(val_humidity,70.52,room_sdb);
		myDB.set(val_pressure,1100.52,room_salon);

/*
		cout << "temp unit : "  << myDB.getUnit(val_temperature) << endl;
		cout << "pres unit  : " << myDB.getUnit(val_pressure) << endl;
		cout << "hum unit : " << myDB.getUnit(val_humidity) << endl;
*/
		cout << "Current salon temp : " << myDB.get(val_temperature,room_salon) << " " << myDB.getUnit(val_temperature) << endl;
		cout << "Current salon pres : " << myDB.get(val_pressure,room_salon) << " " << myDB.getUnit(val_pressure) << endl;
		cout << "Current salon hum : " << myDB.get(val_humidity,room_salon) << " " <<myDB.getUnit(val_humidity) << endl;


		myDB.TableToConsole("measures");

		//myDB.TableClear("measures");
		myDB.Close();
	}
	else
	{

		cout << "DB not connected" << endl;
	}



	return 0;
}



