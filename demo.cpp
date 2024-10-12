#include <iostream>
#include "item.h"
#include "utility.h"

int main() {
    Item apple("Apple", 2, 1.99, Item::ItemCategory::Groceries, "Local Supplier");
    addItem(apple);
    listItems();
    std::cout << "\n\n\n-----\n\n\n";

    Item orange("Orange", 3, 1.99, Item::ItemCategory::Groceries, "Local Supplier");
    addItem(orange);
    listItems();
    std::cout << "\n\n\n-----\n\n\n";

    Item banana("Banana", 1, 1.99, Item::ItemCategory::Groceries, "Local Supplier");
    addItem(banana);
    listItems();
    std::cout << "\n\n\n-----\n\n\n";

    Item pineapple("Pineapple", 4, 1.99, Item::ItemCategory::Groceries, "Local Supplier");
    addItem(pineapple);
    listItems();
    std::cout << "\n\n\n-----\n\n\n";

    removeItem(banana.mItemID);
    listItems();
    std::cout << "\n\n\n-----\n\n\n";

    Item red("red", 3, 1.99, Item::ItemCategory::Groceries, "Local Supplier");
    addItem(red);
    listItems();
    std::cout << "\n\n\n-----\n\n\n";

    Item blue("blue", 1, 1.99, Item::ItemCategory::Groceries, "Local Supplier");
    addItem(blue);
    listItems();
    std::cout << "\n\n\n-----\n\n\n";

    removeItem(apple.mItemID);
    listItems();
    std::cout << "\n\n\n-----\n\n\n";
    

    return EXIT_SUCCESS;
}