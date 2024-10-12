#include "utility.h"
#include <iostream>

Item sItemList[MAXIMUM_ITEM] = {};

int sItemListSize = std::size(sItemList);

int IDCounter = 1;

int* findIndexOfItemToRemove(const int &rItemID) {
    static int indexes[MAXIMUM_ITEM];
    std::fill(std::begin(indexes), std::end(indexes), -1); // Fill the array index of -1.
    
    for (int i = 0; i < MAXIMUM_ITEM; i++) { // Iterate the loop.
        if (sItemList[i].mItemID == rItemID) { // If item ID of current index is equal to reference item ID.
            for (int j = 0; j < MAXIMUM_ITEM; j++) { // Then, loop again but for the indexes to find next empty index.
                if (indexes[j] == -1) { // If indexes value is -1 (empty), fill with the current outer loop.
                    indexes[j] = i;
                    break;
                }
            }
        }
    }
    return indexes;
}

void addItem(const Item &rItem) {
    int quantityCounter = 0;

    for (int i = 0; i < sItemListSize; i++) {
        if (sItemList[i].mItemID == -1) { // If index value in sItemList is -1, it's empty
            sItemList[i] = rItem; // Fill the current index with the current Item
            determineQuantityLevel(sItemList[i]);
            quantityCounter++;
        }

        if (quantityCounter >= rItem.mQuantity)
            break;
    }
}

void removeSpecificItem(Item &rItem) {
    rItem.mItemID = -1;
    rItem.mItemName = "";
    rItem.mQuantity = -1;
    rItem.mPrice = -1;
    rItem.mCategory = Item::ItemCategory::Empty;
    rItem.mQuantityLevel = Item::QuantityLevel::Empty;
    rItem.mSupplierInformation = "";
}

void removeItem(const int &rItemID) {
    int* indexes = findIndexOfItemToRemove(rItemID);   

    for (int i = 0; i < MAXIMUM_ITEM; i++) {
        if (indexes[i] != -1) { // If current index is not -1 (not empty), remove the details of that index item.
            removeSpecificItem(sItemList[indexes[i]]);
        }
    }

    for (int i = 0; i < MAXIMUM_ITEM; i++) { // Iterate the loop.
        if (sItemList[i].mItemID == -1) { // If current item ID is -1, find the next non-empty index and replace it.
            for (int j = i; j < MAXIMUM_ITEM; j++) { // Itierate the loop again to find the next non-empty index.
                if (sItemList[j].mItemID != -1) { // If current item ID is NOT -1, it's not empty. Non-empty index found.
                    sItemList[i] = sItemList[j]; // Move the non-empty index to the current empty index.
                    removeSpecificItem(sItemList[j]); // Remove the moved non-empty index.
                    break;
                }
            }
        }
    }
}


bool isUpdatingQuantityWillExceedLimit(const int &rNewQuantity) {
    int size = 0;

    for (const Item& item : sItemList) {
        if (item.mItemID != -1) {
            size++;
        }
    }

    size += rNewQuantity;

    return rNewQuantity > MAXIMUM_ITEM;
}

void updateItemQuantity(const int &rItemID, const int &rNewQuantity) {
    if (rNewQuantity < 0) {
        std::cout << "updateItemQuantity: Invalid quantity." << '\n';
        return;
    }
    
    if (isUpdatingQuantityWillExceedLimit(rNewQuantity)) {
        std::cout << "updateIteQuantity: Adding new quantity will exceed limit." << '\n';
        return;
    }

    for (int i = 0; i < sItemListSize; i++) {
        if (sItemList[i].mItemID == rItemID) {
            sItemList[i].mQuantity = rNewQuantity;
            determineQuantityLevel(sItemList[i]);
        }
    }
}

void updateItemPrice(const int &rItemID, const float &rNewPrice) {
    if (rNewPrice < 0) {
        std::cout << "updateItemPrice: Invalid price." << '\n';
        return;
    }

    for (int i = 0; i < sItemListSize; i++) {
        if (sItemList[i].mItemID == rItemID) {
            sItemList[i].mPrice = rNewPrice;
        }
    }
}

void searchItemByName(const std::string &rItemName) { 
    bool found = false;

    for (int i = 0; i < sItemListSize; i++) {
        if (sItemList[i].mItemName.find(rItemName) != std::string::npos) {
            std::cout << "Item found!\n";
            std::cout << "Item ID: " << sItemList[i].mItemID << '\n';
            found = true;
        }
    }

    if (!found) {
        std::cout << "No items found with the name: " << rItemName << '\n';
    }
}

void searchItemByID(const int &rItemID) {
    bool found = false;

    for (int i = 0; i < sItemListSize; i++) {
        if (sItemList[i].mItemID == rItemID) {
            std::cout << "Item found!\n";
            std::cout << "Item ID: " << sItemList[i].mItemID << '\n';
            found = true;
        }
    }

    if (!found) {
        std::cout << "No items found with the ID: " << rItemID << '\n'; 
    }
}


void getItemDetails(const int &rItemID) {

}

void determineQuantityLevel(Item &rItem) {
    if (rItem.mQuantity == 0) {
        rItem.mQuantityLevel = Item::QuantityLevel::Empty;
    } else if (rItem.mQuantity <= static_cast<int>(Item::QuantityLevel::Reorder)) {
        rItem.mQuantityLevel = Item::QuantityLevel::Reorder;
    } else if (rItem.mQuantity >= static_cast<int>(Item::QuantityLevel::Maximum)) {
        rItem.mQuantityLevel = Item::QuantityLevel::Maximum;
    } else {
        rItem.mQuantityLevel = Item::QuantityLevel::Empty;
    }
}

void listItems() {
    for (int i = 0; i < sItemListSize; i++) {
        if (sItemList[i].mItemID != -1) {
            std::cout << i + 1 << ". " << sItemList[i].mItemName << " - " << &sItemList[i] << '\n';
        }
    }
}