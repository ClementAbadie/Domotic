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

	static int setDB(volatile DBs  *myDBs);

	static string execute(string order);
	static string atConnect();

	static string atConnect1();
	static string atConnect2();
	static string atConnect3();

private:
	static DB myDB;
};


#endif /* USER_H_ */
