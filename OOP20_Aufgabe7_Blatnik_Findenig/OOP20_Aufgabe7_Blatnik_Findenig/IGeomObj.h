#pragma once
#include "IUniqueID.h"
class IGeomObj : public IUniqueID
{
public:
	virtual void output() = 0;
	virtual double area() = 0;
	virtual double circumference() = 0;
};

