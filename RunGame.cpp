#include "RunGame.h"
#include <omp.h>

using namespace std;

RunGame::RunGame(int _nThreads, GameOfLife _gameoflife):nThreads(_nThreads),gameoflife(_gameoflife){}

void RunGame::run(Board boardRead, Board boardWrite) {
        int num = boardRead.getSize()-1;
        int cont;
        #pragma omp parallel for num_threads(nThreads);
        for(int i = 0; i < num; i++){
            for(int j = 0; j < num; j++){
                cont = 0;
                if(i == 0 && j == 0){
                    if(boardRead.isAlive(0, 1)) cont++; // direita
                    if(boardRead.isAlive(1, 0)) cont++; // baixo
                    if(boardRead.isAlive(1, 1)) cont++; // diagonal inf direita
                    if(boardRead.isAlive(1, num)) cont++; // diagonal inf esquerda
                    if(boardRead.isAlive(num, num)) cont++; // diagonal sup esquerda
                    if(boardRead.isAlive(num, 1)) cont++; // diagonal sup direita
                    if(boardRead.isAlive(num, 0)) cont++; // cima
                    if(boardRead.isAlive(0, num)) cont++; // esquerda
                }

                else if(i == 0 && j == num){
                    if(boardRead.isAlive(0, num-1)) cont++; // esquerda
                    if(boardRead.isAlive(1, num)) cont++; // baixo
                    if(boardRead.isAlive(1, num-1)) cont++; // diagonal inf esquerda
                    if(boardRead.isAlive(num, num-1)) cont++; // diagonal sup esquerda
                    if(boardRead.isAlive(num, num)) cont++; // cima
                    if(boardRead.isAlive(num, 0)) cont++; // diagonal sup direita
                    if(boardRead.isAlive(0, 0)) cont++; //direita
                    if(boardRead.isAlive(1, 0)) cont++; // diagonal inf direita
                }

                else if(i == num && j == 0){
                    if(boardRead.isAlive(num-1, 0)) cont++; // cima
                    if(boardRead.isAlive(num, 1)) cont++; // direita
                    if(boardRead.isAlive(num-1, 1)) cont++; // diagonal sup direita
                    if(boardRead.isAlive(num-1, num)) cont++; // diagonal sup esquerda
                    if(boardRead.isAlive(num, num)) cont++; // esquerda
                    if(boardRead.isAlive(0, num)) cont++; // diagonal inf esquerda
                    if(boardRead.isAlive(0, 0)) cont++; // baixo
                    if(boardRead.isAlive(0, 1)) cont++; // diagonal inf direita
                }
                else if(i == num && j == num) {
                    if (boardRead.isAlive(num, num - 1)) cont++; // cima
                    if (boardRead.isAlive(num - 1, num)) cont++; // esquerda
                    if (boardRead.isAlive(num - 1, num - 1)) cont++; // diagonal sup esquerda
                    if (boardRead.isAlive(num - 1, 0)) cont++; // diagonal sup direita
                    if (boardRead.isAlive(num, 0)) cont++; // direita
                    if (boardRead.isAlive(0, 0)) cont++; // diagonal inf direita
                    if (boardRead.isAlive(0, num)) cont++; // baixo
                    if (boardRead.isAlive(0, num - 1)) cont++; // diagonal inf esquerda
                }

                else if(i == 0 && j != 0 && j != num){
                    if(boardRead.isAlive(0, j-1)) cont++; // esquerda
                    if(boardRead.isAlive(0, j+1)) cont++; // direita
                    if(boardRead.isAlive(1, j+1)) cont++; // diagonal direita
                    if(boardRead.isAlive(1, j)) cont++; // baixo
                    if(boardRead.isAlive(1, j-1)) cont++; // diagonal esquerda
                    if(boardRead.isAlive(num, j-1)) cont++; // diagonal sup esquerda
                    if(boardRead.isAlive(num, j)) cont++; // cima
                    if(boardRead.isAlive(num, j+1)) cont++; // diagonal sup direita
                }

                else if(j == 0 && i !=0 && i != num){
                    if(boardRead.isAlive(i-1, 0)) cont++; // cima
                    if(boardRead.isAlive(i-1, 1)) cont++; // diagonal cima
                    if(boardRead.isAlive(i, 1)) cont++; // direita
                    if(boardRead.isAlive(i+1, 1)) cont++; // diagonal baixo
                    if(boardRead.isAlive(i+1, 0)) cont++; // baixo
                    if(boardRead.isAlive(i-1, num)) cont++; // diagonal sup esquerda
                    if(boardRead.isAlive(i, num)) cont++; // esquerda
                    if(boardRead.isAlive(i+1, num)) cont++; // diagonal inf esquerda
                }

                else if(j == num && i !=0 && i != num){
                    if(boardRead.isAlive(i-1, num)) cont++; // cima
                    if(boardRead.isAlive(i-1, num-1)) cont++; // diagonal cima
                    if(boardRead.isAlive(i, num-1)) cont++; // esquerda
                    if(boardRead.isAlive(i+1, num-1)) cont++; // diagonal baixo
                    if(boardRead.isAlive(i+1, num)) cont++; // baixo
                    if(boardRead.isAlive(i-1, 0)) cont++; // diagonal sup direita
                    if(boardRead.isAlive(i, 0)) cont++; // direita
                    if(boardRead.isAlive(i+1, 0)) cont++; // diagonal inf direita
                }

                else if(i == num && j != 0 && j != num){
                    if(boardRead.isAlive(num, j-1)) cont++; // esquerda
                    if(boardRead.isAlive(num-1, j-1)) cont++; // diagonal esquerda
                    if(boardRead.isAlive(num-1, j)) cont++; // cima
                    if(boardRead.isAlive(num-1, j+1)) cont++; // diagonal direita
                    if(boardRead.isAlive(num, j+1)) cont++; // direita
                    if(boardRead.isAlive(0, j-1)) cont++; // diagonal inf esquerda
                    if(boardRead.isAlive(0, j)) cont++; // baixo
                    if(boardRead.isAlive(0, j+1)) cont++; // diagonal inf direita
                }

                else {
                    if (boardRead.isAlive(i - 1, j - 1)) cont++; // diagonal sup esquerda
                    if (boardRead.isAlive(i - 1, j)) cont++; // cima
                    if (boardRead.isAlive(i - 1, j + 1)) cont++; // diagonal sup direita
                    if (boardRead.isAlive(i, j + 1)) cont++; // direita
                    if (boardRead.isAlive(i + 1, j + 1)) cont++; // diagonal inf direita
                    if (boardRead.isAlive(i + 1, j)) cont++; // baixo
                    if (boardRead.isAlive(i + 1, j - 1)) cont++; // diagonal inf esquerda
                    if (boardRead.isAlive(i, j - 1)) cont++; // esquerda
                }

                if(boardRead.isAlive(i,j)){ // is alive
                    if(cont < 2 || cont > 3){ // and at least 2/3 are dead
                        boardWrite.killCell(i,j);
                    } else {
                        boardWrite.resurrectCell(i,j);
                    }
                }
                else{
                    if(cont == 3){
                        boardWrite.resurrectCell(i,j);
                    } else {
                        boardWrite.killCell(i,j);
                    }
                }
            }
        }
    }

