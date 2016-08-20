#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <linux/i2c-dev.h>
#include <linux/i2c.h>
#include <sys/ioctl.h>
#include <math.h>

#define I2CBus             "/dev/i2c-1"      //New Pi's
//#define I2CBus             "/dev/i2c-0"    //Old, but not stale Pi's

int i2c_Open(char *I2CBusName);
