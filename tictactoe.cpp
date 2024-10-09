#include <iostream>
#include <cctype>
#include <cstdlib>
#include <ctime>

enum gameStatus {
    win = 1,
    lose = 2,
    tie = 3
};

void displayBoard(char *spaces) {
    for (int i = 0; i < 9; i++) {
        if (i == 0 || i == 3 || i == 6)
            std::cout << "| ";
        std::cout << spaces[i] << " | ";
        if (i == 2 || i == 5)  {
            std::cout << '\n';
            std::cout << "|---|---|---|";
            std::cout << '\n';
        }
    }
    std::cout << '\n';
}

void computerMove(char *spaces, const char &r_computer) {
    bool loop = true;
    int number;
    std::srand(static_cast<unsigned int>(std::time(0)));
    do {
        number = std::rand() % 9;

        if (spaces[number] == ' ') {
            spaces[number] = r_computer;
            loop = false;
        }
    } while (loop);
}

bool checkWinner (const char *spaces, gameStatus &r_status, const char &r_player, const char &r_computer) {
    bool tieStatus = true;
    for (int i = 0; i < 9; i++) {
        if (spaces[i] == ' ')
            tieStatus = false;
    }

    if (tieStatus) {
        r_status = tie;
        return false;
    } else {
        if ((spaces[0] == r_player && spaces[1] == r_player && spaces[2] == r_player) || 
            (spaces[3] == r_player && spaces[4] == r_player && spaces[5] == r_player) ||
            (spaces[6] == r_player && spaces[7] == r_player && spaces[8] == r_player) ||
            (spaces[0] == r_player && spaces[3] == r_player && spaces[6] == r_player) ||
            (spaces[1] == r_player && spaces[4] == r_player && spaces[7] == r_player) ||
            (spaces[2] == r_player && spaces[5] == r_player && spaces[8] == r_player) ||
            (spaces[0] == r_player && spaces[4] == r_player && spaces[8] == r_player) ||
            (spaces[2] == r_player && spaces[4] == r_player && spaces[6] == r_player) ) {
            r_status = win;
            return false;
        } else if ((spaces[0] == r_computer && spaces[1] == r_computer && spaces[2] == r_computer) || 
            (spaces[3] == r_computer && spaces[4] == r_computer && spaces[5] == r_computer) ||
            (spaces[6] == r_computer && spaces[7] == r_computer && spaces[8] == r_computer) ||
            (spaces[0] == r_computer && spaces[3] == r_computer && spaces[6] == r_computer) ||
            (spaces[1] == r_computer && spaces[4] == r_computer && spaces[7] == r_computer) ||
            (spaces[2] == r_computer && spaces[5] == r_computer && spaces[8] == r_computer) ||
            (spaces[0] == r_computer && spaces[4] == r_computer && spaces[8] == r_computer) ||
            (spaces[2] == r_computer && spaces[4] == r_computer && spaces[6] == r_computer) ) {
            r_status = lose;
            return false;
        }
    }
    return true;
}

void playerMove(char *spaces, char &r_player) {
    bool loop = true;
    int number;

    do {
        std::cout << "Number to place " << r_player << " (1-9): ";
        std::cin >> number;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(99999, '\n');
            std::cout << "Please input 1-9 only." << '\n';
        } else if (number > 9 || number < 1) {
            std::cout << "Invalid input." << '\n';
        } else {
            number--;
            if (spaces[number] == ' ') {
                spaces[number] = r_player;
                loop = false;
            } else {
                std::cout << "Space already occupied." << '\n';
            }
        }
    } while (loop);
}

void printOutcome(const gameStatus &r_gameStatus) {
    switch (r_gameStatus)
    {
    case tie:
        std::cout << "\n\nIt's a tie!\n\n";
        break;
    case win:
        std::cout << "\n\nYou win!\n\n";
        break;
    case lose:
        std::cout << "\n\nYou lose!\n\n";
        break;
    }
}

void gameLoop(char &r_player) {
    char computer = r_player == 'X' ? 'O' : 'X';
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    bool isPlaying = true;
    gameStatus status;;

    do {
        displayBoard(spaces);
        playerMove(spaces, r_player);
        isPlaying = checkWinner(spaces, status, r_player, computer);

        if (!isPlaying)
            break;

        computerMove(spaces, computer);
        isPlaying = checkWinner(spaces, status, r_player, computer);
    } while (isPlaying);

    displayBoard(spaces);
    printOutcome(status);
}

char askForXO() {
    char player;
    bool loop = true;
    while (loop) {
        std::cout << "Do you want to play X or O? [X/O]: ";
        std::cin >> player;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(99999, '\n');
        } else if ('X' == std::toupper(player) || 'O' == std::toupper(player)) {
            return std::toupper(player);
        } else {
            std::cout << "Invalid input." << '\n';
        }
    }

    return 'X';
}

void start() {
    std::cout << "Tic tac toe!" << '\n';
    char input;
    bool playing = true;
    while (playing) {
        std::cout << "Do you want to play? [Y/N]: ";
        std::cin >> input;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(99999, '\n');
        } else if (std::tolower(input) == 'y') {
            char player = askForXO();
            gameLoop(player);
        } else if (std::tolower(input) == 'n') {
            playing = false;
        } else {
            std::cout << "Invalid input." << '\n';
        }
    }
}

void driverTictactoe() {
    start();
    std::cout << "Thank you for playing!" << '\n';
}