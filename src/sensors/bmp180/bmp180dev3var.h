#ifndef SENSORS_BMP180_BMP180DEV3VAR_H_
#define SENSORS_BMP180_BMP180DEV3VAR_H_

const unsigned char BMPx8x_OverSampling = 3;

// Calibration values - These are stored in the BMP085/180
short int            bmp_ac1;
short int            bmp_ac2;
short int            bmp_ac3;
unsigned short int   bmp_ac4;
unsigned short int   bmp_ac5;
unsigned short int   bmp_ac6;
short int            bmp_b1;
short int            bmp_b2;
int                  bmp_b5;
short int            bmp_mb;
short int            bmp_mc;
short int            bmp_md;

#endif
