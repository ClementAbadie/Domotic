/*
 Usage: ./send <systemCode> <unitCode> <command>
 Command is 0 for OFF and 1 for ON
 */

#include "send.h"
#include "RCSwitch.h"
#include <stdlib.h>
#include <stdio.h>



int ChaconPlug(int group, int plug, int command) {
    
    /*
     output PIN is hardcoded for testing purposes
     see https://projects.drogon.net/raspberry-pi/wiringpi/pins/
     for pin mapping of the raspberry pi GPIO connector
     */
    int PIN = 0;
    
    if (wiringPiSetup() == -1) return 1;
	printf("sending Group[%i] Plug[%i] command[%i]\n", group, plug, command);
	RCSwitch mySwitch = RCSwitch();
	mySwitch.enableTransmit(PIN);
    
    switch(command) {
        case 1:
            mySwitch.switchOn(group, plug);
            break;
        case 0:
            mySwitch.switchOff(group, plug);
            break;
        default:
            printf("command[%i] is unsupported\n", command);
            return -1;
    }
	return 0;
}