int main(int argc, char const *argv[]){

    
    GameOfLife tabuleiro(5);
    RunGame rungame(2, tabuleiro);
    tabuleiro.boardRead.printBoard();
    cout<<"ESPAÇO"<<endl;
    tabuleiro.getBoardWrite().printBoard();
    cout<<"ESPAÇO"<<endl;
    rungame.run(tabuleiro.boardRead, tabuleiro.boardWrite);
    tabuleiro.setupForNextGeneration(5);
    tabuleiro.boardRead.printBoard();
    cout<<"ESPAÇO"<<endl;
    tabuleiro.getBoardWrite().printBoard();
    cout<<"ESPAÇO"<<endl;
    rungame.run(tabuleiro.boardRead, tabuleiro.boardWrite);
    tabuleiro.setupForNextGeneration(5);
    tabuleiro.boardRead.printBoard();
    cout<<"ESPAÇO"<<endl;
    tabuleiro.boardWrite.printBoard();
    cout<<"ESPAÇO"<<endl;
    rungame.run(tabuleiro.boardRead, tabuleiro.boardWrite);
    tabuleiro.setupForNextGeneration(5);
    tabuleiro.boardRead.printBoard();
    cout<<"ESPAÇO"<<endl;
    tabuleiro.boardWrite.printBoard();


    return 0;
}