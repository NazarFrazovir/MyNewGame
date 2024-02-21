//
// Created by Nazar Frazovir on 21.02.2024.
//
#include <iostream>
#include "Player.h"


Player::Player()
//        :name{"Unknown"}, health{0}, armor{0}, xp{0}
        : Player{"Unknown",0,0,0}{}

Player::Player(std::string new_name, int new_health)
//        :name{new_name}, health{new_health}
        :Player{new_name,new_health,0,0}{}

Player::Player(std::string new_name, int new_health, int new_armor)
        :Player{new_name,new_health,new_armor,0}{}

Player::Player(std::string new_name, int new_health, int new_armor, int new_xp)
        :name{new_name},armor{new_armor},xp{new_xp}{health=new_health;}


Player::~Player() {}

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

