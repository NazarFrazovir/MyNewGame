//
// Created by Nazar Frazovir on 29.02.2024.
//

#ifndef MYGAME_SPELL_H
#define MYGAME_SPELL_H
#include <iostream>
#include "SwordMan.h"


class Spell{

private:
int spell_for_damage ;

int spell_for_mobility;

int spell_for_precision;

public:
    Spell();
    Spell(int damageBonus,int mobilityBonus,int precisionBonus);
    ~Spell();
    int getDamageBonus()const;
    int getMobilityBonus()const;
    int getPrecisionBonus()const;
};

#endif //MYGAME_SPELL_H
