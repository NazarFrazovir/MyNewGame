//
// Created by Nazar Frazovir on 24.03.2024.
//

#ifndef MYGAME_OBJECT_H
#define MYGAME_OBJECT_H
#include <iostream>
#include "../Character/SwordMan.h"
#include "../Character/Archer.h"
#include "../Character/Player.h"
#include "Spell.h"

class Object{
public:
    Object();

    std::string name;
    int weight;

    Object(std::string name, int weight);
    std::string getName(){return name;}

};
#endif //MYGAME_OBJECT_H
