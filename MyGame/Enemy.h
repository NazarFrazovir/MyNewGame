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
    Enemy();

    Enemy(std::string enemy_new_name);

    Enemy(std::string enemy_new_name, int enemt_new_health);            // Overloaded operator

    Enemy(std::string enemy_new_name, int enemy_new_health, int enemy_new_armor);

    Enemy(const Enemy& other); // - copy constructor

    ~Enemy();

    void Enemy_SetName(std::string enemy_new_name);

    void Enemy_Weapon();

    void Enemy_Stat() const;

    friend std::ostream& operator<<(std::ostream& os, const Enemy& enemy);

    friend  std::istream& operator>>(std::istream& is, Enemy& enemy);
};
#endif //MYGAME_ENEMY_H
