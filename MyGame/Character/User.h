//
// Created by Nazar Frazovir on 21.03.2024.
//

#ifndef MYGAME_USER_H
#define MYGAME_USER_H
#include <iostream>
#include "../Console.h"
#include "Player.h"
#include "SwordMan.h"
#include "Archer.h"
#include "Character.h"
#include "../Item/Inventory.h"

class User: public Inventory{
private:
//    User(std::vector<std::unique_ptr<User>> vector1);

    std::string name;
    int password;
    bool isAdmin;
    std::vector<std::unique_ptr<User>> users;
//    std::vector<std::unique_ptr<User>> characters;
        std::vector<std::unique_ptr<Character>> characters;
    int health;
    int armor;


public:

    User();
    User(const std::string& name);
//    User(User* userptr);
    User(std::string,int,int);
    User(std::unique_ptr<User> uniqueCharacter);
//    User(std::string name,int password, bool isAdmin);
    ~User();

//    virtual void console() override;
    bool auditIfAdmin();
     void createCharacter();
     void createUser();
     void saveAllUsersToFile();
     void loadUserFromFile();
     void removeUserByName();
    void saveCharacter();
    void loadCharacter();
};
#endif //MYGAME_USER_H
