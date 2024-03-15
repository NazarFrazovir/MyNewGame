//
// Created by Nazar Frazovir on 15.03.2024.
//
#include "Interface.h"

Interface::~Interface(){}

std::ostream &operator<<(std::ostream &os, const Interface& obj){
    obj.print(os);                  // Interface
    return os;
}