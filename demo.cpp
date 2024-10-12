#include <iostream>
#include "item.h"


int main() {
    Item apple("Apple", 15, 1.99, Item::ItemCategory::Groceries, "Local Supplier");
    Item::addItem(apple);
    Item::listItems();
    Item orange("Orange", 15, 1.99, Item::ItemCategory::Groceries, "Local Supplier");
    Item::addItem(orange);
    Item::listItems();
    std::cout << "-----" << '\n';
    Item::removeItem(apple.getID());
    Item::listItems();
    
    return EXIT_SUCCESS;
}
