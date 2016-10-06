/*
 * conf.h
 *
 *  Created on: 22 sept. 2016
 *      Author: Clément
 */

#ifndef CONF_H_
#define CONF_H_


#define DEBUG 1
#define TEST 0
#define OLD 1


#if DEBUG == 0
	#define TCP_PORT 56250
#else
	#define TCP_PORT 56251
#endif

//Paths
#define CONF_PATH "/home/mopidy/prog/remote/domotic/conf/"
#define MANAGE_SCRIPT_PATH "/home/mopidy/prog/bash/domotic.sh"








#endif /* CONF_CONF_H_ */





