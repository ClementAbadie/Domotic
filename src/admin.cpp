/*
 * admin.cpp
 *
 *  Created on: 6 oct. 2016
 *      Author: Clément
 */

#include "conf/Conf.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int domotic_restart() {

char command[512];

sprintf(command, "sudo %s restart", MANAGE_SCRIPT_PATH);
if(DEBUG){cout << command << endl;}

system(command);

return 0;
}



