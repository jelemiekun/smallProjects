#include <iostream>
#include "item.h"
#include "utility.h"

void displayText() {
    std::cout << "====================" << '\n';
    std::cout << "  Inventory System" << '\n';
    std::cout << "====================" << '\n';
    std::cout << "1. Add Item" << '\n';
    std::cout << "2. Remove Item" << '\n';
    std::cout << "3. Update Item Quantity" << '\n';
    std::cout << "4. Update Item Price" << '\n';
    std::cout << "5. Search by Item Name" << '\n';
    std::cout << "6. Search by Item ID" << '\n';
    std::cout << "7. Get Item Details" << '\n';
    std::cout << "8. List Items" << '\n';
    std::cout << "9. Check Reorder Items" << '\n';
    std::cout << "10. List Items By Category" << '\n';
    std::cout << "11. Generate Inventory Status Report" << '\n';
    std::cout << "12. Generate Inventory Revenue Report" << '\n';
    std::cout << "13. Generate Total Report" << '\n';
    std::cout << "14. Exit" << '\n';
}

int askInput() {
    bool isLooping = true;
    int input;
    int MAX_OPERATIONS = NUMBER_OF_OPERATIONS + 1; // + 1 for exit

    do {
        std::cout << "Number: ";
        std::cin >> input;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(999999, '\n');
            std::cout << "Invalid. Input a number.";
        } else if (input < 0 || input > MAX_OPERATIONS) {
            std::cout << "Invalid. Input from 1-14 only.";
        } else {
            isLooping = false;
        }
    } while (isLooping);

    return input;
}

// PO = Process Operation

void POAddItem() {

}

void PORemoveItem() {

}

void POUpdateItemQuantity() {

}

void POUpdateItemPrice() {

}

void POSearchItemByName() {

}

void POSearchItemByID() {

}

void POGetItemDetails() {

}

void processOperation(const int &rInput, bool &rIsLooping) {
    switch (rInput)
    {
    case 1:
        POAddItem();
        break;
    case 2:
        PORemoveItem();
        break;
    case 3:
        POUpdateItemQuantity();
        break;
    case 4:
        POUpdateItemPrice();
        break;
    case 5:
        POSearchItemByName();
        break;
    case 6:
        POSearchItemByID();
        break;
    case 7:
        POGetItemDetails();
        break;
    case 8:
        listItems();
        break;
    case 9:
        checkReorderItems();
        break;
    case 10:
        listItemsByCategory();
        break;
    case 11:
        generateInventoryStatusReport();
        break;
    case 12:
        generateInventoryRevenueReport();
        break;
    case 13:
        generateTotalReport();
        break;
    case 14:
        rIsLooping = false;;
        break;
    default:
        std::cout << "ProcessOperation: Invalid." << '\n';
        break;
    }
}

void driver() {
    bool isLooping = true;

    do {
        displayText();
        int input = askInput();
        processOperation(input, isLooping);
    } while (isLooping);
}

int main() {
    driver();
    return EXIT_SUCCESS;
}