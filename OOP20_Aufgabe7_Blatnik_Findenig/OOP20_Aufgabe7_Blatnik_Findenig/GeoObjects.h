#include "IGeomObj.h"
#include <iostream>
#include "IUniqueID.h"

#define _USE_MATH_DEFINES
#include <math.h>

class GeoRect : public IGeomObj
{
private:
	double length = 0, height = 0;
	unsigned uID;
public:
	GeoRect() {
		this->uID = IUniqueID::counter();
	}
	double area() override {
		return length * height;
	}
	double circumference() override {
		return 2 * (length + height);
	}
	void output() override {
		std::cout << "This is a Rectangle with the Area: " << area() << " and the circumference " << circumference() << std::endl;
	}
	//setters:
	void setSize(double length, double height) {
		this->length = length;
		this->height = height;
	}

};


class GeoSquare : public GeoRect
{
	unsigned uID;
public:
	GeoSquare(){
		this->uID = IUniqueID::counter();
	}
	void output() override{
		std::cout << "This is a Square with the Area: " << area() << " and the circumference " << circumference() << std::endl;
	}
	

	//setters:
	void setSize(double length){
		GeoRect::setSize(length, length);
	}
};

class GeoEllipse : public IGeomObj
{
	unsigned uID;
private:
	double length = 0, height = 0;

public:
	GeoEllipse() {
		this->uID = IUniqueID::counter();
	}
	void output() override {
		std::cout << "This is a Ellipse with the Area: " << area() << " and the circumference " << circumference() << std::endl;
	}
	double area() override {
		return this->length * this->height * M_PI;
	}
	double circumference() override {
		return M_PI * sqrt(2) * (pow((0.5 * length), 2) + pow((0.5 * height), 2));
	}
	//setters:
	void setSize(double length, double height) {
		this->length = length;
		this->height = height;
	}
};

class GeoCircle : public GeoEllipse
{
	unsigned uID;
private:
	double radius = 0;

public:
	GeoCircle() {
		this->uID = IUniqueID::counter();
	}
	double circumference() override {
		return 2*this->radius * M_PI;
	}

	void output() override {
		std::cout << "This is a Circle with the Area: " << area() << " and the circumference " << circumference() << std::endl;
	}

	//setters:
	void setSize(double radius) {
		GeoEllipse::setSize(radius, radius);
		this->radius = radius;
	}
};

class GeoTriangle : public IGeomObj
{
	unsigned uID;
private:
	double a = 0, b = 0, c=0;

public:
	GeoTriangle() {
		this->uID = IUniqueID::counter();
	}
	double area() override {
		double s = (a + b + c) / 2;
		return sqrt(s*(s-a)*(s-b)*(s-c));
	}
	double circumference() override {
		return a+b+c;
	}

	void output() override {
		std::cout << "This is a Triangle with the Area: " << area() << " and the circumference " << circumference() << std::endl;
	}


	//setters:
	void setSize(double a, double b, double c) {
		this->c = c;
		this->a = a;
		this->b = b;
	}
};


