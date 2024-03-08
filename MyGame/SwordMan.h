//
// Created by Nazar Frazovir on 29.02.2024.
//

#ifndef MYGAME_SWORDMAN_H
#define MYGAME_SWORDMAN_H
#include <iostream>
#include "Player.h"
#include "Spell.h"


class SwordMan:public Player{
private:
    std::string sword_Type[4]={"Basic", "Master", "Grandmaster", "Gven'nel"};
    int sword_damage;
    int precision;
    int mobility;
    Spell spell;

public:
    SwordMan();
    SwordMan(int new_sword_damage,int new_precision,int new_mobility);
    SwordMan& operator=(const SwordMan& other);
    virtual ~SwordMan();

    void useSpell(const Spell& spell);
    void setSwordDamage(int new_sword_damage);
    void setPrecision(int new_precision);
    void setMobility(int new_mobility);
    void display() const override;               //final


};

#endif //MYGAME_SWORDMAN_H
