//
// Created by Nazar Frazovir on 07.03.2024.
//

#ifndef MYGAME_ARCHER_H
#define MYGAME_ARCHER_H

#include <iostream>
#include "Player.h"
#include "Spell.h"

class Archer : public Player{
private:
    std::string bowType[4] = {"Basic", "Middle", "Legendary","Bow of God"};
    int numberArrows;
    int flightRange;
    int damageArrows;
    Spell spell;
public:
    Archer();
    Archer(int newNumbersArrows);
    Archer(int newNumbersArrows, int newFlightRange);
    Archer(int newNumbersArrows, int newFlightRange, int newDamageArrows);
    Archer& operator=(const Archer& other);
    ~Archer();

    void useSpell1(const Spell& spell);

    void setNumberArrows(int newNumbersArrows);
    void setFlightRange(int newFlightRange);
    void setDamageArrows(int newDamageArrows);
    void Show() const;
};


#endif //MYGAME_ARCHER_H
