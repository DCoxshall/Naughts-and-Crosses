#include "Board.hpp"

#include <algorithm>
#include <iostream>
#include <string>

Board::Board() {
    // Initialise the array of characters to match the numbers on a standard
    // numpad
    std::vector<char> digits = {'3', '2', 'X', '6', '5', '4', '9', '8', '7'};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = digits.back();
            digits.pop_back();
        }
    }

    // Initialise turn to 'X'
    turn = 'X';

    // Ask the player if they want to play against the computer or with another
    // human and update isRobotActive as appropriate
    std::cout << "Would you like to play against the computer? [y/n]: ";
    std::string input;
    std::cin >> input;
    std::cout << "\n";
    if (input.find('y') != std::string::npos ||  // If the player input 'yes'
        input.find('Y') != std::string::npos) {
        isRobotActive = 1;
        std::cout << "You are playing against the computer! \n";
    } else {
        isRobotActive = 0;
        std::cout << "You are playing against a friend! \n";
    }
}

bool Board::CheckIfValidMove(char move) {
    std::vector<char> validMoves = GetValidMoves();

    // If move is in validMoves
    if (std::find(validMoves.begin(), validMoves.end(), move) !=
        validMoves.end()) {
        return true;
    }
    return false;
}

// Return a vector of chars representing all the possible valid moves
std::vector<char> Board::GetValidMoves() {
    std::vector<char> validMoves;
    std::vector<char> digits = {'7', '8', '9', '4', '5', '6', '1', '2', '3'};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (digits[i * 3 + j] == board[i][j]) {
                validMoves.push_back(digits[i * 3 + j]);
            }
        }
    }

    return validMoves;
}

// Prints the board to the console
void Board::show() {
    printf("---START BOARD---\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("-----------------\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("-----------------\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("---END BOARD---");
}
