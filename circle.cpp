#include "circle.h"
#include <cmath>
#include "circle.h"
using namespace std;

#define pi 3.1416
#define C_radiusEarth 6378.1
#define C_radiusPool 3.0
#define C_radiusTrack 4.0

Circle::Circle(double) {
	set_radius(0);
}

void Circle::set_radius(double C_radius) {
	C_radius = C_radius;
	C_circumference = 2 * pi * C_radius;
	C_area = pi * C_radius * C_radius;
};

void Circle::set_circumference(double C_circumference) {
	C_circumference = C_circumference;
	C_radius = C_circumference / (2 * pi);
	C_area = pi * C_radius * C_radius;
};

void Circle::set_area(double C_area) {
	C_area = C_area;
	C_radius = sqrt(C_area / pi);
	C_circumference = 2 * pi * C_radius;
};

double Circle::get_radius() {
	return C_radius;
};

double Circle::get_circumference() {
	return C_circumference;
};

double Circle::get_area() {
	return C_area;
};

Circle::~Circle() { };