//
// Created by Nazar Frazovir on 21.03.2024.
//
#include <iostream>
#include "User.h"
#include "Player.h"
#include "SwordMan.h"
#include "Archer.h"
#include "Character.h"

User::User()
:name("None"){}
//User::User(std::string name, int password,bool isAdmin)
//:name(name),password(password),isAdmin(isAdmin){}
User::User(const std::string &name)
:name(name){}
User::User(std::string,int,int) {}
User::User(std::unique_ptr<User> uniqueCharacter) {}
//User::User(User *userptr) {}
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
    std::ofstream file(filename,std::ios_base::app); //відкриття файлу у режимі запису

    if (!file.is_open()) {
        std::cerr << "Failed to open file for writing: " << filename << std::endl;
        return;
    }

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
    std::unique_ptr<Character> character = std::make_unique<Character>();
    std::cout << "Enter name: "<<std::endl;
    std::cin >> character->charName;
    std::cout << "Enter health: "<<std::endl;
    std::cin >> character->charHealth;
    std::cout << "Enter armor: "<<std::endl;
    std::cin >> character->charArmor;
    characters.push_back(std::move(character)); // Додавання персонажа до вектора characters
}


void User::saveCharacter(){
    std::string filename = "Character.txt";
    std::ofstream file(filename,std::ios_base::app); //відкриття файлу у режимі запису

    if (!file.is_open()) {
        std::cerr << "Failed to open file for writing: " << filename << std::endl;
        return;
    }

    for (const auto& character : characters) {
        file << "Name: " << character->charName << "Health: " << character->charHealth << " Armor: " << character->charArmor
             << std::endl;
    }
    if (characters.empty()){
        std::cout<<"File is empty "<<std::endl;
        file.close();
        return;
    }
    if(file.fail()){
        std::cerr<<"Error writing in file"<<std::endl;
    }else{std::cout<<"Character added successfully"<<std::endl;}
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





