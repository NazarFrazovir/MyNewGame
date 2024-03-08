//
// Created by Nazar Frazovir on 29.02.2024.
//
#include "Enemy.h"
#include <iostream>
#include "EnemySwordMan.h"

EnemySwordMan::EnemySwordMan():Enemy() {
    enemy_sword_damage= 10 ;
    enemy_precision = 5;
    enemy_mobility = 5;
}
EnemySwordMan::EnemySwordMan(int new_enemy_sword_damage, int new_enemy_precision, int new_enemy_mobility)
: Enemy("Unknown",0,0),enemy_sword_damage(new_enemy_sword_damage),
enemy_precision(new_enemy_precision),enemy_mobility(new_enemy_mobility){}

EnemySwordMan::EnemySwordMan(EnemySwordMan &&other) noexcept
: Enemy(std::move(other)),
enemy_sword_damage(other.enemy_sword_damage),enemy_mobility(other.enemy_mobility),enemy_precision(other.enemy_precision)
{
    other.enemy_sword_damage = 0;
    other.enemy_precision = 0;
    other.enemy_mobility = 0;
}               // move constructor inheritance

//EnemySwordMan::EnemySwordMan(const EnemySwordMan &other)
//: Enemy("Unknown",0,0),enemy_sword_damage(other.enemy_sword_damage),          copy constructor for example
//enemy_precision(other.enemy_precision),enemy_mobility(other.enemy_mobility){}

EnemySwordMan::~EnemySwordMan() {}

void EnemySwordMan::enemy_setSwordDamage(int new_enemy_sword_damage) {
    this->enemy_sword_damage = new_enemy_sword_damage;
}
void EnemySwordMan::enemy_setMobility(int new_enemy_mobility) {
    this->enemy_mobility = new_enemy_mobility;
}
void EnemySwordMan::enemy_setPrecision(int new_enemy_precision) {
    this->enemy_precision = new_enemy_precision;
}
 void EnemySwordMan::enemyDisplay() const {
    Enemy::enemyDisplay();
    std::cout<<"Sword damage: "<<enemy_sword_damage<<std::endl;
    std::cout<<"Mobility: "<<enemy_mobility<<std::endl;
    std::cout<<"Precision: "<<enemy_precision<<std::endl;
}





