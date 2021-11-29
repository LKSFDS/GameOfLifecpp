#include<iostream>
#include<fstream>
#include<string>


class Board{
    private:
        int size;
    public:
        int **board;
        void createMatrix(int n);
        int getSize();
        bool isAlive(int lin, int col);
        void killCell(int lin, int col);
        void resurrectCell(int lin, int col);
        void printBoard();
        int **getBoard();
        void freeMatrix(int n);

};