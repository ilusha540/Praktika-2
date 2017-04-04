#include "Circle.h"
#include <conio.h>
#include <iostream>


int main()
{
	cout << "Earth" << endl;
	Circle Earth(6378.1);
	Circle Line;

	Line.set_the_ference(Earth.get_ference() + 1);

	double loop = Line.get_radius() - Earth.get_radius();

	cout << "The loop = " << loop << endl;
	cout << "___________________" << endl;

	cout << "The Pool" << endl;
	Circle Pool(3);
	Circle Perim(4);

	double track = (Perim.get_area() - Pool.get_area())*1000;
	double fence = Perim.get_ference()*2000;
	cout << "Price of materials for the track = " << track << endl;
	cout << "Price of materials for the fence = " << fence << endl;
	cout << "Amount of expenses = " << track + fence << endl;
	_getch();
	return 0;
}