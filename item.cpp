#include "item.h"

Item Item::sItemList[Item::MAXIMUM_ITEM] = {};

int Item::sItemListSize = std::size(Item::sItemList);

int Item::IDCounter = 1;

int* Item::findIndexOfItemToRemove(const int &rItemID) {
    static int indexes[MAXIMUM_ITEM] = {0};
    for (int i = 0; i < MAXIMUM_ITEM; i++) { // Iterate the loop
        if (sItemList[i].mItemID == rItemID) { // If item ID of current index is equal to reference item ID
            for (int j = 0; j < MAXIMUM_ITEM; j++) { // Then, loop again but for the indexes
                if (indexes[j] == 0) { // If indexes value is -1 (empty), fill with the current outer loop
                    indexes[j] = i;
                    break;
                }
            }
        }
    }
    return indexes;
}

Item::Item() {
    mItemID = 0;
    mItemName = "";
    mQuantity = 0;
    mPrice = 0;
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

void Item::addItem(const Item &rItem) {
    int quantityCounter = 0;

    for (int i = 0; i < sItemListSize; i++) {
        if (sItemList[i].mItemID == 0) {
            sItemList[i] = rItem;
            quantityCounter++;
        }

        if (quantityCounter >= rItem.mQuantity)
            break;
    }
}

void Item::removeSpecificItem(Item &rItem) {
    rItem.mItemID = 0;
    rItem.mItemName = "";
    rItem.mQuantity = 0;
    rItem.mPrice = 0;
    rItem.mCategory = Item::ItemCategory::Empty;
    rItem.mQuantityLevel = Item::QuantityLevel::Empty;
    rItem.mSupplierInformation = "";
}

void Item::removeItem(const int &rItemID) {
    int* indexes = findIndexOfItemToRemove(rItemID);   

    for (int i = 0; i < MAXIMUM_ITEM; i++) {
        if (indexes[i] != 0) {
            removeSpecificItem(sItemList[i]);
        }
    }

    for (int i = 0; i < MAXIMUM_ITEM; i++) { // Itirate the loop.
        if (sItemList[i].mItemID == 0) { // If current item ID is 0, find the next non-empty index and replace it.
            for (int j = i; j < MAXIMUM_ITEM; j++) { // Itierate the loop again to find the next non-empty index.
                if (sItemList[j].mItemID != 0) { // If current item ID is NOT 0, it's not empty. Non-empty index found.
                    sItemList[i] = sItemList[j]; // Move the non-empty index to the current empty index.
                    removeSpecificItem(sItemList[j]); // Remove the moved non-empty index.
                    break;
                }
            }
        }
    }
}

void Item::listItems() {
    for (int i = 0; i < sItemListSize; i++) {
        if (sItemList[i].mItemID != 0 ) {
            std::cout << i + 1 << ". " << sItemList[i].mItemName << " - " << &sItemList[i] << '\n';
        }
    }
}

int Item::getID() const {
    return mItemID;
}