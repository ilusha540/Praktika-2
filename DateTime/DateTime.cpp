#pragma warning(disable : 4996)
#include "DateTime.h"
#include <conio.h>
#include <iostream>
#include <ctime>



DataTime::DataTime() {
	time(&rawtime);                     //date in seconds       
	timeinfo = localtime(&rawtime);     //convert the current date
	year = timeinfo->tm_year + 1900;
	month = timeinfo->tm_mon + 1;
	day = timeinfo->tm_mday;
}

DataTime::DataTime(int date_day, int date_month, int date_year) {
	day = date_day;
	month = date_month;
	year = date_year;

}

DataTime::DataTime(const DataTime &copy)
{
	day = copy.day;
	month = copy.month;
	year = copy.year;
	timeinfo = copy.timeinfo;
	rawtime = copy.rawtime;
	weekday[7] = copy.weekday[7];
	monthname[12] = copy.monthname[12];
}

void DataTime::opredDay() {
	// get current date and change it relatively introduced
	time(&rawtime);                              // current date in seconds
	timeinfo = localtime(&rawtime);              // convert the current date
	timeinfo->tm_year = year - 1900;             // correction of the year
	timeinfo->tm_mon = month - 1;                // correct month value
	timeinfo->tm_mday = day;                     // the entered day
	mktime(timeinfo);
}

void DataTime::printMonth() {
	opredDay();
	cout << "Month: " << monthname[timeinfo->tm_mon] << endl;
}

void DataTime::printWeekDay() {
	opredDay();
	cout << "Day of week: " << weekday[timeinfo->tm_wday] << endl;
}

void DataTime::printToday() {
	opredDay();
	cout << day << " "
		<< monthname[timeinfo->tm_mon] << " "
		<< year << " ("
		<< weekday[timeinfo->tm_wday] << ")" << endl;
}

void DataTime::printTomorrow() {
	char buffer[80];
	tm tomorr = {};
	tomorr.tm_year = year - 1900;
	tomorr.tm_mon = month - 1;
	tomorr.tm_mday = day;
	// modify
	tomorr.tm_mday += 1;
	mktime(&tomorr);
	strftime(buffer, 80, "%d %B %Y %A ", &tomorr);
	// show result
	cout << "Tomorrow: " << buffer << endl;
}

void DataTime::printYesterday() {
	char buffer[80];
	tm yester = {};
	yester.tm_year = year - 1900;
	yester.tm_mon = month - 1;
	yester.tm_mday = day;
	// modify
	yester.tm_mday -= 1;
	mktime(&yester);
	strftime(buffer, 80, "%d %B %Y %A ", &yester);
	// show result
	cout << "Yesterday: " << buffer << endl;
}

void DataTime::printFuture(int x) {
	int n = x;
	char buffer[80];
	tm futur = {};
	futur.tm_year = year - 1900;
	futur.tm_mon = month - 1;
	futur.tm_mday = day;
	// modify
	futur.tm_mday += n;
	mktime(&futur);
	strftime(buffer, 80, "%d %B %Y %A ", &futur);
	// show result
	cout << "After " << n << " days will be: " << buffer << endl;
}

void DataTime::printPast(int x) {
	int m = x;
	char buffer[80];
	tm past = {};
	past.tm_year = year - 1900;
	past.tm_mon = month - 1;
	past.tm_mday = day;
	// modify
	past.tm_mday -= m;
	mktime(&past);
	strftime(buffer, 80, "%d %B %Y %A ", &past);
	// show result
	cout << m << "  days ago was: " << buffer << endl;
}

void DataTime::calcDifference(DataTime d1, DataTime d2) {
	const int oneday = 0x15180;
	int day1, mon1, year1;
	int day2, mon2, year2;

	day1 = d1.day;
	mon1 = d1.month;
	year1 = d1.year;
	day2 = d2.day;
	mon2 = d2.month;
	year2 = d2.year;

	tm FirstDate = { 0, 0, 0, day1, mon1 - 1, year1 - 0x76C, 0, 0, 0 };
	tm SecondDate = { 0, 0, 0, day2, mon2 - 1, year2 - 0x76C, 0, 0, 0 };

	time_t t1 = mktime(&FirstDate);
	time_t t2 = mktime(&SecondDate);

	time_t diff = ((t1 > t2) ? t1 - t2 : t2 - t1) / oneday;

	cout << "\nBetween dates: " << diff << endl;
}
