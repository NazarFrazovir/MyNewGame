//
// Created by Nazar Frazovir on 25.03.2024.
//

#ifndef MYGAME_BOW_H
#define MYGAME_BOW_H
#include <iostream>
#include "Object.h"

class Bow: public Object{
private:
    int damage;
    int flightRange;
public:
    Bow();
    Bow(std::string name,int weight,int damage,int fightRange);
    ~Bow();
};
#endif //MYGAME_BOW_H
