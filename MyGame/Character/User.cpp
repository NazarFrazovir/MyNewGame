//
// Created by Nazar Frazovir on 21.03.2024.
//
#include <iostream>
#include "User.h"
#include "Player.h"
#include "../UnnecessaryClasses/SwordMan.h"
#include "../UnnecessaryClasses/Archer.h"
#include "Character.h"
#include "WhiteSide/Dwarf.h"
#include "DarkSide/DarkSide.h"
#include "DarkSide/Orc.h"
#include "DarkSide/Goblin.h"

User::User()
:name("None"){}
User::User(const std::string &name)
:name(name){}
User::User(const User &other)
:name(other.name),password(other.password){}
User::User(std::string name,int password)
:name(name),password(password){}
User::User(std::unique_ptr<User> uniqueCharacter) {}
User::~User(){}

void User::userConsole(){
    templateForUserConsole();
    int k;

    do {
        std::cout << "Select menu item: " << std::endl;
        std::cin >> k;
        switch (k) {
            case 1:
                createCharacter();
                break;
            case 2:
                inventoryForUser();
                break;
            case 3:
                saveCharacter();
                break;
            case 4:
                loadCharacter();
                break;
            case 5:
                infoAboutGame();
                break;
            case 6:
                std::cout<<"            BYE             "<<std::endl;
                exit(1);
            default:
                std::cerr << "You entered non availed item " << std::endl;
                userConsole();
                break;
        }

    } while (k != 5);
}

