#include<iostream>
#include<fstream>
#include<string>
#include "GameOfLife.cpp"

class RunGame{
    private:
        int nThreads;
        GameOfLife gameoflife;
        
    public:
        RunGame(int nThreads, GameOfLife gameoflife);
        void run(Board boardRead, Board boardWrite);
};