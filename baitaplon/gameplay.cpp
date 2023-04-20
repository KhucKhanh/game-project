#include "board.h"


void copyBoard(int a[BOARD_BLOCK_NUM][BOARD_BLOCK_NUM], int b[BOARD_BLOCK_NUM][BOARD_BLOCK_NUM])
{
    for(int i=0; i< BOARD_BLOCK_NUM; i++){
        for(int j=0; j< BOARD_BLOCK_NUM; j++)
            b[i][j]=a[i][j];
    }
}
int Board::gBlock(int x, int y){
    int b=1;
    for(int i=0; i<board[x][y]; i++){
        b*=2;
    }
	return b;
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

bool Board::moveup()
{
    bool moved = false;
    for(int i=0; i<BOARD_BLOCK_NUM; i++){
        int k=0, j=1;
        while(j <BOARD_BLOCK_NUM){
            if(board[j][i] == Empty){
                j++; //check o [i][j] neu rong thi bo qua
            }
            else if(board[k][i] == Empty){
                board[k][i] = board[j][i];
                board[j][i] = Empty;
                j++;
                moved = true;
                // thay the o [k][i] = [j][i]
            }
            else if(board[j][i] == board[k][i]){
                board[k][i]++;
                score+= gBlock(k,i);
                k++;
                board[j][i] = Empty;
                j++;
                moved = true;
                // gop 2 o giong nhau
            }
            else if(j!=k+1){
                k++;
                board[k][i] = board[j][i];
                board[j][i]= Empty;
                moved = true;
            //keo 2 o lai gan nhau
            }
            else {
                j++;
                k++;
                // 2 o lien ke khac nhau thi xet cap tiep theo
            }
        }
    }
    return moved;
}

bool Board::movedown()
{
    bool moved = false;
    for(int i=0; i<BOARD_BLOCK_NUM; i++){
        int k = BOARD_BLOCK_NUM -1, j = k-1;
        while(j >= 0){
            if(board[j][i] == Empty){
                j--; //check o [j][i] neu rong thi bo qua
            }
            else if(board[k][i] == Empty){
                board[k][i] = board[j][i];
                board[j][i] = Empty;
                j--;
                moved = true;
                //thay the o [k][i] = o [j][i]
                }
            else if(board[j][i] == board[k][i]){
                board[k][i]++;
                score += gBlock(k, i);
                k--;
                board[j][i] = Empty;
                j--;
                moved = true;
                // gop 2 o giong nhau
            }
            else if(j!= k-1){
                k--;
                board[k][i] = board[j][i];
                board[j][i] = Empty;
                j--;
                moved = true;
                // keo gan 2 o khac nhau lai gan nhau
            }
            else {
                j--;
                k--;
                // xet 2 cap khac
            }
        }
    }
    return moved;
}
bool Board::moveleft(){
	bool moved = false;
	for(int i = 0; i < BOARD_BLOCK_NUM ; i++){
		int k = 0, j = 1;
		while(j < BOARD_BLOCK_NUM){
			if(board[i][j]==Empty){
				j++;
			}
			else if(board[i][k] == Empty){
				board[i][k] = board[i][j];
				board[i][j] = Empty;
				j++;
				moved = true;
			}
			else if(board[i][j] == board[i][k]){
				board[i][k]++;
				score += gBlock(i, k);
				k++;
				board[i][j] = Empty;
				j++;
				moved = true;
			}
			else if(j!=k+1){
                k++;
				board[i][k] = board[i][j];
				board[i][j] = Empty;
                j++;
				moved = true;
			}
			else{
				j++;
				k++;
			}
		}
	}
	return moved;
}
bool Board::moveright()
{
    bool moved = false;
    for(int i=0; i<BOARD_BLOCK_NUM; i++){
        int k= BOARD_BLOCK_NUM-1, j= k-1;
        while(j>=0){
            if(board[i][j] == Empty){
                j--; //check o [i][j] neu rong thi bo qua
            }
            else if(board[i][k] == Empty){
                board[i][k] = board[i][j];
                board[i][j] =Empty;
                j--;
                moved = true;
                //thay the o [i][k]= o [i][j]
            }
            else if(board[i][j] == board[i][k]){
                board[i][k]++;
                score+= gBlock(i, k);
                k--;
                board[i][j] = Empty;
                j--;
                moved = true;
                // gop 2 o giong nhau
            }
            else if(j!= k-1){
                k--;
                board[i][k] = board[i][j];
                board[i][j]= Empty;
                j--;
                moved = true;
                // keo 2 o gan nhau
            }
            else{
                j--;
                k--;
                // xet 2 o khac
            }
        }
    }
    return moved;
}
bool Board::gameisover()
{
    if(!FULL()){
        return false;
    }
    int temp[BOARD_BLOCK_NUM][BOARD_BLOCK_NUM];
    copyBoard(board, temp);
    if(moveup()){
        copyBoard(temp,board);
        return false;
    }
    if(movedown()){
        copyBoard(temp,board);
        return false;
    }
    if(moveleft()){
        copyBoard(temp,board);
        return false;
    }
    if(moveright()){
        copyBoard(temp,board);
        return false;
    }
    return true;
}
long Board::gScore(){
    return score;
}

void Board::gNewBlock()
{
    int freeSlots[BOARD_BLOCK_NUM*BOARD_BLOCK_NUM];
    int freeNum =0;
    for(int i=0; i<BOARD_BLOCK_NUM; i++){
        for(int j=0; j<BOARD_BLOCK_NUM; j++){
            if(board[i][j]== Empty){
                freeSlots[freeNum] = i*BOARD_BLOCK_NUM +j;
                freeNum++;
            }
        }
    }
    int n = gRandom(0, freeNum-1);
    board[freeSlots[n]/BOARD_BLOCK_NUM][freeSlots[n]%BOARD_BLOCK_NUM] = gRandom(1, Newmax);
}

bool Board::move(int dir)
{
    bool change =false;
    switch(dir){
    case MOVE_UP:
        change = moveup();
        break;
    case MOVE_DOWN:
        change = movedown();
        break;
    case MOVE_LEFT:
        change = moveleft();
        break;
    case MOVE_RIGHT:
        change = moveright();
        break;
    }
    if(change){
        gNewBlock();
    }
    return change;
}


