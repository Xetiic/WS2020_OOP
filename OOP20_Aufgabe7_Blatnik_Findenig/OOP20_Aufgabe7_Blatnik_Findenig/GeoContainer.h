#pragma once
#include "IGeomObj.h"
#include <vector>
class GeoContainer : public IGeomObj
{
private:
	std::vector<IGeomObj*> vector;

public:
	void output() override;
	double area() override;
	double circumference() override;

	//setter
	void addObject(IGeomObj* add) {
		this->vector.push_back(add);
	}
};

