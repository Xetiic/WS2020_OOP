#include "GeoContainer.h"

double GeoContainer::area() {
	double area = 0;
	for (auto& elem : this->vector) {
		area += elem->area();
	}
	return area;
}

double GeoContainer::circumference() {
	double totalcircum = 0;
	for (auto& elem : this->vector) {
		totalcircum += elem->circumference();
	}
	return totalcircum;
}

void GeoContainer::output() {
	for (auto& elem : this->vector) {
		elem->output();
	}
}