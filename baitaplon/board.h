#ifndef __BOARD_H__
#define __BOARD_H__

#include <stdlib.h>
#include<time.h>

enum move_type {
    MOVE_UP=0,
    MOVE_DOWN=1,
    MOVE_LEFT=2,
    MOVE_RIGHT=3,
    NO_MOVE
};

const int BOARD_BLOCK_NUM = 7;
void copyBoard(int a[BOARD_BLOCK_NUM][BOARD_BLOCK_NUM], int b[BOARD_BLOCK_NUM][BOARD_BLOCK_NUM]);
class Board
{
public:
    Board();
    void init();
    bool move(int dir);
    int gBlock(int x, int y);
    bool FULL();
    bool gameisover();
    long int gScore();



private:
    int board[BOARD_BLOCK_NUM][BOARD_BLOCK_NUM];
    int Empty;
    int Newmax;
    long int score;

    bool moveup();
    bool movedown();
    bool moveleft();
    bool moveright();
    int gRandom(int low, int high);
    void gNewBlock();

};
#endif // __BOARD_H__

