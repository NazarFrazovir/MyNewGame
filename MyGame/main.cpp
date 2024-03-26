#include <iostream>
#include "Character/Player.h"
#include "Enemy.h"
#include "Game.h"
#include "Character/SwordMan.h"
#include "Item/Spell.h"
#include "Character/Archer.h"
#include "EnemySwordMan.h"
#include "User.h"

#include "Item/Inventory.h"


 void onShowStatHealthAndArmor(Player& player){
    player.showStatHealthAndArmor();
}                                         // Base class reference
void displayInfoOnUI(Player& player)  {
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

void adminConsole(User& user){
    std::cout<<"              Admin Console:           "<<std::endl;
    std::cout<<"(1) Add user "<<std::endl;
    std::cout<<"(2) Delete user"<<std::endl;
    std::cout<<"(3) Setting Inventory "<<std::endl;
    std::cout<<"(4) Save User in File "<<std::endl;
    std::cout<<"(5) Show Users "<<std::endl;
    std::cout<<"(6) Exit Menu "<<std::endl;
    std::cout<<std::endl;
    int k;
    do{
        std::cout<<"Select menu item: "<<std::endl;
        std::cin>>k;
        switch (k) {
            case 1:
                user.createUser();
                break;
            case 2:
                user.removeUserByName();
                break;

            case 3:
                user.inventoryForAdmin();
                break;

            case 4:
                user.saveAllUsersToFile();
                break;
            case 5:
                user.loadUserFromFile();
                break;
            case 6:
                std::cout<<"        BYE         "<<std::endl;
                break;
            default:
                std::cerr<<"You entered non availed item. BYE "<<std::endl;
                break;
        }
    }while(k!=6);
}

void userConsole(User& user){
    std::cout << "            Console game:           " << std::endl;
    std::cout << "(1) Create a character " << std::endl;
    std::cout << "(2) Open inventory " << std::endl;
    std::cout << "(3) Save character " << std::endl;
    std::cout << "(4) Load character " << std::endl;
    std::cout << "(5) Exit game " << std::endl;
    std::cout << std::endl;

    int k;


    do {
        std::cout << "Select menu item: " << std::endl;
        std::cin >> k;
        switch (k) {
            case 1:
                user.createCharacter();
                break;
            case 2:
                user.inventoryForUser();
                break;

            case 3:
                user.saveCharacter();
                break;
            case 4:
                user.loadCharacter();
                break;
            case 5:
                std::cout<<"            BYE             "<<std::endl;
                exit(1);
            default:
                std::cerr << "You entered non availed item. BYE " << std::endl;
                exit(1);

        }

    } while (k != 5);
}

void Console(User& user) {
    if (isAdmin(user)){
        adminConsole(user);
    }else {
        userConsole(user);
    }
}
int main() {


    User user1;
    Console(user1);

//Inventory in1;
//
//    in1.inventoryForAdmin();

//in1.inventoryForUser();

    return 0;
};