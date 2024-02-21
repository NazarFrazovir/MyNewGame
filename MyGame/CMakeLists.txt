cmake_minimum_required(VERSION 3.26)
project(MyGame)

set(CMAKE_CXX_STANDARD 17)

add_executable(MyGame main.cpp
        Player.h
        Game.h
        Enemy.h
        Player.cpp
        Enemy.cpp
        Game.cpp)
