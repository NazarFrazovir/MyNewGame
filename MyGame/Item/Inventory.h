//
// Created by Nazar Frazovir on 25.03.2024.
//

#ifndef MYGAME_INVENTORY_H
#define MYGAME_INVENTORY_H
#include "Object.h"
#include <iostream>
#include <fstream>
struct InventoryHistory{
    std::string action;
    std::string itemDetails;
    time_t changeTime;          // Відображає час, секунди в числах

    InventoryHistory(const std::string& action,const std::string& itemDetails)
            :action(action),itemDetails(itemDetails),changeTime(time(nullptr)){}
};
class Inventory{
private:
    std::vector<std::unique_ptr<Object>> items;
    std::vector<InventoryHistory> history;
public:
    ~Inventory();
    void addItems();
    void removeItems();
    void displayItems();
    void saveInventoryToFile();
    void loadInventoryFromFile();
    void inventoryForAdmin();
    void displayHistory();
    void inventoryForUser();
    void sortInventoryByName();
    static bool compareItemsByName(const std::unique_ptr<Object>& a, const std::unique_ptr<Object>& b);
    static bool compareItemsByWeight(const std::unique_ptr<Object>&a, const std::unique_ptr<Object>& b);
    void sortInventoryByWeight();


};
#endif //MYGAME_INVENTORY_H
