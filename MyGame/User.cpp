//
// Created by Nazar Frazovir on 21.03.2024.
//
#include <iostream>
#include "User.h"
#include "Character/Player.h"
#include "Character/SwordMan.h"
#include "Character/Archer.h"


User::User()
:name("None"){}
//User::User(std::string name, int password,bool isAdmin)
//:name(name),password(password),isAdmin(isAdmin){}
User::User(const std::string &name)
:name(name){}
User::User(User *userptr) {}
User::~User(){}

bool User::auditIfAdmin() {
    int newPassword;
    password = 1234;
    int choice;
    std::cout<<"Hello, You're are admin? (1) - Yes.    (2) - No "<<std::endl;
    std::cin>>choice;
    if (choice == 1){
        std::cout<<"Enter password: "<<std::endl;
        std::cin>>newPassword;
        if (newPassword == password){
            return true;
        } else{
            return false;
        }
    }else if (choice == 2){
        return false;
    }else{
        std::cout<<"You entered incorrect number "<<std::endl;
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
    std::unique_ptr<User> user = std::make_unique<User>();
    std::string name;
    std::cout << "Enter username: ";
    std::cin >> name;
    users.push_back(std::make_unique<User>(name));      // Список користувачів.

    }

void User::saveAllUsersToFile() {
    std::string filename = "User.txt";
    std::ofstream file(filename,std::ios_base::trunc); //відкриття файлу у режимі запису

    if (!file.is_open()) {
        std::cerr << "Failed to open file for writing: " << filename << std::endl;
        return;
    }
    file << "All users:\n";
    for (const auto& user : users) {
        file << "Username: " <<user->name<< std::endl;
    }
    file.close();
}

void User::loadUserFromFile() {
    std::string filename = "User.txt";
    std::ifstream file(filename,std::ios_base::in);

    if(!file.is_open()){
        std::cerr<<"File not open "<<std::endl;
    }
    char symbol;
    while (file.get(symbol)){
        std::cout<<symbol;
    }
}

void User::removeUserByName() {
    std::string userName;
    std::cout<<"Enter name of User to remove "<<std::endl;
    std::cin>>userName;

    std::string filename = "User.txt";
    std::ifstream file(filename);

    if (!file.is_open()){
        std::cerr<<"File not open"<<std::endl;
        return;
    }
    std::string line;
    std::vector<std::string> userContent;

    while (std::getline(file,line)){
        if (line.find(userName) == std::string::npos){      //  Якщо імʼя співпадає то значить
            userContent.push_back(line);      // що імʼя не співпало , додаємо рядок до вектора
            // npos - значення класу стрінг,найбільше можливе значення size_t
        }
    }
    file.close();

    std::ofstream outFile(filename);            //Перезаписуєм файл
    for(auto& content:userContent){
        outFile<<content<<std::endl;
    }
    outFile.close();

    std::cout << "User [" << userName << "] removed from File." << std::endl;

}

void User::createCharacter() {
//    std::string characterName;
//    int characterType;
//
//    std::cout << "Enter character name: ";
//    std::cin >> characterName;
//
//    std::cout << "Choose character type:" << std::endl;
//    std::cout << "1. SwordMan" << std::endl;
//    std::cout << "2. Archer" << std::endl;
//    std::cin >> characterType;
//
//    User* newCharacter = nullptr;
//    switch (characterType) {
//        case 1:
////            newCharacter = reinterpret_cast<User *>(new SwordMan(characterName));// оператор Переведення для вказівників, для найбільш небезпечного переведення
//             characters.push_back(std::make_unique<SwordMan>(characterName));
//            break;
//        case 2:
////            newCharacter = reinterpret_cast<User *>(new Archer(characterName));// оператор Переведення для вказівників, для найбільш небезпечного переведення
//            characters.push_back(std::make_unique<Archer>(characterName));
//            break;
//        default:
//            std::cerr << "Invalid character type. Character creation failed." << std::endl;
//            return;
//    }
//
////    characters.push_back(std::make_unique<User>(newCharacter));
//    std::cout << "Character " << characterName << " created successfully." << std::endl;
    std::unique_ptr<User> character = std::make_unique<User>();
    std::cout << "Enter name: "<<std::endl;
    std::cin >> character->name;
    std::cout << "Enter health: "<<std::endl;
    std::cin >> character->health;
    std::cout << "Enter armor: "<<std::endl;
    std::cin >> character->armor;
    users.push_back(std::move(character));      // Список користувачів.
}

void User::saveCharacter(){
    std::string filename = "Character.txt";
    std::ofstream file(filename,std::ios_base::trunc); //відкриття файлу у режимі запису

    if (!file.is_open()) {
        std::cerr << "Failed to open file for writing: " << filename << std::endl;
        return;
    }
    file << "All users:\n";
    for (const auto& character : characters) {
        file << "Name: " <<character->name <<"Health: "<<character->health <<"Armor: "<<character->armor<<  std::endl;
    }
    file.close();
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
}





