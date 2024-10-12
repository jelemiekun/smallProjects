#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <ctime>

class Item {
public:
    enum class ItemCategory {
        Empty,
        Groceries,
        Furniture,
        Electronics,
        Office_supplies,
        Clothing
    };

    enum class QuantityLevel {
        Empty = 0,
        Reorder = 5,
        Maximum = 20
    };

private:
    static const int MAXIMUM_ITEM = 250;
    static Item sItemList[];
    static int sItemListSize;
    static int IDCounter;

    int mItemID;
    std::string mItemName;
    int mQuantity;
    float mPrice;
    ItemCategory mCategory;
    QuantityLevel mQuantityLevel;
    std::string mSupplierInformation;

private:
    static int* findIndexOfItemToRemove(const int &rItemID);
    static void removeSpecificItem(Item &rItem);

public:
    Item();

    Item(const std::string &rItemName, const int &rQuantity, const float &rPrice, 
        const ItemCategory &rCategory, const std::string &rSupplierInformation);

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

    int getID() const;
};

#endif
