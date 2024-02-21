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
    static int health;
    int armor;
    std::string weapon[3] = {"Sword", "Bow", "Spear"};
    std::string player_weapon_class;
public:
    void SetName(std::string new_name);

    void SetArmor(int new_armor);

    void SetHealth(int new_health);

    bool HealtBool();

    void Stat() const;
};
#endif //MYGAME_PLAYER_H
