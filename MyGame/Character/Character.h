//
// Created by Nazar Frazovir on 26.03.2024.
//

#ifndef MYGAME_CHARACTER_H
#define MYGAME_CHARACTER_H
#include "User.h"
#include <iostream>
class Character{
public:
    std::vector<std::unique_ptr<Character>> characters;
    std::string charName;
    int charHealth;
    int charArmor;

    Character()
    :charName(""),charHealth(0),charArmor(0){}
    Character(std::string charName,int charHealth,int charArmor)
    :charName(charName),charHealth(charHealth),charArmor(charArmor){}
};


#endif //MYGAME_CHARACTER_H
