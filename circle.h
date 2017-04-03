#pragma once
class Circle
{
private:
	double C_radius, C_circumference, C_area;
	
	public:
		Circle(double);
		void set_radius(double);
		void set_circumference(double);
		void set_area(double);
		double get_radius();
		double get_circumference();
		double get_area();
		~Circle();
};