//
// Created by Nazar Frazovir on 21.02.2024.
//

#ifndef MYGAME_PLAYER_H
#define MYGAME_PLAYER_H
#include <iostream>



class Player {
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
    Player operator -(); // Оператор -() потрібний в ігрі для того щоб проходив кріт урон по броні.
    virtual ~Player(); // destructor


    void setName(std::string new_name);

    void setArmor(int new_armor);

    void setHealth(int new_health);

    void attack();

    void weapons();

    bool healtBool();

    virtual void display() const;           // virtual methods

     void displayInfoOnUI();       // Static method binding

private:
    std::string weapon[3] = {"Sword", "Bow", "Spear"};
    std::string player_weapon_class;
};
#endif //MYGAME_PLAYER_H
