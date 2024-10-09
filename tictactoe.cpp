#include <iostream>
#include <cctype>
#include <cstdlib>
#include <ctime>

enum gameCondition {
    playerWin = 0,
    playerLose = 1,
    tie = 3
};

static bool isGameDone(std::string board[], const int &r_boardSize) {
    return true;
}

static void displayBoard(std::string board[], const int &r_boardSize) {
    for (int i = 0; i < 9; i++) {
        std::cout << " " << board[i] << " | ";
        if (i == 2 || i == 5)
            std::cout << "\n---|----|---|\n";
    }
    std::cout << '\n';
}

static void makeMove(const bool &r_IsPlayer, const int rowColumn[], const char &r_input, std::string board[]) {
    const char validInput = r_IsPlayer ? 'X' : 'O';

}

static void inputMove(const bool &r_IsPlayer, std::string board[]) {
    const char validInput = r_IsPlayer ? 'X' : 'O';
    bool isValidInput = false;
    int rowColumnInput;
    while (!isValidInput) {
        std::cout << "Input #: ";
        std::cin >> rowColumnInput;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(99999, '\n');
            std::cout << "Invalid input. Please enter number only." << '\n';
        } else if (rowColumnInput > 9 || rowColumnInput < 1) {
            std::cout << "Please input from 1-9 only." << '\n';
        } else {
            board[rowColumnInput] = validInput;
            isValidInput = true;
        }
    }
}

static bool equalsIgnoreCase(const char &r_input, const char &r_reference) {
    return std::tolower(r_input) == std::tolower(r_reference);
}

static int generateRandomNumber(const int &r_min, const int &r_max) {
    bool isSeeded = false;
    if (!isSeeded) {
        std::srand(static_cast<unsigned int>(std::time(0)));
        isSeeded = true;
    }
    return r_min + (std::rand() % (r_max - r_min + 1));
}

static void render() {
    int whoFirst = generateRandomNumber(1, 2);
    std::string board[9] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
    bool finish = false;
    int turn = 0;
    int gameCondition;
    bool isPlayerFirst = (whoFirst == 0); 

    do {
        displayBoard(board, std::size(board));
        
        if (turn % 2 == 0) {
            inputMove(!isPlayerFirst, board);
        } else { // Computer's turn
            inputMove(isPlayerFirst, board);
        }

        finish = isGameDone(board, std::size(board));
        turn++;
    } while (!finish);
}

void driverTictactoe() {
    std::cout << "Tic-Tac-Toe" << '\n';

    char input;
    bool isPlaying = true;
    do {
        std::cout << "Would you like to play? [Y/N]: ";
        std::cin >> input;

        if (equalsIgnoreCase(input, 'Y')) {
            render();
        } else if (equalsIgnoreCase(input, 'N')) {
            std::cout << "See you next time!" << '\n';
            isPlaying = false;
        } else {
            std::cout << "Invalid input!" << '\n';
            std::cin.clear();
            std::cin.ignore(9999999, '\n');
        }
    } while (isPlaying);
}