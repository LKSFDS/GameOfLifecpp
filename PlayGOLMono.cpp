#include "PlayGOLMono.h"
namespace sc = std::chrono;

using namespace std;

PlayGOLMono::PlayGOLMono(int _boardSize, int _numThreads):gameoflife(_boardSize),rungame(_numThreads, gameoflife){}

/*int main(){

    int mSize, numGen, nThread;

    cout<<"Informe o tamanho da matrix"<<endl;
    cin >> mSize;

    cout<<"Informe o numero de geracoes"<<endl;
    cin >> numGen;

    cout<<"Informe o numero de Threads"<<endl;
    cin >> nThread;

    PlayGOLMono playGol(mSize, nThread);

    //auto since_epoch = time.time_since_epoch();

    for(int i = 0; i < numGen; i++){
        int cont = 0;
        for(int l = 0; l < mSize; l++){
            for(int m = 0; m < mSize; m++){
                if(playGol.gameoflife.getBoardRead().isAlive(l,m)){
                    cont++;
                }
            }
        }
        playGol.gameoflife.getBoardRead().printBoard();
        cout<<"\n"<<endl;
        playGol.gameoflife.getBoardWrite().printBoard();
        cout<<"\n"<<endl;
        playGol.rungame.run();
        playGol.gameoflife.getBoardRead().printBoard();
        cout<<"\n"<<endl;
        playGol.gameoflife.getBoardWrite().printBoard();

        cout<<"\n"<<endl;
        playGol.gameoflife.setupForNextGeneration(mSize);

    }


    return 0;
}*/

