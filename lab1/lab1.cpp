#include <iostream>

using namespace std;

#include "wind_rose.h"
#include "file_reader.h"
#include "constants.h"

int main()
{
	setlocale(LC_ALL, "Russian");
    cout << "Laboratory work #1. GIT\n";
    cout << "Variant #6. Wind Rose\n";
    cout << "Author: Lepskaya Darya\n";
	speed* speed_wind [MAX_FILE_ROWS_COUNT];
	int size;
	try
	{
		read("data.txt", speed_wind, size);
		for (int i = 0; i < size; i++)
		{
			cout << speed_wind[i]->speed_wind << " ";
			cout << speed_wind[i]->wind.direction_wind<< " ";
			cout << '\n';
		}
		for (int i = 0; i < size; i++)
		{
			delete speed_wind[i];
		}
	}
	catch (const char* error)
	{
		cout << error << '\n';
	}
	return 0;
}