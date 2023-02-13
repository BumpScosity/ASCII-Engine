#include <iostream> // Includeing iostream for displaying stuff onto the console
#include <conio.h> // Includeing conio.h for detecting inputs in windows
#include <vector> // Includeing vectors for creating the gameboard
 
// Create variables for the player
int playerX = 1; // The players X positon
int playerY = 1; // The players Y positon
char input; // Storing the input for later

// Create the gameboard for the first display
std::vector<std::string> gameBoard = {
    ":::::::::::::::   ::::::::::::::::",
    ":[]           :::::              :",
    ":                                :",
    ":                                :",
    ":             :::::              :",
    ":::::::::::::::   ::::::::::::::::"
};

// Function for displaying the gameboard
void Display(std::vector<std::string>& gameBoard) {
    system("cls"); // Clear the console
    for (const auto& line : gameBoard) {
        std::cout << line << std::endl; // Display the gameboard
    }
}

// Function for refreshing the gameboard
void Refresh() {
    // Cleaning the gameboard
    std::vector<std::string> gameBoard = {
        ":::::::::::::::   ::::::::::::::::",
        ":             :::::              :",
        ":                                :",
        ":                                :",
        ":             :::::              :",
        ":::::::::::::::   ::::::::::::::::"
    };

    // Adding the player to the gameboard
    gameBoard[playerY][playerX] = '['; 
    gameBoard[playerY][playerX + 1] = ']';

    Display(gameBoard); // Calling the display function
}

void Move() {
    if (input == 'w' && playerY > 1) { // Checking if the key is W
        if (playerX < 19 && playerX > 12) { // Checking the players X positon
            if (playerY == 3) { // Checking the players Y position
                playerY--; // Moving the the player up
            }
        }
        else { // If the players X positon is not one of those
            playerY--; // Moving the the player up
        }
    }
    else if (input == 's' && playerY < 4) { // Checking if the key is S
        if (playerX < 19 && playerX > 12) { // Checking the players X postion
            if (playerY == 2) {// Checking the players Y position
                playerY++; // Moving the player down
            }
        }
        else { // If the players X positon is not one of those
            playerY++; // Moving the player down
        }
    }
    else if (input == 'a' && playerX > 1) { // Checking if the key is A
        if (playerX == 19) { // Checking the players X postion
            if (playerY != 4 && playerY != 1) { // Checking the players Y position
                playerX--; // Moving the player left
            }
        }
        else if (playerX > 12 || playerX < 19) { // If the players X positon isn't 19 execute this code
            playerX--; // Moving the player left
        }
        else { // If both are false execute this code
            playerX--; // Moving the player right
        }
    }
    else if (input == 'd' && playerX < 31) { // Checking if the key is D
        if (playerX == 12) { // Checking the players X position
            if (playerY != 4 && playerY != 1) { // Checking the players Y positon
                playerX++; // Moving the player right
            }
        }
        else if (playerX < 12 || playerX > 19) { // If the players X positon isn't 12 execute this code
            playerX++; // Moving the player right
        }
        else { // If both are false execute this code
            playerX++; // Moving the player right
        } 
    }
    Refresh(); // Calling the Refresh function
}

int main() { // Starting the program
    Display(gameBoard); // Displaying the gameboard for the first time

    while (true) {
        // Key inputs and calling functions
        input = _getch(); // Detecting key inputs
        if (input != 0) { // Checking if there was a input
            Move(); // Calling the Move function
            input = 0; // Reseting the input once moved
        }
    }
    return 0; // Ending the function
}
