#include<iostream>
#include<fstream>
#include<string>
#include<time.h>
#include <chrono> 
#include "RunGame.cpp"

class PlayGOLMono{
    private:
    public:
        RunGame rungame;
        GameOfLife gameoflife;
        PlayGOLMono(int boardSize, int numThread);
};