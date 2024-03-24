//
// Created by Nazar Frazovir on 21.03.2024.
//
#include <iostream>
#include "User.h"
#include "Player.h"
#include "SwordMan.h"
#include "Archer.h"


//User::User()
//:name("None"),password(0),isAdmin(0){}
User::User(std::string name, int password,bool isAdmin)
:name(name),password(password),isAdmin(isAdmin){}
User::~User(){}

bool User::auditIfAdmin() {
    int newPassword;
    password = 1234;
    int choice;
    std::cout<<"Hello, You're are admin? (1) - Yes.    (2) - No "<<std::endl;
    std::cin>>choice;
    if (choice == 1){
        std::cout<<"Enter password: "<<std::endl;
        std::cin>>newPassword;
        if (newPassword == password){
            return true;
        } else{
            return false;
        }
    }else if (choice == 2){
        return false;
    }else{
        std::cout<<"You entered incorrect number "<<std::endl;
    }
}



 void User::createACharacter(Player& player,Player& player2) {
    std::cout<<" Create a character: "<<std::endl;
    std::cout<<std::endl;
    int change;
    std::cout<<" Type of character: "<<std::endl;
    std::cout<<"(1) Sword Man "<<std::endl;
    std::cout<<"(2) Archer "<<std::endl;
    std::cout<<"Enter type of character: "<<std::endl;
    std::cin>>change;
    switch (change) {
        case 1:
            player.setStat();
            break;
        case 2:
            player2.setStat();
            break;
        default:
            std::cout<<"Enough type of character "<<std::endl;
            break;
    }
}

void User::Inventory(const std::vector<std::string>& item) {
    if (item.empty()){
        std::cout<<"You're inventory is empty. "<<std::endl;
    }else{
        std::cout<<"Inventory: "<<std::endl;
        for(const std::string& items : item) {
            std::cout<<"-["<<items<<"]"<<std::endl;
        }
    }
}

//void User::console() {
//    std::cout<<"            Console game:           "<<std::endl;
//    std::cout<<"(1) Create a character "<<std::endl;
//    std::cout<<"(2) Open inventory "<<std::endl;
//    std::cout<<"(3) Fight "<<std::endl;
//    std::cout<<"(4) Exit game "<<std::endl;
//    std::cout<<std::endl;
//
//
//    int k;
//
//    std::cout<<"Select menu item: "<<std::endl;
//    std::cin>>k;
//
//    switch (k) {
//        case 1:
//        User::createACharacter();
//            break;
//        case 2:
//
//            break;
//
//        case 3:
//
//            break;
//
//        case 4:
//
//            break;
//
//        default:
//            std::cout<<"You entered non availed item. BYE "<<std::endl;
//
//    }
//
//}