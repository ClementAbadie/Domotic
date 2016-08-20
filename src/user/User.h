/*
 * User.h
 *
 *  Created on: 28 juil. 2016
 *      Author: Clément
 */

#ifndef USER_H_
#define USER_H_

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <clocale>
#include <cstdio>
#include "../AI/DB.h"
#include "../AI/DBstruct.h"
#include "../actuators.h"

using namespace std;

class User {
public:
	User(volatile DBs  *myDBs);
	User(){};
	virtual ~User();

	string execute(string order);
	string atConnect();

	string atConnect1();
	string atConnect2();
	string atConnect3();

private:
	DB myDB;
};


#endif /* USER_H_ */
