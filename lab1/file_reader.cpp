#include "file_reader.h"
#include "constants.h"

#include <fstream>
#include <cstring>


void read(const char* file_name, speed* array[], int& size)
{
	std::ifstream file(file_name);
	if (file.is_open())
	{
		size = 0;
		char tmp_buffer[MAX_STRING_SIZE];
		while (!file.eof())
		{
			speed* item = new speed;
			file >> item->DateWind.day;
			file >> item->DateWind.month;
			file >> item->wind.direction_wind;
			file >> item->speed_wind;

			array[size++] = item;
		}
		file.close();
	}
	else
	{
		throw "  ";
	}
}
