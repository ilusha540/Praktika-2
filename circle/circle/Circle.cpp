#include "Circle.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std; // идентификатор пространство имён

Circle::Circle(double radius)
	{
		set_the_radius(radius);
	}

void Circle::set_the_radius(double radius)
	{
		с->radius = radius; // Выбор элемента по указателю, выбираем элемент radius
		с->ference = 2*(M_PI)*radius; 
		 с->area = M_PI*pow(radius, 2);
		//cout << radius << "," << ference << "," << area << endl;
	}

void Circle::set_the_ference(double ference)
	{
		с->ference = ference;
		с->radius = ference/(2*M_PI);
		с->area = 2*pow(radius, 2);
		//cout << radius << ",   " << ference << ",   " << area << endl;
	}

void Circle::set_the_area(double area)
	{
		с->area = area;
		с->radius = sqrt(area*M_PI);
		 с->ference = 2*M_PI*radius;
		//cout << radius << "," << ference << "," << area << endl;
	}

double Circle::get_radius()
	{
		return radius;
	}

double Circle::get_area()
	{
		return area;
	}

double Circle::get_ference()
	{
		return ference;
	}

	Circle::Circle()
	{
		set_the_radius(0);
}
