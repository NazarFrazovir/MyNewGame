//
// Created by Nazar Frazovir on 21.02.2024.
//
#include <iostream>
#include "Player.h"

void Player::SetHealth(int new_health) {
    this -> health = new_health;                    // this Вказує на поточний обʼєкт класу Player
}
bool Player::HealtBool() {
    if( health <= 0){
        return false;
    }else{
        return true;
    }
}
void Player::SetName(std::string new_name){
    this->name = new_name;
}
void Player::SetArmor(int new_armor) {
    this->armor = new_armor;
}
void Player::Stat() const{
    std::cout<<"Player name: "<<Player::name<<std::endl;
    std::cout<<"Health: "<<Player::health<<std::endl;
    std::cout<<"Armor: "<<Player::armor<<std::endl;
}

