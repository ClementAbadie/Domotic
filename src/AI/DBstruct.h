#ifndef AI_DBstruct_H_
#define AI_DBstruct_H_

#include <list>
#include <string>
#include <vector>

using namespace std;

struct DBs {
	float realTime[MAX_DATA_TYPE][MAX_ROOM];
	float config[MAX_CONFIG_VALUE][MAX_ROOM];
	int mode[MAX_DATA_TYPE][MAX_ROOM];
	string *unit[MAX_DATA_TYPE];
};

#endif
