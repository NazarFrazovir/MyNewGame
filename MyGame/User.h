//
// Created by Nazar Frazovir on 21.03.2024.
//

#ifndef MYGAME_USER_H
#define MYGAME_USER_H
#include <iostream>
#include "Console.h"
#include "Player.h"
#include "SwordMan.h"
#include "Archer.h"

class User: public Console{
private:
    std::string name;
    int password;
    bool isAdmin;

public:

    User();
    User(std::string name,int password, bool isAdmin);
    ~User();

//    virtual void console() override;
    bool auditIfAdmin();
     void createACharacter(Player& player,Player& player2);
    static void Inventory(const std::vector<std::string>& item);
};
#endif //MYGAME_USER_H
