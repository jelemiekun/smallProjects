#ifndef UTILITY_H
#define UTILITY_H

#include "item.h"

// private
static const int MAXIMUM_ITEM = 250;
extern Item sItemList[];
extern int sItemListSize;
extern int IDCounter;

// private
static int* findIndexOfItemToRemove(const int &rItemID);
static void removeSpecificItem(Item &rItem);
static bool isUpdatingQuantityWillExceedLimit(const int &rNewQuantity);

// public
extern void addItem(const Item &rItem);
void removeItem(const int &rItemID);
void updateItemQuantity(const int &rItemID, const int &rNewQuantity);
void updateItemPrice(const int &rItemID, const float &rNewPrice);
void searchItemByName(const std::string &rItemName);
void searchItemByID(const int &rItemID);
void getItemDetails(const int &rItemID);
void determineQuantityLevel(Item &rItem);
void listItems();
void checkReorderItems();
void sortItemsByCategory();
void generateInventoryStatusReport();
void generateInventoryRevenueReport();
void generateTotalReport();

#endif