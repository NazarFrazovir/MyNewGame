//
// Created by Nazar Frazovir on 21.02.2024.
//

#ifndef MYGAME_GAME_H
#define MYGAME_GAME_H
#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include <string>

class Game {
private:
    bool game_over;

public:
    Game();

    static void GameStart();
};
#endif //MYGAME_GAME_H
