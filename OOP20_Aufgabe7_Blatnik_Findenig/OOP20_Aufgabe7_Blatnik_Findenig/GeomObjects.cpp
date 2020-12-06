// GeomObjects.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#ifndef GeoObjects_H
#define GeoObjects_H
#include "GeoObjects.h"
#endif
#include "IUniqueID.h"
#include "GeoContainer.h"
#include "GeoHouse.h"

unsigned IUniqueID::uniqueID = 0;

int main()
{
    GeoSquare sq;
    GeoRect rec;
    GeoEllipse el;
    GeoCircle cir;
    GeoTriangle tr;

    sq.setSize(5);
    rec.setSize(5,7);
    el.setSize(1, 2);
    cir.setSize(3);
    tr.setSize(3, 4, 5);

    sq.output();
    rec.output();
    el.output();
    cir.output();
    tr.output();

    GeoContainer cont;
    cont.addObject(&sq);
    cont.addObject(&sq);
    cont.addObject(&tr);
    std::cout << "Container content:" << std::endl;
    cont.output();
    std::cin.get();
    std::cout << "House content:" << std::endl;

    
    GeoHouse house(5, 3, 2);
    house.output();
    
}

