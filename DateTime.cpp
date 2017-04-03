#include <iostream>
#include <ctime>
#include "datetime.h"
using namespace std;



DateTime::DateTime()
{
	day = now->tm_mday;
	month = now->tm_mon + 1;
	year = now->tm_year + 1900;
};


DateTime::DateTime (int obj_day, int obj_month, int obj_year) {
	day = obj_day;
	month = obj_month;
	year = obj_year;
};

DateTime::DateTime(const DateTime &obj) {
	day = obj.day;
	month = obj.month;
	year = obj.year;
	weekday[7] = obj.weekday[7];
	monthname[12] = obj.monthname[12];
};

void DateTime::printToday() {
	cout << "Today is "
		<< weekday[(day % 7) + 1] << " "
		<< monthname[month - 1] << " "
		<< day << " "
		<< year << " " << endl;
};

void DateTime::printYesterday() {
	cout << "Yesterday is "
		<< weekday[day % 7] << " "
		<< monthname[month - 1] << " "
		<< day << " "
		<< year << " " << endl;
};

void DateTime::printTommorow() {
	cout << "Tommorow is "
		<< weekday[(day % 7) + 2] << " "
		<< monthname[month - 1] << " "
		<< day << " "
		<< year << " " << endl;
};

void DateTime::printFuture(int N) {
	tm now = {};
	now.tm_year = year;
	now.tm_mon = month;
	now.tm_mday = day;

	now.tm_mday += N;
	mktime(&now);

	cout << "After " << N << " days there will be "
		<< now.tm_mday << " "
		<< now.tm_mon << " "
		<< now.tm_year << endl;
};

void DateTime::printPast(int N) {
	tm now = {};
	now.tm_year = year;
	now.tm_mon = month;
	now.tm_mday = day;

	now.tm_mday -= N;
	mktime(&now);

	cout << "Before " << N << " days there was "
		<< now.tm_mday << " "
		<< now.tm_mon << " "
		<< now.tm_year << endl;
};

void DateTime::printMonth() {
	cout << monthname[month - 1] << endl;
};

void DateTime::printWeekDay() {
	cout << weekday[(day % 7) + 1] << endl;
};

void DateTime::calcDifference() {
	struct tm a = { 0,0,0,31,12,117 };
	struct tm b = { 0,0,0,28,3,117 };
	time_t x = mktime(&a);
	time_t y = mktime(&b);

	int difference = difftime(y, x) / (60 * 60 * 24);
	cout << ctime(&x);
	cout << ctime(&y);
	cout << "Between dates "
		<< abs(difference) << " days" << endl;
};

DateTime::~DateTime() { };