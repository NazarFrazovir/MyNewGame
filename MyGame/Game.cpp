//
// Created by Nazar Frazovir on 21.02.2024.
//

#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "Game.h"
#include <string>

Game::Game() {};

void Game::GameStart() {
    if (!Player::HealtBool()){
        std::cout<<"GAME OVER"<<std::endl;
    }else{
        std::cout<<"GAME CONTINUE"<<std::endl;
    }
}