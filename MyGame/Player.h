//
// Created by Nazar Frazovir on 21.02.2024.
//

#ifndef MYGAME_PLAYER_H
#define MYGAME_PLAYER_H
#include <iostream>
#include "Interface.h"


class Player: public Interface{
//    friend std::ostream &operator<<(std::ostream &os, const Player &obj);           // Interface
protected:
    std::string name;
    int xp;
    int health;
    int armor;

public:

    Player(); // default constructor
    Player(std::string new_name, int new_health);
    Player(std::string new_name, int new_health, int new_armor);
    Player(std::string new_name, int new_health,int new_armor, int new_xp ); // Overloaded constructor
    Player& operator=(const Player& other);
    Player& operator -(); // Оператор -() потрібний в ігрі для того щоб проходив кріт урон по броні.
    virtual ~Player(); // destructor


    void setName();

    virtual  void  setStat();

    void setArmor();

    void setHealth();

    void attack();

    void weapons();

    bool healtBool();

    virtual void display() const;           // virtual methods

    virtual void showStatHealthAndArmor();

    virtual void makeSound()  = 0;                 //pure virtual function
//
    virtual void print(std::ostream& os)const override;

//    void representation(Player& obj);


private:
    std::string weapon[3] = {"Sword", "Bow", "Spear"};
    std::string player_weapon_class;
};
#endif //MYGAME_PLAYER_H
