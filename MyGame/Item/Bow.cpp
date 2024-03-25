//
// Created by Nazar Frazovir on 25.03.2024.
//
#include <iostream>
#include "Bow.h"
Bow::Bow()
:Object(name,weight),damage(0), flightRange(0){}

Bow::Bow(std::string name, int weight, int damage, int flightRange)
: Object(name, weight), damage(damage), flightRange(flightRange){}

Bow::~Bow() {}