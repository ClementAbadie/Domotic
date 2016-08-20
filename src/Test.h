/*
 * Test.h
 *
 *  Created on: 28 juil. 2016
 *      Author: Clément
 */

#ifndef TEST_H_
#define TEST_H_

#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>
#include "AI/DB.h"
#include "AI/AI.h"
#include "user/pushbullet.hpp"
#include "user/ServerSocket.h"

using namespace std;



void *producer(void *arg);
void *consumer(void *arg);
int multithreadTest();


class Test {
public:
	Test();
	virtual ~Test();


};


#endif /* TEST_H_ */
