//
// Created by Nazar Frazovir on 15.03.2024.
//

#include <iostream>

#ifndef MYGAME_INTERFACE_H
#define MYGAME_INTERFACE_H

class Interface{
    friend std::ostream &operator<<(std::ostream &os, const Interface &obj);
public:
    virtual void print(std::ostream & os)const = 0;
    virtual ~Interface();
};

#endif //MYGAME_INTERFACE_H
