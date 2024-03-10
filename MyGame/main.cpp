#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "Game.h"
#include "SwordMan.h"
#include "Spell.h"
#include "Archer.h"
#include "EnemySwordMan.h"

 void onShowStatHealthAndArmor(Player& player){
    player.showStatHealthAndArmor();
}                                         // Base class reference

void displayInfoOnUI(const Player& player)  {
    std::cout<<"---------------------------------------------"<<std::endl;
    player.display();
    std::cout<<"---------------------------------------------"<<std::endl;
}                               // Static method binding
int main() {


    SwordMan swordman0;
    swordman0.setName("Nazar");
    swordman0.setHealth(100);
    swordman0.setMobility(27);                  // Static method binding
    swordman0.setPrecision(150);
    displayInfoOnUI(swordman0);


Player* swordman2 = new SwordMan();

    swordman2->setName("Tolik");
    swordman2->setArmor(400);

                                                // Base class pointer
    swordman2->display();

    swordman2->representation(* swordman2);             // Interface

    delete swordman2;

    SwordMan swordman3;
    swordman3.setName("George");
    swordman3.setHealth(100);
    swordman3.setArmor(100);

    Archer archer1;
    archer1.setName("Danilo");
    archer1.setHealth(200);


    //Create reference in base class            // Base class reference
    Player& player1 = swordman3;
    Player& player2 = archer1;

    // We call function base class reference
    onShowStatHealthAndArmor(player1);


    // We call virtual methods
    player1.display();
    player2.display();
    player2.representation(player2);    //Interface



    SwordMan swordnam4;

    swordnam4.setName("Geralt");
    swordnam4.makeSound();
                                                        // Pure virtual function
    Archer archer2;
    archer2.setName("Cirrila");
    archer2.makeSound();




    return 0;
}
