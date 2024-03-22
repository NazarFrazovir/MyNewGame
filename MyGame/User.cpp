//
// Created by Nazar Frazovir on 21.03.2024.
//
#include <iostream>
#include "User.h"
#include "Player.h"
#include "SwordMan.h"
#include "Archer.h"


User::User()
:name("None"),password(0),isAdmin(0){}
User::User(std::string name, int password)
:name(name),password(password),isAdmin(0){}
User::~User(){}

bool User::auditIfAdmin() {
    int newPassword;
    if (newPassword = password){
        isAdmin = true;
        return true;
    } else{
        isAdmin = false;
        return false;
    }
}



 void User::createACharacter(SwordMan& swordMan, Archer& archer) {
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
            swordMan.setStat();
            break;
        case 2:
            archer.setStat();
            break;
        default:
            std::cout<<"Enough type of character "<<std::endl;
            break;
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