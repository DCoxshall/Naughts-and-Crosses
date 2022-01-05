#ifndef BOARD_H
#define BOARD_H

#include <vector>

class Board {
public:
    Board();

    std::vector<int> get_valid_moves();
    void show();

    char board[3][3];
    char turn;

private:
};

#endif