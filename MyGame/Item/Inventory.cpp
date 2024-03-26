//
// Created by Nazar Frazovir on 25.03.2024.
//
#include "Inventory.h"
#include <iostream>
#include <fstream>
#include <memory>

Inventory::Inventory() {}

void Inventory::addItems() {
    std::unique_ptr<Object> item = std::make_unique<Object>(); // make_unique створює обʼєкт, яка створює вказівник
    std::cout<<"        Add item in Inventory: "<<std::endl;

    std::cout<<"Item name: "<<std::endl;
    std::cin>>item->name;

    std::cout<<"Item weight: "<<std::endl;
    std::string weightInput;
    std::cin>>weightInput;

/*    std::string itemName = item->name;
    int itemWeight = item->weight;
    items.push_back(std::move(item));  // Отримання вказівника з unique_ptr
    history.push_back(InventoryHistory("Added: ", itemName + " "+ "Weight: "
    + std::to_string(itemWeight))); //to_string
    saveInventoryToFile();
    перетворює числа, або інші типи данних в рядок.
*/          // Старий код

    try{
    item->weight = std::stoi(weightInput);  // stoi перетворює рядок в ціле число
} catch (const std::invalid_argument& e) {  // Передача аргумента з неправельним значенням в метод, наприклад: ви очікуєте
    std::cerr<<"Invalid input for weight"<<std::endl; // передачу в число а передаєте рядок, тоді буде виключення
    return;
} catch (const std::out_of_range& e) {          // Значення виходять за допустимі межі.
    std::cerr<<"Weight value is out of range."<<std::endl;
    return;
}
std::string itemName = item -> name;
int itemWeight = item ->weight;

items.push_back(std::move(item));  // Додавання вказівника з unique_ptr
history.push_back(InventoryHistory("Added: ", itemName + " "+ "Weight: "
    + std::to_string(itemWeight)));     // to_string перетворює числа,або інші типи даних в рядок

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
    std::ofstream file(filename,std::ios_base::trunc); //відкриття файлу у режимі запису
/*    if (file.is_open()){
//        for(const auto& item:items){
//           file<<"Name: "<<item->name<<" Weight: "<<item->weight<<std::endl;
//        }
//        file.close();
//    }else{
//        std::cerr<<"File not open "<<std::endl;
//    }
 historyInventorySaveToFile();
*/    // Старий код

    if (!file.is_open()){
        std::cerr<<"File not open"<<std::endl;
    }else{
        for(const auto& item: items){
            file<<"Name: "<<item->name<<" Weight: "<<item->weight<<std::endl;
        }
        file.close();
    }
//    historyInventorySaveToFile();
}

void Inventory::historyInventorySaveToFile() {
    std::string filename = "History.txt";
    std::ofstream file(filename, std::ios_base::trunc);//відкриття файлу у режимі запису

    if (file.is_open()){
        for(const auto& change:history){
            file<<"Action: "<<change.action<<" "<<"Details: "<<change.itemDetails<<" "<<std::endl;
            file<<"Timestamp: "<<std::ctime(&change.changeTime);
        }
        file.close();
    }else{
        std::cerr<<"File not to open "<<std::endl;
    }
}

void Inventory::historyInventoryLoadFromFile() {
    std::string filename = "History.txt";
    std::ifstream file(filename,std::ios_base::in); // ios_base::in файл відкритий тільки для читання.

    if(!file.is_open()){
        std::cerr<<"File not open "<<std::endl;
    }
    char symbol;
    while (file.get(symbol)){
        std::cout<<symbol;
    }
}

void Inventory::loadInventoryFromFile() {
    std::string filename = "Inventory.txt";
    std::ifstream file(filename,std::ios_base::in); // ios_base::in файл відкритий тільки для читання

    if(!file.is_open()){
        std::cerr<<"File not open "<<std::endl;
    }
    char symbol;
    while (file.get(symbol)){
        std::cout<<symbol;
    }
}
Inventory::~Inventory() {}

void Inventory::inventoryForAdmin(){
    std::cout<<"                Inventory for Admin       "<<std::endl;
    std::cout<<"(1) Add items for inventory "<<std::endl;
    std::cout<<"(2) Remove items for inventory "<<std::endl;
    std::cout<<"(3) Save inventory to file "<<std::endl;
    std::cout<<"(4) Load inventory From file "<<std::endl;
    std::cout<<"(5) Display(history) inventory for admin "<<std::endl;
    std::cout<<"(6) Save history of inventory "<<std::endl;
    std::cout<<"(7) Exit "<<std::endl;

    int change;
    do{
        std::cin>>change;
        switch (change) {
            case 1:
                addItems();
                std::cout<<"Item add in inventory "<<std::endl;
                break;
            case 2:
                removeItemByName();
                break;
            case 3:
                saveInventoryToFile();
                break;
            case 4:
                loadInventoryFromFile();
                break;
            case 5:
                historyInventoryLoadFromFile();
                break;
            case 6:
                historyInventorySaveToFile();
                break;
            case 7:
                std::cout<<"        BYE     "<<std::endl;
                exit(0);
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
    std::cout<<"(3) Exit "<<std::endl;
    int change;
    do{
        std::cin>>change;
        switch (change) {
            case 1:
                loadInventoryFromFile();
                break;
            case 2:
                removeItemByName();
                break;
            case 3:
                std::cout<<"        BYE     "<<std::endl;
                exit(1);
            default:
                std::cerr<<"Incorrect number. "<<std::endl;
                exit(1);

        }
    }while(change != 3);

}

bool Inventory::compareItemsByName(const std::unique_ptr<Object>& a, const std::unique_ptr<Object>& b) {
return a->name < b->name;
}

void Inventory::sortInventoryByName() {
    std::sort(items.begin(),items.end(), compareItemsByName);
    std::cout<<"        Sort Inventory(by name) "<<std::endl;
    saveInventoryToFile();
}

bool Inventory::compareItemsByWeight(const std::unique_ptr<Object> &a, const std::unique_ptr<Object> &b) {
    return a->weight < b->weight;
}

void Inventory::sortInventoryByWeight() {
    std::sort(items.begin(), items.end(), compareItemsByWeight);
    std::cout << "        Sort Inventory(by weight) " << std::endl;
    saveInventoryToFile();
}

void Inventory::removeItemByName() {
    std::string itemName;
    std::cout<<"Enter name of the item to remove "<<std::endl;
    std::cin>>itemName;

    std::string filename = "Inventory.txt";
    std::ifstream file(filename);

    if (!file.is_open()){
        std::cerr<<"File not open"<<std::endl;
        return;
    }
    std::string line;
    std::vector<std::string> fileContent;

    while (std::getline(file,line)){
        if (line.find(itemName) == std::string::npos){      //  Якщо імʼя співпадає то значить
            fileContent.push_back(line);      // що імʼя не співпало , додаємо рядок до вектора
              // npos - значення класу стрінг,найбільше можливе значення size_t
        }
    }
    file.close();

    std::ofstream outFile(filename);            //Перезаписуєм файл
    for(auto& content:fileContent){
        outFile<<content<<std::endl;
    }
    outFile.close();

    std::cout << "Item [" << itemName << "] removed from inventory." << std::endl;

    historyInventorySaveToFile();
}





