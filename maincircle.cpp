#include <iostream>
#include <cmath> // cmath - это заголовочный файл 
// стандартной библиотеки €зыка программировани€ —.
#include "circle.h"
// некоторое множество, под которым подразумеваетс€ модель, 
// абстрактное хранилище или окружение, созданное дл€ логической
// группировки уникальных индификаторов(то есть имЄн)
using namespace std; 

#define pi 3.1416
#define C_radiusEarth 6378.1
#define C_radiusPool 3.0
#define C_radiusTrack 4.0

int main() {

	// Gap between Earth & Rope
	Circle  Earth(C_radiusEarth);
	Circle Rope(0);
	Rope.set_circumference(Earth.get_circumference() + 1);

	double gap = Rope.get_radius() - Earth.get_radius();

	cout << "The gap between Earth & Rope is " << gap << "km" << endl;

	// Stuff price
	Circle Pool(C_radiusPool);
	Circle Perimeter(C_radiusTrack);

	Pool.set_radius(C_radiusPool);
	Perimeter.set_radius(C_radiusTrack);

	double track = Perimeter.get_area() - Pool.get_area();
	double fence = Perimeter.get_circumference();
	double cost_track = track * 1000;
	double cost_fence = fence * 2000;

	cout << "Cost of track is " << cost_track << " rubles" << endl;
	cout << "Cost of track & fence is "
		<< cost_track + cost_fence << " rubles" << endl;

	return 0;
};