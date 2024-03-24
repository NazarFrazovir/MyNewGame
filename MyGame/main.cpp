#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "Game.h"
#include "SwordMan.h"
#include "Spell.h"
#include "Archer.h"
#include "EnemySwordMan.h"
#include "User.h"


 void onShowStatHealthAndArmor(Player& player){
    player.showStatHealthAndArmor();
}                                         // Base class reference
void displayInfoOnUI(const Player& player)  {
    std::cout<<"---------------------------------------------"<<std::endl;
    player.display();
    std::cout<<"---------------------------------------------"<<std::endl;
}
void InterfaceForAll(Interface& obj){
    std::cout<<obj;                 // Interface
}

bool isAdmin(User& user){
    if(user.auditIfAdmin()){
        std::cout<<"You're Admin "<<std::endl;
        return true;
    }else{
        std::cout<<"You're not Admin "<<std::endl;
        return false;
    }
}

void Console(User& user) {
    if (isAdmin(user)){
        std::cout<<"              Admin Console:           "<<std::endl;
        std::cout<<"(1) Create a character "<<std::endl;
        std::cout<<"(2) Delete character"<<std::endl;
        std::cout<<"(3) Create enemy"<<std::endl;
        std::cout<<"(4) Show all character"<<std::endl;
        std::cout<<"(5) Exit Menu "<<std::endl;
        std::cout<<std::endl;
        int k;
        switch (k) {
            case 1:

                break;
            case 2:

                break;

            case 3:

                break;

            case 4:

                break;
            case 5:

                break;

            default:
                std::cout<<"You entered non availed item. BYE "<<std::endl;
                exit(1);
                break;

        }
    }else{
        std::cout<<"            Console game:           "<<std::endl;
        std::cout<<"(1) Create a character "<<std::endl;
        std::cout<<"(2) Open inventory "<<std::endl;
        std::cout<<"(3) Fight "<<std::endl;
        std::cout<<"(4) Display "<<std::endl;
        std::cout<<"(5) Exit game "<<std::endl;
        std::cout<<std::endl;

        int k;
        std::cout<<"Select menu item: "<<std::endl;
        std::cin>>k;
        SwordMan sw;
        Archer ar;

        Player& player = reinterpret_cast<Player &>(user);      // оператор Переведення для вказівників, для найбільш небезпечного переведення
        switch (k) {
            case 1:
                user.createACharacter(sw,ar);
                break;
            case 2:

                break;

            case 3:

                break;

            case 4:
                displayInfoOnUI(player);
                break;
            case 5:

                break;

            default:
                std::cout<<"You entered non availed item. BYE "<<std::endl;
                exit(1);
                break;

        }

    }
    }


int main() {


    SwordMan sw1;
    Player& player1 = sw1;
    Console((User&)player1);

    return 0;
};