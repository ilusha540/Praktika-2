#pragma once
#include <conio.h>
#include <iostream>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

class DataTime
{
private:
	int day,
		month,
		year;

	struct tm * timeinfo;   // data type for storing the number of seconds
	time_t rawtime;         // date and time structure


	char * weekday[7] = { "Sunday", "Monday",
		"Tuesday", "Wednesday",
		"Thursday", "Friday", "Saturday" };

	char * monthname[12] = { "January", "February",
		"March", "April","May",
		"June", "July", "August",
		"September","October","November",
		"December" };

public:
	DataTime();
	DataTime(int, int, int);
	DataTime(const DataTime &copy);
	void opredDay();
	void printMonth();
	void printWeekDay();
	void printToday();
	void printTomorrow();
	void printYesterday();
	void printFuture(int);
	void printPast(int);
	void calcDifference(DataTime, DataTime);
};