#include<iostream>
#include<fstream>
#include<string>
#include "Board.cpp"

class GameOfLife{
    private:
    public:
        Board boardRead;
        Board boardWrite;
        GameOfLife(int n);
        Board getBoardRead();
        void setBoardRead(Board boardRead);
        Board getBoardWrite();
        void setBoardWrite(Board boardWrite);
        void killCell(int n, int m);
        void ressurectCell(int n, int m);
        void stayAlive(int n, int m);
        void stayDead(int n, int m);
        void setupForNextGeneration(int n);
};