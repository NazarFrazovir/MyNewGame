//
// Created by Nazar Frazovir on 21.02.2024.
//

#ifndef MYGAME_ENEMY_H
#define MYGAME_ENEMY_H
#include <iostream>
#include <string>
#include "Player.h"

class Enemy {
private:
    std::string enemy_name;
    int enemy_health;
    int enemy_armor;
    bool enemy_isAlive;
public:
    void Enemy_SetName();

    void Enemy_Weapon();

    void Enemy_Stat() const;
};
#endif //MYGAME_ENEMY_H
