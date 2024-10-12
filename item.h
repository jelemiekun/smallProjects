#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <ctime>

class Item {
private:
enum ItemCategory {
    Groceries,
    Furniture,
    Electronics,
    Office_supplies,
    Clothing
};

enum QuantityLevel {
    empty = 0,
    reorder = 5,
    maximum = 20
};

private:
    static Item sItemList[100];
    int mItemID;
    std::string mItemName;
    int mQuantity;
    float mPrice;
    ItemCategory mCategory;
    QuantityLevel mQuantityLevel;
    std::string mSupplierInformation;

public:
    Item(const int &rItemID, const std::string &rItemName, const int &rQuantity, const float &rPrice, 
        const ItemCategory &rCategory, const std::string &rSupplierInformation) 
        : mItemID(rItemID), mItemName(rItemName), mQuantity(rQuantity), mPrice(rPrice), mCategory(rCategory),
        mSupplierInformation(rSupplierInformation) {

        }

    static void addItem(const Item &rItem);
    static void removeItem(const int &rItemID);
    static void updateItemQuantity(const int &rItemID, const int &rNewQuantity);
    static void updateItemPrice(const int &rItemID, const int &rNewPrice);
    static void searchItemByName(const std::string &rItemName);
    static void searchItemByID(const int &rItemID);
    static void getItemDetails(const int &rItemID);
    static void listItems();
    static void checkReorderItems();
    static void sortItemsByCategory();
    static void generateInventoryStatusReport();
    static void generateInventoryRevenueReport();
    static void generateTotalReport();
};

#endif