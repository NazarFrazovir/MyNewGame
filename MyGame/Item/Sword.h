//
// Created by Nazar Frazovir on 25.03.2024.
//

#ifndef MYGAME_SWORD_H
#define MYGAME_SWORD_H

#include <iostream>
#include "Object.h"
class Sword: public Object{
private:
    int damage;
    int bladeSharpness;
public:
    Sword();
    Sword(std::string name,int weight, int damage,int bladeSharpness);
    ~Sword();
};
#endif //MYGAME_SWORD_H
