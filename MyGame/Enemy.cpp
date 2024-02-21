//
// Created by Nazar Frazovir on 21.02.2024.
//
#include <iostream>
#include "Enemy.h"
#include <string>

void Enemy::Enemy_SetName(){
    std::string enemy_new_name;
    std::cout<<"Enter enemy name: "<<std::endl;
    getline(std::cin,enemy_new_name);
    this->enemy_name=enemy_new_name;
}
void Enemy::Enemy_Weapon(){

    std::string enemy_weapon [3] = {"Sword", "Bow", "Spear"};
    srand(time(NULL));
    int random = rand()%3;
    int random_weapon = rand()%100;
    int random_weapon2 = rand()&100;
    int random_weapon3 = rand()%100;
    int enemy_weapon_class_point;
    std::string enemy_weapon_class;
    std::cout<<"Enemy weapon ("<<enemy_weapon[random]<<")"<<std::endl;
    if (enemy_weapon[random] == "Sword" ){
        int enemy_damage = random_weapon;
        int enemy_breaking_armor = random_weapon2;
        std::cout<<"Enemy damage: ["<<enemy_damage<<"]"<<std::endl;
        std::cout<<"Enemy breaking armor: ["<<enemy_breaking_armor<<"]"<<std::endl;
        enemy_weapon_class_point = (enemy_damage + enemy_breaking_armor) / 2;
        if (enemy_weapon_class_point >= 20 && enemy_weapon_class_point <= 40){
            enemy_weapon_class = "Basic";
            std::cout<<"Enemy weapon have (" << enemy_weapon_class<<") level"<<std::endl;
        }else if(enemy_weapon_class_point > 40 && enemy_weapon_class_point <= 60){
            enemy_weapon_class = "Middle";
            std::cout<<"Enemy weapon have (" << enemy_weapon_class<<") level"<<std::endl;
        }else if(enemy_weapon_class_point > 60 && enemy_weapon_class_point <= 85){
            enemy_weapon_class = "High";
            std::cout<<"Enemy weapon have (" << enemy_weapon_class<<") level"<<std::endl;
        }else if(enemy_weapon_class_point > 85 && enemy_weapon_class_point <= 100){
            enemy_weapon_class = "Legendary";
            std::cout<<"Enemy weapon have (" << enemy_weapon_class<<") level"<<std::endl;
        }
    }else if(enemy_weapon[random] == "Bow"){
        int enemy_range_of_flight = random_weapon;
        int enemy_arrow_lethality = random_weapon2;
        int enemy_arrow_damage = random_weapon3;
        std::cout<<"Enemy range of flight: ["<<enemy_range_of_flight<<"]"<<std::endl;
        std::cout<<"Enemy arrow lethality: ["<<enemy_arrow_lethality<<"]"<<std::endl;
        std::cout<<"Enemy arrow damage: ["<<enemy_arrow_damage<<"]"<<std::endl;
        enemy_weapon_class_point = (enemy_arrow_lethality + enemy_arrow_damage + enemy_range_of_flight) / 2.5;
        if (enemy_weapon_class_point >= 20 && enemy_weapon_class_point <= 40){
            enemy_weapon_class = "Basic";
            std::cout<<"Enemy weapon have (" << enemy_weapon_class<<") level"<<std::endl;
        }else if(enemy_weapon_class_point > 40 && enemy_weapon_class_point <= 60){
            enemy_weapon_class = "Middle";
            std::cout<<"Enemy weapon have (" << enemy_weapon_class<<") level"<<std::endl;
        }else if(enemy_weapon_class_point > 60 && enemy_weapon_class_point <= 85){
            enemy_weapon_class = "High";
            std::cout<<"Enemy weapon have (" << enemy_weapon_class<<") level"<<std::endl;
        }else if(enemy_weapon_class_point > 85 && enemy_weapon_class_point <= 100){
            enemy_weapon_class = "Legendary";
            std::cout<<"Enemy weapon have (" << enemy_weapon_class<<") level"<<std::endl;
        }
    }else if(enemy_weapon[random] == "Spear"){
        int enemy_throw_range = random_weapon;
        int enemy_damage = random_weapon2;
        int enemy_breaking_armor = random_weapon3;
        std::cout<<"Enemy damage: ["<<enemy_damage<<"]"<<std::endl;
        std::cout<<"Enemy breaking armor: ["<<enemy_breaking_armor<<"]"<<std::endl;
        std::cout<<"Enemy throw range: ["<<enemy_throw_range<<"]"<<std::endl;
        enemy_weapon_class_point = (enemy_damage + enemy_breaking_armor + enemy_throw_range)/2.5;
        if (enemy_weapon_class_point >= 20 && enemy_weapon_class_point <= 40){
            enemy_weapon_class = "Basic";
            std::cout<<"Enemy weapon have (" << enemy_weapon_class<<") level"<<std::endl;
        }else if(enemy_weapon_class_point > 40 && enemy_weapon_class_point <= 60){
            enemy_weapon_class = "Middle";
            std::cout<<"Enemy weapon have (" << enemy_weapon_class<<") level"<<std::endl;
        }else if(enemy_weapon_class_point > 60 && enemy_weapon_class_point <= 85){
            enemy_weapon_class = "High";
            std::cout<<"Enemy weapon have (" << enemy_weapon_class<<") level"<<std::endl;
        }else if(enemy_weapon_class_point > 85 && enemy_weapon_class_point <= 100){
            enemy_weapon_class = "Legendary";
            std::cout<<"Enemy weapon have (" << enemy_weapon_class<<") level"<<std::endl;
        }
    }
}
void Enemy::Enemy_Stat() const{
    std::cout<<"Enemy name: "<<Enemy::enemy_name<<std::endl;
    std::cout<<"Health: "<<Enemy::enemy_health<<std::endl;
    std::cout<<"Armor: "<<Enemy::enemy_armor<<std::endl;
}