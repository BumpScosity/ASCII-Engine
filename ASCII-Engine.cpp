#include <iostream>  // Includeing iostream for displaying stuff onto the console
#include <conio.h>  // Includeing conio.h for detecting inputs in windows
#include <vector> // Includeing vectors for creating the gameboard

// Variables
int PlayerX = 3;
int PlayerY = 1;
char input = 1;
bool Run = true;

// Here is the game board, feel free to edit it by following these rules. (:
// Rule 1: all ':' are walls
// Rule 2: anything that is not a ':' will be counted as a empty space and will have to be coded it
// Rule 3: If it is off the grid the player will be able to break out of the gameboard and break the game
std::vector<std::string> gameBoard = {
    "::::::::::::::::::::::::      ::::::::::::::::::::::::",
    "::                    ::      ::                    ::",
    "::                    ::      ::                    ::",     
    "::                    ::::::::::                    ::",
    "::                                                  ::",
    "::                                                  ::",
    "::                                                  ::",
    "::                    ::::::::::                    ::",
    "::                    ::      ::                    ::",
    "::                    ::      ::                    ::",
    "::::::::::    ::::::::::      ::::::::::    ::::::::::",
    "        ::    ::                      ::    ::",
    "        ::    ::                      ::    ::",
    "        ::    ::                      ::    ::",
    "::::::::::    ::::::::::      ::::::::::    ::::::::::",
    "::                    ::      ::                    ::",
    "::                    ::      ::                    ::",
    "::                    ::::::::::                    ::",
    "::                                                  ::",
    "::                                                  ::",
    "::                                                  ::",
    "::                    ::::::::::                    ::",
    "::                    ::      ::                    ::",
    "::                    ::      ::                    ::",
    "::::::::::::::::::::::::      ::::::::::::::::::::::::"
};

// For displaying the game
void Display(std::vector<std::string>& gameBoard) {
    system("cls");

    for (auto& line : gameBoard) {
        size_t player_pos = line.find_first_of("[]");
        if (player_pos != std::string::npos) {
            line[player_pos] = ' ';
            line[player_pos + 1] = ' ';
        }
    }

    gameBoard[PlayerY][PlayerX - 1] = '[';
    gameBoard[PlayerY][PlayerX] = ']';

    for (const auto& line : gameBoard) {
        std::cout << line << std::endl;
    }

    std::cout << std::endl << "'[]' is the player, ':' are the borders." << std::endl << "W to move up, A to move left, S to move down, D to move right.";
}

// For moving the player around
void Move(std::vector<std::string>& gameBoard) {
    // The W part
    if (input == 'w' && gameBoard[PlayerY - 1][PlayerX] != ':') {
        PlayerY--;
    }
    // The S part
    if (input == 's' && gameBoard[PlayerY + 1][PlayerX] != ':') {
        PlayerY++;
    }
    // The D part
    if (input == 'd' && gameBoard[PlayerY][PlayerX + 1] != ':') {
        PlayerX++;
        PlayerX++;
    }
    // The A part
    if (input == 'a' && gameBoard[PlayerY][PlayerX - 2] != ':') {
        PlayerX--;
        PlayerX--;
    }
    Display(gameBoard);
}

// For starting the game and detecting inputs
int main() {
    Display(gameBoard);

    while (Run) {
        input = _getch();
        if (input != 0) {
            Move(gameBoard);
            input = 0;
        }

    }
    return 0; // Ending the game
}
