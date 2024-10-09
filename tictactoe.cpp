#include <iostream>
#include <cctype>

static void inputPlayer();
static void inputComputer();
static void displayBoard();
static void determineWinnr();

static bool equalsIgnoreCase(const char &r_input, const char &r_reference) {
    return std::tolower(r_input) == std::tolower(r_reference);
}

static void render() {
    std::string board[9];
}

void driverTictactoe() {
    std::cout << "Tic-Tac-Toe" << '\n';

    char input;
    bool playing = true;
    do {

        std::cout << "Would you like to play? [Y/N]: ";
        std::cin >> input;

        if (equalsIgnoreCase(input, 'Y')) {
            render();
        } else if (equalsIgnoreCase(input, 'N')) {
            std::cout << "See you next time!" << '\n';
            playing = false;
        } else {
            std::cout << "Invalid input!" << '\n';
            std::cin.clear();
            std::cin.ignore(9999999, '\n');
        }
    } while (playing);
}