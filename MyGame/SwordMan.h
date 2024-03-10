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
    virtual ~SwordMan();            // I set virtual destructor, because if(base class have virtual destructor,
    //   and subsidiaries must have virtual destructor)

    void useSpell(const Spell& spell);
    void setSwordDamage(int new_sword_damage);
    void setPrecision(int new_precision);
    void setMobility(int new_mobility);
    void display() const override final;              //final (method) cannot be override.
    void makeSound() override;              // pure virtual function
    virtual void print(std::ostream& os) const override{
        os << "I'm "<<name<< ", What's going on? "<< std::endl;
        os << std::endl;
    }
    void representation(SwordMan& obj){
        std::cout<<obj;
    }

};

#endif //MYGAME_SWORDMAN_H
