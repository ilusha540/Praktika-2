#include <iostream>
#include <ctime>
#include "datetime.h"
#include "date.h"
using namespace std;

int main() {

	DateTime obj1;
	obj1.printToday();
	obj1.printYesterday();
	obj1.printTommorow();
	obj1.printFuture(29);
	obj1.printPast(255);
	obj1.printMonth();
	obj1.printWeekDay();

	DateTime obj2(31, 12, 2017);
	obj2.calcDifference();

	return 0;
};