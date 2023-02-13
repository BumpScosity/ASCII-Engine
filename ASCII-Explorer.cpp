#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <vector>

void displayGameBoard(const std::vector<std::string>& gameBoard) {
    //system("cls");
    for (const auto& line : gameBoard) {
        std::cout << line << std::endl;
    }
}

int main() {
    // Defining the game board as a vector of strings
    std::vector<std::string> gameBoard = {
        ":::::::::::::::   ::::::::::::::::",
        ":[]           :::::              :",
        ":                                :",
        ":                                :",
        ":             :::::              :",
        ":::::::::::::::   ::::::::::::::::"
    };

    // Displaying the game board
    displayGameBoard(gameBoard);

    // Moving the player
    int playerX = 1;
    int playerY = 1;
    char input;
    bool updateScreen = true;

    while (true) {
        // Update the player position
        input = _getch();
        if (input == 'w' && playerY > 1) {
            if (playerX < 19 && playerX > 12) {
                if (playerY == 3) {
                    playerY--;
                    updateScreen = true;
                }
            }
            else if (playerX < 12 || playerX > 19) {
                playerY--;
                updateScreen = true;
            }
        }
        else if (input == 's' && playerY < 4) {
            if (playerX < 19 && playerX > 12) {
                if (playerY == 2) {
                    playerY++;
                    updateScreen = true;
                }
            }
            else if (playerX < 12 || playerX > 19) {
                playerY++;
                updateScreen = true;
            }
        }
        else if (input == 'a' && playerX > 1) {
            if (playerX == 19) {
                if (playerY != 4 && playerY != 1) {
                    playerX--;
                    updateScreen = true;
                }
            }
            else if (playerX > 12 || playerX < 19) {
                playerX--;
                updateScreen = true;
            }
        }
        else if (input == 'd' && playerX < 31) {
            if (playerX == 12) {
                if (playerY != 4 && playerY != 1) {
                    playerX++;
                    updateScreen = true;
                }
            }
            else if (playerX < 12 || playerX > 19) {
                playerX++;
                updateScreen = true;
            }
            else {
                playerX++;
                updateScreen = true;
            }
        }

        std::vector<std::string> gameBoard = {
        ":::::::::::::::   ::::::::::::::::",
        ":             :::::              :",
        ":                                :",
        ":                                :",
        ":             :::::              :",
        ":::::::::::::::   ::::::::::::::::"
        };

        // Update the game board with the new player position
        gameBoard[playerY][playerX] = '[';
        gameBoard[playerY][playerX + 1] = ']';

        // Display the updated game board
        if (updateScreen) {
            displayGameBoard(gameBoard);
            updateScreen = false;
        }
    }

    return 0;
}
