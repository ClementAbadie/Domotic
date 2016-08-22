//============================================================================
// Name        : Domotic.cpp
// Author      : Clement ABADIE
// Version     :
// Copyright   : Free
// Description : Hello World in C++, Ansi-style
//============================================================================


#include"Domotic.h"




//dataStruct DS;
	pthread_mutex_t* myMutex = ( pthread_mutex_t*) malloc(sizeof( pthread_mutex_t));
	volatile struct DBs* myDBs = (volatile struct DBs*) malloc(sizeof(volatile struct DBs));




void *AIfunc(void *id)
{
	AI myAI = AI(myDBs);
	myAI.start(myMutex);

return 0;
}

void *USERfunc(void *id)
{
//	ServerSocket myServer = ServerSocket();
//	myServer.start(56250,myMutex,myDBs);

//	  Server *s;
//	  s = new Server(56250);

	  //Main loop
//	  s->AcceptAndDispatch();


//	myTCPServer(56250,myMutex,myDBs);
	TidyServer(56250);


return 0;
}



int multithread()
{

		int id1 = 1, id2 = 2;
        pthread_t aiThread, userThread;
        pthread_mutex_init(myMutex,0);
        pthread_create(&aiThread, 0, AIfunc, (void*)id1);
        pthread_create(&userThread, 0, USERfunc, (void*)id2);

        pthread_join(aiThread, 0);
        pthread_join(userThread, 0);

        pthread_mutex_destroy(myMutex);
        return 0;
}


int main() {


	User::setDB(myDBs);
	multithread();

	//DB myDB = DB();

	//AI myAI = AI(myDB);
	//myAI.start();

	//ServerSocket myServer = ServerSocket();
	//myServer.start(56200);

	//Pushbullet myPush = Pushbullet(Pushbullet_APIKEY);

	//myPush.push_note("Domotic"," Oh yeah ! =D");

	//Test myTest = Test();

	return 0;
}



