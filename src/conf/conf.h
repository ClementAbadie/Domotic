/*
 * conf.h
 *
 *  Created on: 22 sept. 2016
 *      Author: Cl�ment
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

#define CONF_PATH "/home/mopidy/prog/remote/domotic/conf/"









#endif /* CONF_CONF_H_ */





