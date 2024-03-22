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

void Archer::setDamageArrows() {
    int newDamageArrows;
    std::cout << "Enter Damage of arrows: " << std::endl;
    std::cin >> newDamageArrows;
    try {
        if (newDamageArrows < 0 || newDamageArrows > 100)
            throw 0;
            damageArrows = newDamageArrows;                     // Exception
    }catch (int &ex){
        std::cerr<<"Damage can't be < 0 and can't be > 100 "<<std::endl;
        exit(1);
    }
}

void Archer::setFlightRange() {
    int newFlightRange;
    std::cout<<"Enter Flight Range: "<<std::endl;
    std::cin>>newFlightRange;
    try {
        if (newFlightRange < 0 || newFlightRange > 100)
            throw 0;
            flightRange = newFlightRange;                     // Exception
    }catch (int &ex){
        std::cerr<<"Flight range can't be < 0 and can't be > 100 "<<std::endl;
        exit(1);
    }
}

void Archer::setNumberArrows() {
    int newNumbersArrows;
    std::cout<<"Enter Number of arrwos (1-30): "<<std::endl;
    std::cin>>newNumbersArrows;
    try {
        if (newNumbersArrows < 0 || newNumbersArrows > 30) {
            throw 0;
            numberArrows = newNumbersArrows;                     // Exception
        }
    }catch (int &ex){
        std::cerr<<"Numbers of arrows can't be < 0 and can't be > 30 "<<std::endl;
        exit(1);
    }
}

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

void Archer::print(std::ostream &os) const {
    std::cout<<"Interface for Archer: "<<std::endl;
    std::cout << "My number arrows: "<<numberArrows<<std::endl<<"Flight range: "<<flightRange<<std::endl
    <<"Damage arrows: "<<damageArrows<<std::endl;
    std::cout << std::endl;
}
void Archer::setStat(){
    std::cout<<" Enter SwordMan characteristic: "<<std::endl;
    Player::setStat();
    setDamageArrows();
    setNumberArrows();
    setFlightRange();
}

