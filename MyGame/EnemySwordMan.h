//
// Created by Nazar Frazovir on 29.02.2024.
//

#ifndef MYGAME_ENEMYSWORDMAN_H
#define MYGAME_ENEMYSWORDMAN_H
#include "Enemy.h"
#include <iostream>

class EnemySwordMan final :public Enemy {
private:
    int enemy_sword_damage;
    int enemy_precision;
    int enemy_mobility;
public:
    EnemySwordMan();
    EnemySwordMan(int new_enemy_sword_damage,int new_enemy_precision,int new_enemy_mobility);
    EnemySwordMan(EnemySwordMan&& other) noexcept;
//    EnemySwordMan(const EnemySwordMan& other);        copy constructor for example
    ~EnemySwordMan();

    void enemy_setSwordDamage(int new_enemy_sword_damage);
    void enemy_setPrecision(int new_enemy_precision);
    void enemy_setMobility(int new_enemy_mobility);
    void enemyDisplay() const override final;
};

#endif //MYGAME_ENEMYSWORDMAN_H
