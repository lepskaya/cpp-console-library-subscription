#include "filter.h"
#include <cstring>
#include <iostream>

speed** filter(speed* array[], int size, bool(*check)(speed* element), int& result_size)
{
	speed** result = new speed*[size];
	result_size = 0;
	for (int i = 0; i < size; i++)
	{
		if (check(array[i]))
		{
			result[result_size++] = array[i];
		}
	}
	return result;
}

bool check_by_direction(speed* element)
{
	return strcmp(element->wind.direction_wind, "West") == 0 ||
		strcmp(element->wind.direction_wind, "NorthWest ") == 0 ||
		strcmp(element->wind.direction_wind, "North") == 0;
}

bool check_by_speed(speed* element)
{
	return element->speed_wind>5;
}
