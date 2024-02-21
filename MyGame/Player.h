//
// Created by Nazar Frazovir on 21.02.2024.
//

#ifndef MYGAME_PLAYER_H
#define MYGAME_PLAYER_H
#include <iostream>



class Player {
private:
    std::string name;
    int xp;
    int health;
    int armor;
    std::string weapon[3] = {"Sword", "Bow", "Spear"};
    std::string player_weapon_class;
public:

    Player(); // default constructor
    Player(std::string new_name, int new_health);
    Player(std::string new_name, int new_health, int new_armor);
    Player(std::string new_name, int new_health,int new_armor, int new_xp ); // Overloaded constructor
    Player& operator=(const Player& other);
    Player operator -(); // Оператор -() потрібний в ігрі для того щоб проходив кріт урон по броні.
    ~Player(); // destructor


    void SetName(std::string new_name);

    void SetArmor(int new_armor);

    void SetHealth(int new_health);

    bool HealtBool();

    void Weapon();

    void Stat() const;
};
#endif //MYGAME_PLAYER_H
