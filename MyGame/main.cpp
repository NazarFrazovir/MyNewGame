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
// Static method binding

void InterfaceForAll(Interface& obj){
    std::cout<<obj;                 // Interface
}

void Console(User& user) {
    std::cout<<"            Console game:           "<<std::endl;
    std::cout<<"(1) Create a character "<<std::endl;
    std::cout<<"(2) Open inventory "<<std::endl;
    std::cout<<"(3) Fight "<<std::endl;
    std::cout<<"(4) Exit game "<<std::endl;
    std::cout<<std::endl;
    int k;
    std::cout<<"Select menu item: "<<std::endl;
    std::cin>>k;
    SwordMan sw;
    Archer ar;
    switch (k) {
        case 1:
            user.createACharacter(sw,ar);
            break;
        case 2:

            break;

        case 3:

            break;

        case 4:

            break;

        default:
            std::cout<<"You entered non availed item. BYE "<<std::endl;

    }

}
int main() {


    SwordMan sw1;
    Player& player1 = sw1;
    Console((User&)sw1);
    sw1.display();
//
//    SwordMan swordman0;
//    swordman0.setName("Nazar");
//    swordman0.setHealth(100);
//    swordman0.setMobility(27);                  // Static method binding
//    swordman0.setPrecision(150);
//    displayInfoOnUI(swordman0);
//
//    Archer archer0;
//
//    archer0.setName("Dima");
//    archer0.setDamageArrows(100);
//    archer0.setArmor(100);
//    archer0.setHealth(100);
//    displayInfoOnUI(archer0);
//
//
//Player* swordman2 = new SwordMan();
//
//    swordman2->setName("Tolik");
//    swordman2->setArmor(400);
//                                                            // Base class pointer
//    displayInfoOnUI(*swordman2);
//
//    std::cout<<*swordman2<<std::endl;
//
//    displayInfoOnUI(*swordman2);                 // Interface
//
//    delete swordman2;
//
//
//
//    SwordMan swordman3;
//    swordman3.setName("George");
//    swordman3.setHealth(100);
//    swordman3.setArmor(100);
//
//    Archer archer1;
//    archer1.setName("Danilo");
//    archer1.setHealth(200);
//
//
//    // Base class reference
//    Player& player1 = swordman3;
//    Player& player2 = archer1;

//
//    player1.display();
//    player2.display();
//    displayInfoOnUI(player1);
//
//    onShowStatHealthAndArmor(player1);
//
//    InterfaceForAll(player2);  //Interface
//
//
//
//    SwordMan swordnam4;
//
//    swordnam4.setName("Geralt");
//    swordnam4.makeSound();
//                                                        // Pure virtual function
//    Archer archer2;
//    archer2.setName("Cirrila");
//    archer2.makeSound();

    return 0;
};