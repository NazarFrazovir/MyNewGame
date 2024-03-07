//
// Created by Nazar Frazovir on 07.03.2024.
//

#include <iostream>
#include "Player.h"
#include "Archer.h"
#include "Spell.h"

Archer::Archer() :Player(){
    bowType[0] = "Basic";
    damageArrows = 10;
    numberArrows = 10;
    flightRange =  20;

}

Archer::Archer(int newNumbersArrows)
:Player("Unknown", health > 0 ? health : 0, 0, 0),
numberArrows(newNumbersArrows){}

Archer::Archer(int newNumbersArrows, int newFlightRange)
:Player("Unknown", health > 0 ? health : 0, 0, 0),
numberArrows(newNumbersArrows),flightRange(newFlightRange){}

Archer::Archer(int newNumbersArrows, int newFlightRange, int newDamageArrows)
: Player("Unknown", health > 0 ? health : 0, 0, 0),
numberArrows(newNumbersArrows),flightRange(newFlightRange), damageArrows(newDamageArrows){}

Archer &Archer::operator=(const Archer &other) {
    if (this != &other){
        Player::operator=(other);
        damageArrows = other.damageArrows;
        numberArrows = other.numberArrows;
        flightRange = other.flightRange;
    }
    return *this;
}

Archer::~Archer() {}

void Archer::useSpell1(const Spell &spell) {damageArrows += spell.getDamageBonus();}

void Archer::Show()const{std::cout<<"damage: "<<damageArrows<<std::endl;}

void Archer::setDamageArrows(int newDamageArrows) {damageArrows = newDamageArrows;}

void Archer::setFlightRange(int newFlightRange) {flightRange = newFlightRange;}

void Archer::setNumberArrows(int newNumbersArrows) {numberArrows = newNumbersArrows;}