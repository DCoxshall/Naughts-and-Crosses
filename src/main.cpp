#include <iostream>

#include "Board.hpp"

int main() {
    Board testBoard = Board();
    testBoard.show();

    std::vector<char> t = testBoard.GetValidMoves();

    return 0;
}