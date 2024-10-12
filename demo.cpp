#include <iostream>
#include "item.h"

int main() {
    Item apple("Apple", 2, 1.99, Item::ItemCategory::Groceries, "Local Supplier");
    Item::addItem(apple);
    Item::listItems();
    std::cout << "\n\n\n-----\n\n\n";

    Item orange("Orange", 3, 1.99, Item::ItemCategory::Groceries, "Local Supplier");
    Item::addItem(orange);
    Item::listItems();
    std::cout << "\n\n\n-----\n\n\n";

    Item banana("Banana", 1, 1.99, Item::ItemCategory::Groceries, "Local Supplier");
    Item::addItem(banana);
    Item::listItems();
    std::cout << "\n\n\n-----\n\n\n";

    Item pineapple("Pineapple", 4, 1.99, Item::ItemCategory::Groceries, "Local Supplier");
    Item::addItem(pineapple);
    Item::listItems();
    std::cout << "\n\n\n-----\n\n\n";

    Item::removeItem(banana.getID());
    Item::listItems();
    std::cout << "\n\n\n-----\n\n\n";

    Item red("red", 3, 1.99, Item::ItemCategory::Groceries, "Local Supplier");
    Item::addItem(red);
    Item::listItems();
    std::cout << "\n\n\n-----\n\n\n";

    Item blue("blue", 1, 1.99, Item::ItemCategory::Groceries, "Local Supplier");
    Item::addItem(blue);
    Item::listItems();
    std::cout << "\n\n\n-----\n\n\n";

    Item::removeItem(apple.getID());
    Item::listItems();
    std::cout << "\n\n\n-----\n\n\n";
    

    return EXIT_SUCCESS;
}