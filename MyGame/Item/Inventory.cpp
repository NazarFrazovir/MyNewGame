//
// Created by Nazar Frazovir on 25.03.2024.
//
#include "Inventory.h"
#include <iostream>
#include <fstream>
#include <memory>

void Inventory::addItems() {
    std::unique_ptr<Object> item = std::make_unique<Object>();
//Object* item = new Object();
    std::cout<<"        Add item in Inventory: "<<std::endl;
    std::cout<<"Item name: "<<std::endl;
    std::cin>>item->name;
    std::cout<<"Item weight: "<<std::endl;
    std::cin>>item->weight;
    std::string itemName = item->name;
    int itemWeight = item->weight;
    items.push_back(std::move(item));  // Отримання вказівника з unique_ptr
    history.push_back(InventoryHistory("Added: ", itemName + " "+ "Weight: "
    + std::to_string(itemWeight))); //to_string
    // перетворює числа, або інші типи данних в рядок.
    saveInventoryToFile();

}
void Inventory::removeItems() {
    int index;
    std::cout<<"Enter item who needs to remove: "<<std::endl;
    std::cin>>index;
    if (index >= 0 && index < items.size()) {
        items.erase(items.begin() + index);  // erase - видалення індекса з вектора
        history.push_back(InventoryHistory("Removed", ""));
        saveInventoryToFile();
    }
}
void Inventory::displayItems() {
    std::cout<<"Inventory: "<<std::endl;
    for(auto& item: items){
        std::cout<<"[ "<<"Name: "<<item->name<<std::endl<<"Weight: "<<item->weight<<" ]"<<std::endl;
    }
}
void Inventory::displayHistory() {
    std::cout<<"        Inventory change history   "<<std::endl;
    for(auto& change:history){
        std::cout<<"Action: "<<change.action<<" "<<"Details: "<<change.itemDetails<<" "<<std::endl;
        std::cout<<"Timestamp: "<<std::ctime(&change.changeTime);   //Конвертує тип даних time_t в рядок.
    }
}

void Inventory::saveInventoryToFile() {
    std::string filename = "Inventory.txt";
//    std::cout<<"Enter file name: "<<std::endl;
//    std::cin>>filename;
    std::ofstream file(filename);
    if (file.is_open()){
        for(auto& item:items){
           file<<"Name: "<<item->name<<" Weight: "<<item->weight<<std::endl;
        }
        file.close();
        std::cout<<"Inventory saved to file "<<std::endl;
    }else{
        std::cerr<<"File not to open "<<std::endl;
    }
}

void Inventory::loadInventoryFromFile() {
    std::string filename = "Inventory.txt";
//    std::cout<<"Enter file name: "<<std::endl;
//    std::cin>>filename;
    std::ifstream file(filename);
    if (file.is_open()){
        items.clear();
        std::string itemName;
        int itemWeight;
        while(file >> itemName >> itemWeight){  // Виводимо з файлу
        std::unique_ptr<Object> newItem = std::make_unique<Object>(itemName,itemWeight);
            items.push_back(std::move(newItem));   // додаємо до кінця
        }
        file.close();
        std::cout<<"Inventory load from file "<<std::endl;
    }else{
        std::cerr<<"File not to open "<<std::endl;
    }
}
Inventory::~Inventory() {
    items.clear();
}

void Inventory::inventoryForAdmin(){
    std::cout<<"                Inventory for Admin       "<<std::endl;
    std::cout<<"(1) Add items for inventory "<<std::endl;
    std::cout<<"(2) Remove items for inventory "<<std::endl;
    std::cout<<"(3) Save inventory to file "<<std::endl;
    std::cout<<"(4) Load inventory From file "<<std::endl;
    std::cout<<"(5) Display inventory for admin "<<std::endl;
    std::cout<<"(6) Just display inventory"<<std::endl;
    std::cout<<"(7) Exit "<<std::endl;

    int change;
    do{
        std::cin>>change;
        switch (change) {
            case 1:
                addItems();
                std::cout<<"Items add in inventory "<<std::endl;
                break;
            case 2:
                removeItems();
                break;
            case 3:
                saveInventoryToFile();
                break;
            case 4:
                loadInventoryFromFile();
                break;
            case 5:
                displayHistory();
                break;
            case 6:
                displayItems();
                break;
            case 7:
                std::cout<<"        BYE     "<<std::endl;
                exit(1);
            default:
                std::cerr<<"Incorrect number. "<<std::endl;
                break;
        }
    }while(change != 7);

}
void Inventory::inventoryForUser(){
    std::cout<<"                Inventory for User       "<<std::endl;
    std::cout<<"(1) Show Inventory "<<std::endl;
    std::cout<<"(2) Remove items for inventory "<<std::endl;
    std::cout<<"(3) Sort by name Inventory "<<std::endl;
    std::cout<<"(4) Sort by weight Inventory"<<std::endl;
    std::cout<<"(5) Exit "<<std::endl;
    int change;
    do{
        std::cin>>change;
        switch (change) {
            case 1:
                displayItems();
                break;
            case 2:
                removeItems();
                break;
            case 3:
                sortInventoryByName();
                break;
            case 4:
                sortInventoryByWeight();
                break;
            case 5:
                std::cout<<"        BYE     "<<std::endl;
                exit(1);
            default:
                std::cerr<<"Incorrect number. "<<std::endl;
                break;
        }
    }while(change != 5);

}

bool Inventory::compareItemsByName(const std::unique_ptr<Object>& a, const std::unique_ptr<Object>& b) {
return a->name < b->name;
}

void Inventory::sortInventoryByName() {
    std::sort(items.begin(),items.end(), compareItemsByName);
    std::cout<<"        Sort Inventory(by name) "<<std::endl;
    displayItems();
}

bool Inventory::compareItemsByWeight(const std::unique_ptr<Object> &a, const std::unique_ptr<Object> &b) {
    return a->weight < b->weight;
}

void Inventory::sortInventoryByWeight() {
    std::sort(items.begin(),items.end(), compareItemsByWeight);
    std::cout<<"        Sort Inventory(by weight) "<<std::endl;
    displayItems();
}

