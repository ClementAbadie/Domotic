#include "i2c.h"




// Returns a file id for the port/bus
int i2c_Open(char *I2CBusName){
  int fd;
  //Open port for reading and writing
  if ((fd = open(I2CBusName, O_RDWR)) < 0){
    printf ("\n");
    printf ("%s : Failed to open the i2c bus, error : %d\n",__func__,errno);
    printf ("Check to see if you have a bus: %s\n",I2CBusName);
    printf ("This is not a slave device problem, I can not find the bus/port with which to talk to the device\n");
    printf ("\n");
    // Only one of the following lines should be used
    // the second line allows you to retry another bus, PS disable all the printf 's
    exit(1);      //Use this line if the function must terminate on failure
    //return fd;  //Use this line if it must return to the caller for processing
    }
    else{
     return fd;
    }
}
