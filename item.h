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

public:
    int mItemID;
    std::string mItemName;
    int mQuantity;
    float mPrice;
    ItemCategory mCategory;
    QuantityLevel mQuantityLevel;
    std::string mSupplierInformation;

public:
    Item();

    Item(const std::string &rItemName, const int &rQuantity, const float &rPrice, 
        const ItemCategory &rCategory, const std::string &rSupplierInformation);
};

#endif
