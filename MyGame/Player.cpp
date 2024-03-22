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
        :Player{new_name,new_health > 0 ? new_health : 0,0,0}{}

Player::Player(std::string new_name, int new_health, int new_armor)
        :Player{new_name,new_health > 0 ? new_health : 0,new_armor > 0 ? new_armor : 0
                ,0}{}

Player::Player(std::string new_name, int new_health, int new_armor, int new_xp)
        :name{new_name},armor{new_armor},xp{new_xp}{health=new_health > 0 ? new_health : 0;}

Player& Player::operator=(const Player &other){
        if (this != &other) {
            this->armor = other.armor;
            this->name = other.name;
            this->health = other.health;
        }
        return *this;
    }

Player& Player::operator-() {
    armor = -armor;              // Add unary operator - Для критичного удара по броні.
    return *this;
}


Player::~Player() {}


void Player::setHealth() {
    int new_health;
    std::cout<<"Enter Health: "<<std::endl;
    std::cin>>new_health;
    try {
        if (new_health < 0 || new_health > 100) {
            throw 0;
            health = new_health;                     // Exception
        }
    }catch (int &ex){
        std::cerr<<"Health can't be < 0 and can't be > 100 "<<std::endl;
        exit(1);
    }
}

void Player::weapons(){
    std::string weapon_class;
    double weapon_class_point;
    int damage;
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
        static_cast<double>(weapon_class_point = (damage + breaking_armor)) / 2;        //excaption
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
        static_cast<double>(weapon_class_point = (damage + breaking_armor + throw_range))/2.5;
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
        int range_of_flight;
        int arrow_lethality;
        int arrow_damage;
        std::cout<<"Enter the characteristic: "<<std::endl;
        std::cout<<"Enter range of flight (1-100): "<<std::endl;
        std:: cin>>range_of_flight;
        std::cout<<"Enter arrow lethality (1-100): "<<std::endl;
        std::cin>>arrow_lethality;
        std::cout<<"Enter arrow damage (1-100): "<<std::endl;
        std::cin>>arrow_damage;
        static_cast<double>(weapon_class_point = (range_of_flight + arrow_damage + arrow_lethality))/2.5;
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

bool Player::healtBool() {
    if(health<= 0){
        return false;
    }else{
        return true;
    }
}



void Player::setName(){
    std::string new_name;
    std::cout<<"Enter name: "<<std::endl;
    std::cin>>new_name;
    try {
        if (new_name < "") {
            throw 0;
            this-> name = new_name;                     // Exception
        }
    }catch (int &ex){
        std::cerr<<"Name can't be empty"<<std::endl;
        exit(1);
    }
}
void Player::setStat() {
    Player::setName();
    Player::setHealth();
    Player::setArmor();
}

void Player::setArmor() {
    int new_armor;
    std::cout<<"Enter Armor: "<<std::endl;
    std::cin>>new_armor;
    try {
        if (new_armor < 0|| new_armor > 100) {
            throw 0;
            this->armor = new_armor;                     // Exception
        }
    }catch (int &ex){
        std::cerr<<"Armor can't be < 0 and can't be > 100 "<<std::endl;
        exit(1);
    }


}

void Player::display() const {
    std::cout<<"       Player Information: "<<std::endl;
    std::cout<<"Name: "<<name<<std::endl;
    std::cout<<"Health: "<<health<<std::endl;
    std::cout<<"Armor: "<<armor<<std::endl;
    std::cout<<std::endl;
}

void Player::showStatHealthAndArmor() {
    std::cout<<"You're health: ["<<health<<"] "<<std::endl;
    std::cout<<"You're armor: ["<<armor<<"] "<<std::endl;
    std::cout<<std::endl;
}
void Player::print(std::ostream &os) const {
    os<<"Interface for Player: "<<std::endl;
    os<< "My name: "<<name<<std::endl<<"Health: "<<health<<std::endl
       <<"Armor: "<<armor<<std::endl;
    os<< std::endl;
}





