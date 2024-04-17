//
// Created by Nazar Frazovir on 21.03.2024.
//

#ifndef MYGAME_USER_H
#define MYGAME_USER_H
#include "Character.h"
#include <iostream>
#include "Player.h"
#include "../UnnecessaryClasses/SwordMan.h"
#include "../UnnecessaryClasses/Archer.h"
#include "../Item/Inventory.h"
#include "WhiteSide/Elf.h"


class User: public Inventory{
private:
    std::string name;
    int password;
    bool isAdmin;
    std::vector<User> users;
    std::vector<std::shared_ptr<Characters>> characters;

public:
    User();
    User(const std::string& name);
    User(const User& other);
    User(std::string name,int password);
    User(std::unique_ptr<User> uniqueCharacter);
    ~User();

//    virtual void console() override;
    bool auditIfAdmin();
     void createCharacter();
     void removeUserByName();
    void saveCharacter();
    void loadCharacter();
    void createUser();
    void saveAllUsersToFile();
    void loadUserFromFile();
    void userConsole();
    void templateForUserConsole();
    void templateForAdminConsole();


    //Info
    void infoAboutGame();
    void infoAboutRace();
    void infoAboutWorldAndCountry();


};
#endif //MYGAME_USER_H
