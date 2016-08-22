/*
 * ServerTCP.h
 *
 *  Created on: 21 août 2016
 *      Author: Clément
 */

#ifndef SERVERTCP_H_
#define SERVERTCP_H_
#define DEBUG 1

#include "ServerSocket.h"
#include "SocketException.h"
#include <iostream>
#include <string>

#include <cstdlib>
#include <unistd.h>

#include "../Domotic.h"
#include "User.h"

using namespace std;

int myTCPServer (int port, pthread_mutex_t *myMutex, volatile DBs  *myDBs);


#endif /* USER_SERVERTCP_H_ */
