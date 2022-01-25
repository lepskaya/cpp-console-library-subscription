#ifndef WIND_ROSE_H
#define WIND_ROSE_H

#include "constants.h"

struct date
{
	int day;
	int month;
};

struct direction
{
	char direction_wind[MAX_STRING_SIZE];
};

struct speed
{
	double speed_wind;
	direction wind;
	date DateWind;
};

#endif
