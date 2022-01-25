#ifndef FILTER_H
#define FILTER_H

#include "wind_rose.h"

speed** filter(speed* array[], int size, bool(*check)(speed* element), int& result_size);



bool check_by_direction(speed* element);




bool check_by_speed(speed* element);


#endif
