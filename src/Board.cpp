#include "Board.hpp"

#include <iostream>

Board::Board() {
    // Initialise the array of characters to match the numbers on a standard
    // numpad
    std::vector<char> digits = {'0', '1', '2', '3', '4',
                                '5', '6', '7', '8', '9'};
    for (int i = 0; i < 3; i++) {
        for (int j = 2; j > -1; j--) {
            board[i][j] = digits.back();
            digits.pop_back();
        }
    }
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
