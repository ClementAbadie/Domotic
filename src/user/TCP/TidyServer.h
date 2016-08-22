/*
 * TidyServer.h
 *
 *  Created on: 21 ao�t 2016
 *      Author: Cl�ment
 */

#ifndef TIDYSERVER_H_
#define TIDYSERVER_H_


#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <netinet/in.h>
#include <resolv.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#include "../../Domotic.h"
#include "../User.h"


	int TidyServer(int host_port);
	void* SocketHandler(void*);




#endif /* TIDYSERVER_H_ */
