//
// Created by Nazar Frazovir on 29.02.2024.
//
#include <iostream>
#include "Player.h"
#include "SwordMan.h"
#include "Spell.h"

SwordMan::SwordMan() :Player(){
    sword_Type = "Basic";
    sword_damage= 10 ;
    precision = 5;
    mobility = 5;
}
SwordMan::SwordMan(int new_sword_damage, int new_precision,int new_mobility)
: Player(name,health > 0 ? health : 0,armor,xp),
sword_damage(new_sword_damage > 0 ? new_sword_damage : 0),
precision(new_precision),mobility(new_mobility){}

SwordMan &SwordMan::operator=(const SwordMan &other) {
    if(this != &other){
        Player::operator=(other);
        sword_damage = other.sword_damage;
        precision = other.precision;
        mobility = other.mobility;
    }
    return *this;
}

SwordMan::~SwordMan() noexcept{}

void SwordMan::useSpell(const Spell& spell) {
    sword_damage += spell.getDamageBonus();
}

void SwordMan::setSwordDamage() {
    int new_sword_damage;
    std::cout<<"Enter Sword damage: "<<std::endl;
    std::cin>>new_sword_damage;
    try {
        if (new_sword_damage < 0 || new_sword_damage > 100) {
            throw 0;
            sword_damage = new_sword_damage;                     // Exception
        }
    }catch (int &ex){
        std::cerr<<"Sword damage can't be < 0 and can't be > 100 "<<std::endl;
        exit(1);
    }
}

void SwordMan::setMobility() {
    int new_mobility;
    std::cout<<"Enter Mobility: "<<std::endl;
    std::cin>>new_mobility;
    try {
        if (new_mobility < 0 || new_mobility > 100) {
            throw 0;
            mobility = new_mobility;                     // Exception
        }
    }catch (int &ex){
        std::cerr<<"Mobility can't be < 0 and can't be > 100 "<<std::endl;
        exit(1);
    }

}

void SwordMan::setPrecision() {
    int new_precision;
    std::cout<<"Enter Precision: "<<std::endl;
    std::cin>>new_precision;
    try {
        if (new_precision < 0 || new_precision > 100) {
            throw 0;
            precision = new_precision;                     // Exception
        }
    }catch (int &ex){
        std::cerr<<"Precision can't be < 0 and can't be > 100 "<<std::endl;
        exit(1);
    }

}

void SwordMan::display() const {
    Player::display();
    std::cout<<"Sword damage : "<<sword_damage<<std::endl;
    std::cout<<"Precision: "<<precision<<std::endl;
    std::cout<<"Mobility: "<<mobility<<std::endl;
    std::cout<<"Sword: "<<sword_Type<<std::endl;
    std::cout<<std::endl;
}

void SwordMan::makeSound()  {
    std::cout<<"I'm "<<name<<", and I'm the best SwordsMan in the world. "<<std::endl;
    std::cout<<std::endl;
}

void SwordMan::print(std::ostream &os) const {
    os<<"Interface for Sword man: "<<std::endl;
    os<< "My Sword damage: "<<sword_damage<<std::endl<<"Precision: "<<precision<<std::endl
       <<"Mobility: "<<mobility<<std::endl;
    os<< std::endl;
}

void SwordMan::setStat() {
    std::cout<<" Enter SwordMan characteristic: "<<std::endl;
    Player::setStat();
    setSwordDamage();
    setMobility();
    setPrecision();
}

void SwordMan::setWeapon() {
    std::cout<<"Enter you're Sword: [Basic] [Master] [Grand Master] [Gven'nel]"<<std::endl;
    std::string newSwordType;
    getline(std::cin,newSwordType);
    if (newSwordType == "Basic"){
        std::cout<<"You're sword is {Basic} "<<std::endl;
        precision = 20;
        mobility = 30;
        sword_damage = 20;
        sword_Type = newSwordType;
    } else if(newSwordType == "Master"){
        std::cout<<"You're sword is {Master} "<<std::endl;
        precision = 30;
        mobility = 40;
        sword_damage = 35;
        sword_Type = newSwordType;
    } else if(newSwordType == "Grand Master"){
        std::cout<<"You're sword is {Grand Master} "<<std::endl;
        precision = 40;
        mobility = 60;
        sword_damage = 45;
        sword_Type = newSwordType;
    } else if(newSwordType == "Gven'nel"){
        std::cout<<"You're sword is {Gven'nel} "<<std::endl;
        precision = 50;
        mobility = 80;
        sword_damage = 60;
        sword_Type = newSwordType;
    }else{
        std::cout<<"Incorrect sword type entered "<<std::endl;
    }
}

