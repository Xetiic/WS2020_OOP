#pragma once
#include "GeoContainer.h"
#ifndef GeoObjects_H
#define GeoObjects_H
#include "GeoObjects.h"
#endif
#include <math.h>
class GeoHouse : virtual public GeoContainer
{
private:
	GeoRect base;
	GeoTriangle roof;
	unsigned uID;
public:
	GeoHouse(double width, double height, double heightroof) {
		uID = IUniqueID::counter();
		this->base.setSize(width, height);
		double roofside;
		roofside = sqrt(pow((width / 2), 2) + pow(heightroof, 2));
		this->roof.setSize(width, roofside, roofside);

		GeoContainer::addObject(&base);
		GeoContainer::addObject(&roof);
	}
};

