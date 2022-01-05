#ifndef BOARD_H
#define BOARD_H

#include <vector>

class Board {
public:
    Board();

    std::vector<char> GetValidMoves();
    void show();

    bool CheckIfValidMove(char move);
    char board[3][3];
    char turn;
    int isRobotActive;

private:
};

#endif