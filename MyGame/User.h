//
// Created by Nazar Frazovir on 21.03.2024.
//

#ifndef MYGAME_USER_H
#define MYGAME_USER_H
#include <iostream>
#include "Console.h"
#include "Character/Player.h"
#include "Character/SwordMan.h"
#include "Character/Archer.h"

#include "Item/Inventory.h"

class User: public Inventory{
private:
    User(std::vector<std::unique_ptr<User>> vector1);

    std::string name;
    int password;
    bool isAdmin;
    std::vector<std::unique_ptr<User>> users;
    std::vector<std::unique_ptr<User>> characters;
    int health;
    int armor;


public:

    User();
    User(const std::string& name);
    User(User* userptr);
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
