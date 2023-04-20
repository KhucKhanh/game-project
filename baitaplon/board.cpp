#include "board.h"

void copyBoard(int a[BOARD_BLOCK_NUM][BOARD_BLOCK_NUM], int b[BOARD_BLOCK_NUM][BOARD_BLOCK_NUM])
{
    for(int i=0; i< BOARD_BLOCK_NUM; i++){
        for(int j=0; j< BOARD_BLOCK_NUM; j++)
            b[i][j]=a[i][j];
    }
}

Board::Board()
{
    Empty=0;
}

void Board::init()
{
    srand(time(NULL));
    for(int i=0; i< BOARD_BLOCK_NUM; i++)
    {
        for(int j=0; j< BOARD_BLOCK_NUM; j++)
        board[i][j] = Empty;
    }
    score =0;
    board[gRandom(0,3)][gRandom(0,6)] = 1;
    board[gRandom(4,6)][gRandom(0,6)] = 1;
    Newmax =2;
}
int Board::gRandom(int low, int high)
{
    return (rand()%(high-low+1)+low); // low -> high
}

bool Board::FULL()
{
    for(int i=0; i<BOARD_BLOCK_NUM; i++){
        for(int j=0; j<BOARD_BLOCK_NUM; j++){
            if(board[i][j] == Empty) return false;
        }
    }
    return true;
}

long Board::newscore(int n)
{
    return 2*n;
}



