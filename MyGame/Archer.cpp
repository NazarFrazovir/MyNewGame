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
numberArrows(newNumbersArrows > 0 ? newNumbersArrows : 0){}

Archer::Archer(int newNumbersArrows, float newFlightRange)
:Player("Unknown", health > 0 ? health : 0, 0, 0),
numberArrows(newNumbersArrows > 0 ? newNumbersArrows : 0),flightRange(newFlightRange){}

Archer::Archer(int newNumbersArrows, float newFlightRange, float newDamageArrows)
: Player("Unknown", health > 0 ? health : 0, 0, 0),
numberArrows(newNumbersArrows > 0 ? newNumbersArrows : 0),
flightRange(newFlightRange), damageArrows(newDamageArrows > 0 ? newDamageArrows : 0){}

Archer &Archer::operator=(const Archer &other) {
    if (this != &other){
        Player::operator=(other);
        damageArrows = other.damageArrows;
        numberArrows = other.numberArrows;
        flightRange = other.flightRange;
    }
    return *this;
}

Archer::~Archer() noexcept {}

void Archer::useSpell(const Spell &spell) {damageArrows += spell.getDamageBonus();}

void Archer::setDamageArrows(int newDamageArrows) {damageArrows = newDamageArrows;}

void Archer::setFlightRange(int newFlightRange) {flightRange = newFlightRange;}

void Archer::setNumberArrows(int newNumbersArrows) {numberArrows = newNumbersArrows;}

void Archer::display() const {
    Player::display();
    std::cout<<"Arrow damage : "<<damageArrows<<std::endl;
    std::cout<<"Flight range: "<<flightRange<<std::endl;
    std::cout<<"Number of Arrows: "<<numberArrows<<std::endl;
    std::cout<<std::endl;
}

void Archer::makeSound()  {
    std::cout<<"I'm "<<name<< ", and I'm the best Archer in the world. "<<std::endl;
    std::cout<<std::endl;
}
