//
// Created by Nazar Frazovir on 25.03.2024.
//
#include <iostream>
#include "Sword.h"

Sword::Sword()
: Object(name,weight),damage(0), bladeSharpness(0){}

Sword::Sword(std::string name, int weight, int damage, int bladeSharpness)
: Object(name, weight), damage(damage), bladeSharpness(bladeSharpness){}

Sword::~Sword() {}