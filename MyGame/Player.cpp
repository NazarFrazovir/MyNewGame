//
// Created by Nazar Frazovir on 21.02.2024.
//
#include <iostream>
#include "Player.h"

int Player::health = 100; // initialization static
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

Player& Player::operator=(const Player &other){
        if (this != &other) {
            this->armor = other.armor;         // Assigment operator - він потрібний для того щоб спрацював оператор -()
        }
        return *this;
    }

Player Player::operator-() {
    armor = -armor;              // Add unary operator - Для критичного удара по броні.
    return *this;
}


Player::~Player() {}

void Player::Weapon(){
    std::string weapon_class;
    double weapon_class_point;
    double damage;
    int breaking_armor;
    std::string new_weapon;
    std::cout<<"Enter you're weapon: (Sword) (Bow) (Spear) "<<std::endl;
    getline(std::cin,new_weapon);
    if (new_weapon == "Sword"){
        std::cout<<"You're weapon is: "<<new_weapon<<std::endl;
        std::cout<<std::endl;
        std::cout<<"Enter the characteristic: "<<std::endl;
        std::cout<<"Enter damage (1-100): "<<std::endl;
        std::cin>>damage;
        std::cout<<"Enter breaking armor (1-100): "<<std::endl;
        std::cin>>breaking_armor;
        weapon_class_point = (damage + breaking_armor) / 2;
        if (weapon_class_point >= 0 && weapon_class_point <= 40){
            player_weapon_class = weapon_class = "Basic";
            std::cout<<"You're weapon have (" << weapon_class<<") level"<<std::endl;
        }else if(weapon_class_point > 40 && weapon_class_point <= 60){
            player_weapon_class = weapon_class = "Middle";
            std::cout<<"You're weapon have (" << weapon_class<<") level"<<std::endl;
        }else if(weapon_class_point > 60 && weapon_class_point <= 85){
            player_weapon_class = weapon_class = "High";
            std::cout<<"You're weapon have (" << weapon_class<<") level"<<std::endl;
        }else if(weapon_class_point > 85 && weapon_class_point <= 100){
            player_weapon_class =weapon_class = "Legendary";
            std::cout<<"You're weapon have (" << weapon_class<<") level"<<std::endl;
        }
    } else if(new_weapon == "Spear" ){
        int throw_range;
        std::cout<<"Enter the characteristic: "<<std::endl;
        std::cout<<"Enter damage (1-100): "<<std::endl;
        std::cin>>damage;
        std::cout<<"Enter breaking armor (1-100): "<<std::endl;
        std::cin>>breaking_armor;
        std::cout<<"Enter throw range (1-100): "<<std::endl;
        std::cin>>throw_range;
        weapon_class_point = (damage + breaking_armor + throw_range)/2.5;
        if (weapon_class_point >= 0 && weapon_class_point <= 40){
            player_weapon_class = weapon_class = "Basic";
            std::cout<<"You're weapon have (" << weapon_class<<") level"<<std::endl;
        }else if(weapon_class_point > 40 && weapon_class_point <= 60){
            player_weapon_class = weapon_class = "Middle";
            std::cout<<"You're weapon have (" << weapon_class<<") level"<<std::endl;
        }else if(weapon_class_point > 60 && weapon_class_point <= 85){
            player_weapon_class = weapon_class = "High";
            std::cout<<"You're weapon have (" << weapon_class<<") level"<<std::endl;
        }else if(weapon_class_point > 85 && weapon_class_point <= 100){
            player_weapon_class = weapon_class = "Legendary";
            std::cout<<"You're weapon have (" << weapon_class<<") level"<<std::endl;
        }
    } else if(new_weapon == "Bow"){
        double range_of_flight;
        int arrow_lethality;
        int arrow_damage;
        std::cout<<"Enter the characteristic: "<<std::endl;
        std::cout<<"Enter range of flight (1-100): "<<std::endl;
        std:: cin>>range_of_flight;
        std::cout<<"Enter arrow lethality (1-100): "<<std::endl;
        std::cin>>arrow_lethality;
        std::cout<<"Enter arrow damage (1-100): "<<std::endl;
        std::cin>>arrow_damage;
        weapon_class_point = (range_of_flight + arrow_damage + arrow_lethality)/2.5;
        if (weapon_class_point >= 0 && weapon_class_point <= 40){
            player_weapon_class = weapon_class = "Basic";
            std::cout<<"You're weapon have (" << weapon_class<<") level"<<std::endl;
        }else if(weapon_class_point > 40 && weapon_class_point <= 60){
            player_weapon_class = weapon_class = "Middle";
            std::cout<<"You're weapon have (" << weapon_class<<") level"<<std::endl;
        }else if(weapon_class_point > 60 && weapon_class_point <= 85){
            player_weapon_class = weapon_class = "High";
            std::cout<<"You're weapon have (" << weapon_class<<") level"<<std::endl;
        }else if(weapon_class_point > 85 && weapon_class_point <= 100){
            player_weapon_class = weapon_class = "Legendary";
            std::cout<<"You're weapon have (" << weapon_class<<") level"<<std::endl;
        }
    }else{
        std::cout<<"There is none weapon"<<std::endl<<std::endl;
    }

}

void Player::SetHealth(int new_health) {
    health = new_health;                    // this Вказує на поточний обʼєкт класу Player
}
bool Player::HealtBool() {
    if(health <= 0){
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
    std::cout<<std::endl;
}

