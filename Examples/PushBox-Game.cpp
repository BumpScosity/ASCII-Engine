#include <iostream>  // Includeing iostream for displaying stuff onto the console
#include <conio.h>  // Includeing conio.h for detecting inputs in windows
#include <cstdlib> // Includeing cstdlib for the randomization
#include <vector> // Includeing vectors for creating the gameboard

// Variables
int PlayerX = 2;
int PlayerY = 1;
int BoxX = 10;
int BoxY = 5;
int EndX = 20;
int EndY = 9;
char input = 1;
bool Run = true;

// The gameboard itself
std::vector<std::string> gameBoard = {
    "::::::::::::::::::::::",
    ":                    :",
    ":                    :",
    ":                    :",
    ":                    :",
    ":                    :",
    ":                    :",
    ":                    :",
    ":                    :",
    ":                    :",
    "::::::::::::::::::::::"
};

// This a function so you can change what it does
void Win() {
    std::cout << std::endl << std::endl << "Congratulations you won!" << std::endl;
    Run = false;
}

// For displaying the game
void Display(std::vector<std::string>& gameBoard) {
    system("cls");

    for (auto& line : gameBoard) {
        size_t player_pos = line.find_first_of("[]");
        if (player_pos != std::string::npos) {
            line[player_pos] = ' ';
            line[player_pos + 1] = ' ';
        }
        size_t box_pos = line.find_first_of("{}");
        if (box_pos != std::string::npos) {
            line[box_pos] = ' ';
            line[box_pos + 1] = ' ';
        }
        size_t end_pos = line.find_first_of("()");
        if (end_pos != std::string::npos) {
            line[end_pos] = ' ';
            line[end_pos + 1] = ' ';
        }
    }

    gameBoard[PlayerY][PlayerX - 1] = '[';
    gameBoard[PlayerY][PlayerX] = ']';
    gameBoard[BoxY][BoxX - 1] = '{';
    gameBoard[BoxY][BoxX] = '}';
    gameBoard[EndY][EndX - 1] = '(';
    gameBoard[EndY][EndX] = ')';

    for (const auto& line : gameBoard) {
        std::cout << line << std::endl;
    }

    std::cout << std::endl << "[] is the player, {} is the box, () is the end, : are the borders." << std::endl << "W to move up, A to move left, S to move down, D to move right.";

    if (BoxX == EndX && BoxY == EndY) {
        Win();
    }
}

// For moving the player around
void Move(std::vector<std::string>& gameBoard) {
    // The W part
    if (input == 'w' && gameBoard[PlayerY - 1][PlayerX] != ':') {
        if (PlayerY - 1 == BoxY && PlayerX == BoxX && gameBoard[BoxY - 1][BoxX] != ':') {
            BoxY--;
        }
        else if (PlayerY - 1 == BoxY && PlayerX == BoxX && gameBoard[BoxY - 1][BoxX] == ':') {
            PlayerY++;
        }
        PlayerY--;
    }
    // The S part
    if (input == 's' && gameBoard[PlayerY + 1][PlayerX] != ':') {
        if (PlayerY + 1 == BoxY && PlayerX == BoxX && gameBoard[BoxY + 1][BoxX] != ':') {
            BoxY++;
        }
        else if (PlayerY + 1 == BoxY && PlayerX == BoxX && gameBoard[BoxY + 1][BoxX] == ':') {
            PlayerY--;
        }
        PlayerY++;
    }
    // The D part
    if (input == 'd' && gameBoard[PlayerY][PlayerX + 1] != ':') {
        if (PlayerY == BoxY && PlayerX + 2 == BoxX && gameBoard[BoxY][BoxX + 1] != ':') {
            BoxX++;
            BoxX++;
        }
        else if (PlayerY == BoxY && PlayerX + 2 == BoxX && gameBoard[BoxY][BoxX + 1] == ':') {
            PlayerX--;
            PlayerX--;
        }
        PlayerX++;
        PlayerX++;
    }
    // The A part
    if (input == 'a' && gameBoard[PlayerY][PlayerX - 2] != ':') {
        if (PlayerY == BoxY && PlayerX - 2 == BoxX && gameBoard[BoxY][BoxX - 2] != ':') {
            BoxX--;
            BoxX--;
        }
        else if (PlayerY == BoxY && PlayerX - 2 == BoxX && gameBoard[BoxY][BoxX - 2] == ':') {
            PlayerX++;
            PlayerX++;
        }
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
