#include <iostream>
#include <iomanip>

using namespace std;

#include "wind_rose.h"
#include "file_reader.h"
#include "constants.h"
#include "filter.h"

void output(speed* subscription)
{

	//  
	cout << subscription->DateWind.day << " ";
	//    
	cout << subscription->DateWind.month << ". ";
	//    
	cout << subscription->wind.direction_wind << ".";

	cout << subscription->speed_wind << ".";
	cout << '\n';


}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Laboratory work #1. GIT\n";
	cout << "Variant #6. Wind Rose\n";
	cout << "Author: Lepskaya Darya\n";
	speed* subscriptions[MAX_FILE_ROWS_COUNT];
	int size;
	try
	{
		read("../data.txt", subscriptions, size);
		for (int i = 0; i < size; i++)
		{
			output(subscriptions[i]);
		}
		bool(*check_function)(speed*) = NULL; // check_function -    ,    bool,
														   //        book_subscription*
		cout << "1)Дни, в которые дул ветер в одном из направлений West, NorthWest или North."<<'\n';
		cout << "2)Дни, в которые дул ветер больше 5 м/с. "<<'\n';

		int item;
		cin >> item;
		switch (item)
		{
		case 1:
			check_function = check_by_direction; //       
			break;
		case 2:
			check_function = check_by_speed; //       
			break;

		default:
			throw "Неверное чісло";
		}
		if (check_function)
		{
			int new_size;
			speed** filtered = filter(subscriptions, size, check_function, new_size);
			for (int i = 0; i < new_size; i++)
			{
				output(filtered[i]);
			}
			delete[] filtered;
		}
		for (int i = 0; i < size; i++)
		{
			delete subscriptions[i];
		}
	}
	catch (const char* error)
	{
		cout << error << '\n';
	}
	return 0;
}
