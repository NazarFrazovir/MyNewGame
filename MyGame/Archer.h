//
// Created by Nazar Frazovir on 07.03.2024.
//

#ifndef MYGAME_ARCHER_H
#define MYGAME_ARCHER_H

#include <iostream>
#include "Player.h"
#include "Spell.h"

class Archer final : public Player{
private:
    std::string bowType[4] = {"Basic", "Middle", "Legendary","Bow of God"};
    int numberArrows;
    float flightRange;
    float damageArrows;
    Spell spell;
public:
    Archer();
    Archer(int newNumbersArrows);
    Archer(int newNumbersArrows, float newFlightRange);
    Archer(int newNumbersArrows, float newFlightRange, float newDamageArrows);
    Archer& operator=(const Archer& other);
    virtual ~Archer();          // I set virtual destructor, because if(base class have virtual destructor,
    //   and subsidiaries must have virtual destructor)

    void useSpell(const Spell& spell);
    void setNumberArrows();
    void setFlightRange();
    void setDamageArrows();
     void display() const override ;
     void makeSound() override;
     virtual void print(std::ostream& os) const override;
     void setStat() override;
    void createArcher();

//     void representation(Archer& obj);


};


#endif //MYGAME_ARCHER_H
