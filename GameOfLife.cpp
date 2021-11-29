#include "GameOfLife.h"

using namespace std;

GameOfLife::GameOfLife(int n){
    boardRead.createMatrix(n);
    boardWrite.createMatrix(n);
    boardRead.resurrectCell(2,1);
    boardRead.resurrectCell(2,3);
    //boardRead.resurrectCell(3,1);
    boardRead.resurrectCell(3,2);
    boardRead.resurrectCell(3,3);
    /*boardRead.resurrectCell(12,31);
    boardRead.resurrectCell(12,32);
    boardRead.resurrectCell(11,32);
    boardRead.resurrectCell(13,32);
    boardRead.resurrectCell(11,33);*/
}

Board GameOfLife::getBoardRead(){
    return boardRead;
}

void GameOfLife::setBoardRead(Board boardRead){
    boardRead = boardRead;
}

Board GameOfLife::getBoardWrite(){
    return boardWrite;
}

void GameOfLife::setBoardWrite(Board boardWrite){
    boardWrite = boardWrite;
}

void GameOfLife::killCell(int n, int m){
    boardWrite.killCell(n,m); 
}

void GameOfLife::ressurectCell(int n, int m){
    boardWrite.resurrectCell(n,m);
}

void GameOfLife::stayAlive(int n, int m){
    getBoardWrite().resurrectCell(n,m);
}


void GameOfLife::stayDead(int n, int m){
    getBoardWrite().killCell(n,m);
}

void GameOfLife::setupForNextGeneration(int n){
    boardRead.freeMatrix(n);
    boardRead = boardWrite;
    Board aux;
    boardWrite = aux;
    boardWrite.createMatrix(n);
}


