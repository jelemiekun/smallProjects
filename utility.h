#ifndef UTILITY_H
#define UTILITY_H

#include "item.h"

// private
const int NUMBER_OF_OPERATIONS = 13;
static const int MAXIMUM_ITEM = 250;
extern Item sItemList[];
extern int sItemListSize;
extern int IDCounter;

// private
static int* findIndexOfItemToRemove(const int &rItemID);
static void removeSpecificItem(Item &rItem);
static bool isUpdatingQuantityWillExceedLimit(const int &rNewQuantity);
static void determineQuantityLevel(Item &rItem);

// public
extern void addItem(const Item &rItem);
extern void removeItem(const int &rItemID);
extern void updateItemQuantity(const int &rItemID, const int &rNewQuantity);
extern void updateItemPrice(const int &rItemID, const float &rNewPrice);
extern void searchItemByName(const std::string &rItemName);
extern void searchItemByID(const int &rItemID);
extern void getItemDetails(const int &rItemID);
extern void listItems();
extern void checkReorderItems();
extern void listItemsByCategory();
extern void generateInventoryStatusReport();
extern void generateInventoryRevenueReport();
extern void generateTotalReport();

#endif