#pragma once
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;


class Circle
{
public:
	Circle(double radius);
	void set_the_radius(double radius);
	void set_the_ference(double ference);
	void set_the_area(double area);
	double get_radius();
	double get_area();
	double get_ference();
	Circle();

private:
	double radius, ference, area;
};