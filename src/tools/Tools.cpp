/*
 * Tools.cpp
 *
 *  Created on: 22 sept. 2016
 *      Author: Clément
 */

#include "Tools.h"


string timeToString ()
{
  time_t rawtime;
  struct tm * timeinfo;
  char buffer[80];

  time (&rawtime);
  timeinfo = localtime(&rawtime);

  strftime(buffer,80,"%H:%M:%S",timeinfo);
  string str(buffer);

  return str;
}

string dateToString ()
{
  time_t rawtime;
  struct tm * timeinfo;
  char buffer[80];

  time (&rawtime);
  timeinfo = localtime(&rawtime);

  strftime(buffer,80,"%Y-%m-%d",timeinfo);
  string str(buffer);

  return str;
}

string dateAndTimeToString()
{
  time_t rawtime;
  struct tm * timeinfo;
  char buffer[80];

  time (&rawtime);
  timeinfo = localtime(&rawtime);

  strftime(buffer,80,"%Y-%m-%d %H:%M:%S",timeinfo);
  string str(buffer);

  return str;
}
