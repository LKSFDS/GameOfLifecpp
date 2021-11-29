#include "Board.h"

using namespace std;

void Board::createMatrix(int n){
    size = n;
    board = new int*[n];
    for(int i = 0; i < n; i++){
        board[i] = new int[n];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            board[i][j] = 0;
        }
    }
}

int Board::getSize(){
    return size;
}

bool Board::isAlive(int lin, int col){
    return !board[lin][col] == 0;
}

void Board::killCell(int lin, int col){
    board[lin][col] = 0;
}

void Board::resurrectCell(int lin, int col){
    board[lin][col] = 1;
}

void Board::printBoard(){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<"\n"<<endl;
    }
}

int **Board::getBoard(){
    return board;
}

void Board::freeMatrix(int n){
    int i;
    for(i = 0; i < n; i++){
        delete(board[i]);
    }
    delete(board);
}