//
// Created by Nazar Frazovir on 25.03.2024.
//
#include "Object.h"
#include <iostream>

Object::Object(std::string name, int weight)
:name(name),weight(weight){}

Object::Object()
:name(""),weight(0){}