bool User::auditIfAdmin() {
    int newPassword;
    password = 1234;
    int choice;
    std::cout << "Hello, Are you an admin? (1) - Yes.    (2) - No " << std::endl;
    try {
        if (!(std::cin >> choice)) {
            std::cerr << "Invalid input. Please enter a number." << std::endl;
            std::exit(1);
        }

        if (choice == 1) {
            std::cout << "Enter password: " << std::endl;
            if (!(std::cin >> newPassword)) {
                std::cerr << "Invalid input Please enter number." << std::endl;
                std::exit(1);
            }
            if (newPassword == password) {
                std::cout << "You're admin. Welcome" << std::endl;
                return true;
            } else {
                std::cout << "Incorrect password. You're not admin." << std::endl;
                return false;
            }
        } else if (choice == 2) {
            std::cout << "You're a user. Welcome" << std::endl;
            return false;
        } else {
            std::cerr << "Enter 1 or 2." << std::endl;
            std::exit(1);
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        std::exit(1);
    }
}


//void User::createACharacter(SwordMan& swordMan,Archer& archer) {
//    std::cout<<" Create a character: "<<std::endl;
//    std::cout<<std::endl;
//    int change;
//    std::cout<<" Type of character: "<<std::endl;
//    std::cout<<"(1) Sword Man "<<std::endl;
//    std::cout<<"(2) Archer "<<std::endl;
//    std::cout<<"Enter type of character: "<<std::endl;
//    std::cin>>change;
//    switch (change) {
//        case 1:
//            swordMan.setStat();
//            break;
//        case 2:
//            archer.setStat();
//            break;
//        default:
//            std::cout<<"Enough type of character "<<std::endl;
//            break;
//    }
//}

void User::createUser() {

    std::string name;
    std::cout << "Enter username: ";
    std::cin >> std::ws;
    std::getline(std::cin, name);
    users.emplace_back(name);      // таяк пуш бек, лиш без копіювання або переміщення
    std::cout<<std::endl;
    std::cout<<"--------------"<<std::endl;
    std::cout<<"User Created."<<std::endl;\
    std::cout<<"--------------"<<std::endl;
    std::cout<<std::endl;
    templateForAdminConsole();
}

void User::saveAllUsersToFile() {
    std::string filename = "User.txt";
    std::ofstream file(filename,std::ios_base::app); //відкриття файлу у режимі запису

    if (!file.is_open()) {
        std::cerr << "Failed to open file for writing: " << filename << std::endl;
        return;
    }

    for (const auto& user : users) {
        file << "Username: " << user.name << std::endl;
        }file.close();
    std::cout<<"--------------------"<<std::endl;
    std::cout<<"User saved in File. "<<std::endl;
    std::cout<<"--------------------"<<std::endl;
templateForAdminConsole();
    users.clear();
    }

void User::loadUserFromFile() {
    std::string filename = "User.txt";
    std::ifstream file(filename,std::ios_base::in);

    if(!file.is_open()){
        std::cerr<<"File not open "<<std::endl;
    }
    char symbol;
    std::cout<<"---------------------------------------"<<std::endl;
    while (file.get(symbol)){
        std::cout<<symbol;
    }
    std::cout<<"---------------------------------------"<<std::endl;
    templateForAdminConsole();
}

void User::removeUserByName() {
    std::string userName;
    std::cout << "Enter name of User to remove: " << std::endl;
    std::cin >> std::ws;
    std::getline(std::cin,userName);

    std::string filename = "User.txt";
    std::ifstream file(filename);

    if (!file.is_open()){
        std::cerr << "File not open" << std::endl;
        return;
    }

    std::string line;
    std::vector<std::string> userContent;
    bool userFound = false;

    while (std::getline(file, line)){
        if (line.find(userName) == std::string::npos) { // Якщо імʼя не співпадає
            userContent.push_back(line);
        } else {
            userFound = true;
        }
    }
    file.close();

    if (!userFound) {
        std::cout<<"----------------------"<<std::endl;
        std::cout << "No such user found." << std::endl;
        std::cout<<"----------------------"<<std::endl;
        templateForUserConsole();
        std::cin.ignore();
        return;
    }

    std::ofstream outFile(filename); // Перезаписуєм файл
    for(auto& content : userContent){
        outFile << content << std::endl;
    }
    outFile.close();
    std::cout<<"------------------------------------------------"<<std::endl;
    std::cout << "User [" << userName << "] removed from File." << std::endl;
    std::cout<<"------------------------------------------------"<<std::endl;
    templateForAdminConsole();
}


void User::createCharacter() {
/*    std::string race;
//    std::cout << "Enter race (Dwarf, Elf): ";
//    std::cin >> race;
//
//    if (race == "Dwarf") {
//
//        auto dwarf = std::make_shared<Dwarf>();
//        dwarf->charRace = "Dwarf";
//        std::cout<<"Enter name: "<<std::endl;
//        std::cin>>dwarf->charName;
//        characters.push_back(dwarf);
//
//    }else if(race == "Elf"){
//        auto elf = std::make_shared<Elf>();
//        elf->charRace = "Elf";
//        std::cout<<"Enter name: "<<std::endl;
//        std::cin>>elf->charName;
//        characters.push_back(elf);
//    }
//    else {
//        std::cerr<<"There is no such race"<<std::endl;
//    }
//    templateForUserConsole();
*/          // Old code

std::string side;
std::string race;
std::cout<<"Enter you're side (Dark) (Light): ";
std::cin>>side;

    if (side == "Dark"){
        std::cout<<"Enter you're race (Orc) (Goblin) ";
        std::cin>>race;
        if (race == "Orc"){
            auto orc = std::make_shared<Orc>();
            orc->charRace = "Orc";
            std::cout<<"Enter you're name: "<<std::endl;
            std::cin>>std::ws;
            getline(std::cin,orc->charName);

            characters.push_back(orc);
        }else if(race == "Goblin"){
            auto goblin = std::make_shared<Goblin>();
            goblin->charRace = "Goblin";
            std::cout<<"Enter you're name: "<<std::endl;
            std::cin>>std::ws;
            getline(std::cin,goblin->charName);
            characters.push_back(goblin);
        }else{
            std::cerr<<"There is no such race"<<std::endl;
        }
    } else if(side == "Light"){
            std::cout << "Enter race (Dwarf, Elf): ";
            std::cin >> race;

    if (race == "Dwarf") {

        auto dwarf = std::make_shared<Dwarf>();
        dwarf->charRace = "Dwarf";
        std::cout<<"Enter name: "<<std::endl;
        std::cin>>std::ws;
        getline(std::cin,dwarf->charName);
        characters.push_back(dwarf);

    }else if(race == "Elf"){
        auto elf = std::make_shared<Elf>();
        elf->charRace = "Elf";
        std::cout<<"Enter name: "<<std::endl;
        std::cin>>std::ws;
        getline(std::cin,elf->charName);
        characters.push_back(elf);
    }else {

        std::cerr<<"There is no such race"<<std::endl;
       }

    }else{std::cout<<"There is no such side, please retry "<<std::endl;}
    templateForUserConsole();
}



void User::saveCharacter(){
    std::string filename = "Character.txt";
    std::ofstream file(filename,std::ios_base::app); //відкриття файлу у режимі запису

    if (!file.is_open()) {
        std::cerr << "Failed to open file for writing: " << filename << std::endl;
        return;
    }

    for (const auto& character : characters) {
        if (auto charPtr = character.get()) { // Отримання вказівника на об'єкт Characters
            file << "Name: " << charPtr->charName << " Race: " << charPtr->charRace
                 << " Health: " << charPtr->charHealth << " Armor: " << charPtr->charArmor
                 << std::endl;
        }

    }
    file.close();
    std::cout<<"-----------------"<<std::endl;
    std::cout<<"Character saved. "<<std::endl;
    std::cout<<"-----------------"<<std::endl;

    characters.clear();
    templateForUserConsole();
}



void User::loadCharacter() {
    std::string filename = "Character.txt";
    std::ifstream file(filename,std::ios_base::in);

    if(!file.is_open()){
        std::cerr<<"File not open "<<std::endl;
    }
    char symbol;
    while (file.get(symbol)){
        std::cout<<symbol;
    }
    file.close();
    templateForUserConsole();
}



void User::templateForAdminConsole() {
    std::cout<<std::endl;
    std::cout << "        Admin Console:  " << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << "(1) Add user" << std::endl;
    std::cout << "(2) Delete user" << std::endl;
    std::cout << "(3) Setting Inventory" << std::endl;
    std::cout << "(4) Save User in File" << std::endl;
    std::cout << "(5) Show Users" << std::endl;
    std::cout << "(6) Exit Menu" << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << std::endl;
}

void User::templateForUserConsole() {

    std::cout << "            Console game:           " << std::endl;
    std::cout<<"-----------------------------------"<<std::endl;
    std::cout << "(1) Create a character " << std::endl;
    std::cout << "(2) Open inventory " << std::endl;
    std::cout << "(3) Save character " << std::endl;
    std::cout << "(4) Load character " << std::endl;
    std::cout<<  "(5) Info "<<std::endl;
    std::cout << "(6) Exit game " << std::endl;
    std::cout<<"-----------------------------------"<<std::endl;
    std::cout<<std::endl;

}



//Info

void User::infoAboutWorldAndCountry() {
    std::cout<<"----------------------------------------"<<std::endl;
    std::cout<<"            INFO ABOUT WORLD            "<<std::endl;
    std::cout<<"----------------------------------------"<<std::endl;
std::cout<<std::endl;

    std::cout<<"---------------------World------------------"<<std::endl;
    std::cout<<" Erión: A big world where various civilizations exist, mysteries of ancient ruins, "
               "and magnificent natural landscapes."<<std::endl;
    std::cout<<"--------------------------------------------"<<std::endl;
    std::cout<<"--------------------Country-----------------"<<std::endl;
    std::cout<<"(1) Lindaria Empire: This is a large empire consisting of various provinces and has many different cultural influences. "
               "It's a place where humans, elves, and other races share cities and trade routes, "
               "but there are also tense relations between them."<<std::endl;
    std::cout<<std::endl;
    std::cout<<"(2) Eldrilion Kingdom: This ancient kingdom where elves are considered the most influential race. "
               "They live in vast forests and have highly developed magic and culture."<<std::endl;
    std::cout<<std::endl;
    std::cout<<"(3) Gnomish Forge: Gnomes are known for their skill in blacksmithing and technologies. "
               "Their state is located in the large mountainous regions where they extract metals and "
               "develop new technologies."<<std::endl;
    std::cout<<std::endl;
    std::cout<<"(4) Orcish Wasteland: Orcs live in a harsh desert environment where they wage wars for resources"
               " and territories. They have huge fortress cities where strict laws of war prevail."<<std::endl;
    std::cout<<std::endl;
    std::cout<<"(5) Goblin Territories: Goblins are considered bandits and mercenaries, living in dense forests or caves. "
               "Their settlements are often underground and well-protected from enemies."<<std::endl;
    std::cout<<"--------------------------------------------"<<std::endl;
    std::cout<<std::endl;

    infoAboutGame();
}

void User::infoAboutRace() {
    std::cout<<"----------------------------------------"<<std::endl;
    std::cout<<"            INFO ABOUT RACE            "<<std::endl;
    std::cout<<"----------------------------------------"<<std::endl;
    std::cout<<std::endl;


    std::cout<<"(1) Emperor"<<std::endl;
    std::cout<<"(2) Elves"<<std::endl;
    std::cout<<"(3) Gnomes"<<std::endl;
    std::cout<<"(4) Orcs"<<std::endl;
    std::cout<<"(5) Goblins"<<std::endl;
    std::cout<<"(6) Exit"<<std::endl;
    int c;
    std::cin>>c;
    switch (c) {
        case 1:
            std::cout<<"1. **Emepror**:\n"
                       "  \tHumans of the Lindarian Empire descend from ancient colonizers who settled these lands many centuries ago.\n "
                       "Their history is filled with struggles for power and influence, but also with a desire for peace and prosperity.\n"
                       " They have founded great cities, fostering trade and cultural exchange among different races."<<std::endl;
            std::cout<<std::endl;

            std::cout<<"-----------------------"<<std::endl;
            std::cout<<"        WEAPON:"<<std::endl;
            std::cout<<"-----------------------"<<std::endl;
            std::cout<<"(Imperial Sword): This sword is crafted from high-quality steel and boasts an exquisite design.\n"
                       " Its wielders, the Imperial warriors, possess great skill in the art of combat. \n"
                       "The sword may be adorned with special enchantments or gilding, enhancing its strength and effectiveness."<<std::endl;
            std::cout<<std::endl;

            break;
        case 2:
            std::cout<<"2. **Elves**:\n"
                       " \tInhabitants of the Eldrilion Kingdom are considered ancient and wise guardians of nature.\n"
                       " Their history is intertwined with vast forests, where they flourished, adhering to ancient traditions"
                       " and magical knowledge.\n"
                       " They advocate for the preservation of nature and harmony with the surrounding world."<<std::endl;
            std::cout<<std::endl;

            std::cout<<"-----------------------"<<std::endl;
            std::cout<<"        WEAPON:"<<std::endl;
            std::cout<<"-----------------------"<<std::endl;

            std::cout<<"(Elven Woodsman's Bow): This bow is made from high-quality wood known for its elasticity and strength.\n "
                       "Its wielders, the elven woodsmen, possess incredible skill in archery.\n "
                       "The arrows they use may also feature special tips that inflict additional damage to enemies."<<std::endl;
            std::cout<<std::endl;

            break;

        case 3:
            std::cout<<"3. **Gnomes**:\n"
                       " \tResidents of the Gnomish Forge emerged amidst mountain peaks,"
                       " where they studied the art of blacksmithing and invented new technologies.\n"
                       " Their history is linked to the development of industry and technology,"
                       " as well as the struggle for control over resources."<<std::endl;
            std::cout<<std::endl;

            std::cout<<"-----------------------"<<std::endl;
            std::cout<<"        WEAPON:"<<std::endl;
            std::cout<<"-----------------------"<<std::endl;
            std::cout<<"(Gnomish Engineer's Mallet): This mallet is crafted from heavy metal and has a compact design.\n"
                       " Its wielders, the gnomish engineers, use it for repairs, construction, and as a weapon in close combat.\n "
                       "It may also feature special mechanisms or additional adaptations that make it more deadly in the hands of a gnome."<<std::endl;
            std::cout<<std::endl;

            break;
        case 4:
            std::cout<<"4. **Orcs**:\n"
                       "\t Inhabitants of the Orcish Wasteland grew up in the harsh desert environment,"
                       " where they learned to survive and fight for power.\n Their history is filled with wars and conquests,"
                       " but also with a quest for justice and a place in the sun for their people."<<std::endl;
            std::cout<<std::endl;

            std::cout<<"-----------------------"<<std::endl;
            std::cout<<"        WEAPON:"<<std::endl;
            std::cout<<"-----------------------"<<std::endl;
            std::cout<<"(Black Mage's Staff): This staff is made from black wood specially grown in dark and harsh conditions,\n"
                       " enhancing its power. Its wielders, the orcish black mages,\n"
                       " command dark magic and blend it with their own life energy to create powerful spells.\n"
                       " The staff can also serve as an effective melee weapon, dealing dark-inflicted damage to enemies."<<std::endl;
            break;
        case 5:
            std::cout<<"5. **Goblins**:\n"
                       " \tInhabitants of the Goblin Territories have always lived in shadow and chaos,"
                       " being bandits and mercenaries.\n However,"
                       " their history also contains moments of heroism and"
                       " courage when they stood up to defend their people and territories from external threats."<<std::endl;
            std::cout<<std::endl;

            std::cout<<"-----------------------"<<std::endl;
            std::cout<<"        WEAPON:"<<std::endl;
            std::cout<<"-----------------------"<<std::endl;
            std::cout<<"Goblin Miner's Blade): This blade is made from sharp and sturdy steel, using technologies developed by goblins in their mines.\n"
                       " Its wielders, the goblin miners, possess great strength and skill in close combat. \n"
                       "Additionally, the blade may have special overlays or spikes that inflict additional damage to enemies."<<std::endl;
            break;
        case 6:
            std::cout<<"        BYE"<<std::endl;
            exit(1);
    }
    infoAboutGame();

}

void User::infoAboutGame() {
    std::cout<<"---------------------------"<<std::endl;
    std::cout<<"            INFO           "<<std::endl;
    std::cout<<"---------------------------"<<std::endl;


    std::cout<<"(1) World."<<std::endl;
    std::cout<<"(2) Race and people Erión."<<std::endl;
    std::cout<<"(3) Game functionality. "<<std::endl;
    std::cout<<"(4) Exit. "<<std::endl;

    std::cout<<std::endl;
    std::cout<<"What do you want to know about? "<<std::endl;
    int k;
    std::cin>>k;
    switch (k) {
        std::cout<<"Info about world."<<std::endl;
        case 1:
            infoAboutWorldAndCountry();
            break;
        case 2:
            infoAboutRace();
            break;
        case 3:
            //About functionality
            break;
        case 4:
            std::cout<<"    BYE"<<std::endl;
            exit(1);
        default:
            std::cout<<"There is no correct choice. "<<std::endl;
            break;
    }
}


