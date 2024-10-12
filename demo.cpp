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
            std::cout << "Invalid. Input a number." << '\n';
        } else if (input < 0 || input > MAX_OPERATIONS) {
            std::cout << "Invalid. Input from 1-14 only." << '\n';
        } else {
            isLooping = false;
        }
    } while (isLooping);
    std::cin.ignore();

    return input;
}

// PO = Process Operation

void POAddItem() {
    bool isLooping = true;

    std::string mItemName;
    int mQuantity;
    float mPrice;
    Item::ItemCategory mCategory;
    std::string mSupplierInformation;

    std::cout << "Enter item name: ";
    std::getline(std::cin, mItemName);

    do {
        std::cout << "Enter quantity: ";
        std::cin >> mQuantity;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(999999, '\n');
            std::cout << "Invalid. Input a number." << '\n';
        } else if (mQuantity < 0){
            std::cout << "Invalid. Quantity can't be below 0." << '\n';
        } else {
            isLooping = false;
        }
    } while (isLooping);

    isLooping = true;
    do {
        std::cout << "Enter price: ";
        std::cin >> mPrice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(999999, '\n');
            std::cout << "Invalid. Input a number." << '\n';
        } else if (mPrice < 0){
            std::cout << "Invalid. Price can't be below 0." << '\n';
        } else {
            isLooping = false;
        }
    } while (isLooping);
    
    int categoryChoice;
    std::cout << "Select category:\n";
    std::cout << "1. Groceries\n";
    std::cout << "2. Furniture\n";
    std::cout << "3. Electronics\n";
    std::cout << "4. Office Supplies\n";
    std::cout << "5. Clothing\n";

    isLooping = true;
    do {
        std::cout << "Enter category number: ";
        std::cin >> categoryChoice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(999999, '\n');
            std::cout << "Invalid. Input a number." << '\n';
        } else if (categoryChoice < 1 || categoryChoice > 5){
            std::cout << "Invalid. Enter from 1-5 only." << '\n';
        } else {
            isLooping = false;
        }
    } while (isLooping);

    switch (categoryChoice) {
        case 1: mCategory = Item::ItemCategory::Groceries; break;
        case 2: mCategory = Item::ItemCategory::Furniture; break;
        case 3: mCategory = Item::ItemCategory::Electronics; break;
        case 4: mCategory = Item::ItemCategory::Office_supplies; break;
        case 5: mCategory = Item::ItemCategory::Clothing; break;
        default:
            std::cout << "Invalid category. Defaulting to 'Empty'.\n";
            mCategory = Item::ItemCategory::Empty;
            break;
    }

    std::cin.ignore();
    std::cout << "Enter supplier information: ";
    std::getline(std::cin, mSupplierInformation);

    Item newItem(mItemName, mQuantity, mPrice, mCategory, mSupplierInformation);
    addItem(newItem);
    std::cout << "Item added successfully!\n";
}


void PORemoveItem() {
    bool isLooping = true;
    int input;

    do {
        std::cout << "\nItem ID to remove: ";
        std::cin >> input;
    
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(999999, '\n');
            std::cout << "Invalid. Input a number.";
        } else {
            isLooping = false;
        }
    } while (isLooping);
    
    removeItem(input);
}

void POUpdateItemQuantity() {
    bool isLooping = true;
    int input;
    int newQuantity;

    do {
        std::cout << "\nItem ID to update: ";
        std::cin >> input;
    
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(999999, '\n');
            std::cout << "Invalid. Input a number.";
        } else {
            std::cout << "\nNew quantity: ";
            std::cin >> newQuantity;
    
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(999999, '\n');
                std::cout << "Invalid. Input a number.";
            } else if (newQuantity < 0) {
                std::cout << "Invalid. Quantity can't be below 0.";
            } else {
                isLooping = false;
            }
        }
    } while (isLooping);
    
    updateItemQuantity(input, newQuantity);
}

void POUpdateItemPrice() {
    bool isLooping = true;
    int input;
    float newPrice;

    do {
        std::cout << "\nItem ID to update: ";
        std::cin >> input;
    
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(999999, '\n');
            std::cout << "Invalid. Input a number.";
        } else {
            std::cout << "\nNew price: ";
            std::cin >> newPrice;
    
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(999999, '\n');
                std::cout << "Invalid. Input a number.";
            } else if (newPrice < 0) {
                std::cout << "Invalid. Price can't be below 0.";
            } else {
                isLooping = false;
            }
        }
    } while (isLooping);
    
    updateItemPrice(input, newPrice);
}

void POSearchItemByName() {
    std::string name;
    std::cout << "Item Name to Search: ";
    std::cin >> name;
    searchItemByName(name);
}

void POSearchItemByID() {
    bool isLooping = true;
    int input;

    do {
        std::cout << "\nItem ID to search: ";
        std::cin >> input;
    
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(999999, '\n');
            std::cout << "Invalid. Input a number.";
        } else {
            isLooping = false;
        }
    } while (isLooping);
    
    searchItemByID(input);
}

void POGetItemDetails() {
    bool isLooping = true;
    int input;

    do {
        std::cout << "\nItem ID to get details: ";
        std::cin >> input;
    
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(999999, '\n');
            std::cout << "Invalid. Input a number.";
        } else {
            isLooping = false;
        }
    } while (isLooping);
    
    getItemDetails(input);
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