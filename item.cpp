#include "utility.h"

Item::Item() {
    mItemID = -1;
    mItemName = "";
    mQuantity = -1;
    mPrice = -1;
    mCategory = Item::ItemCategory::Empty;
    mQuantityLevel = Item::QuantityLevel::Empty;
    mSupplierInformation = "";
}

Item::Item(const std::string &rItemName, const int &rQuantity, const float &rPrice, 
        const ItemCategory &rCategory, const std::string &rSupplierInformation) 
        : mItemName(rItemName), mQuantity(rQuantity), mPrice(rPrice), mCategory(rCategory),
        mSupplierInformation(rSupplierInformation) {
    mItemID = IDCounter;
    IDCounter++;
    std::cout << "Item " << rItemName << " created." << '\n';
}