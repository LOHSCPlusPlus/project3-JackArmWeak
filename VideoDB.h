#include "VideoClass.h"
#include <iostream>
#include <fstream>
using namespace std;

class VideoDB {
  public:
    VideoDB();
    void read();
    void printAllGames();
    int reload();
    void addGame();
    void removeGame();
    void printDSGames();
    void gameListToFile(const char fileName[]); 
    void resetFile(const char fileName[]);
    void insertGame();
  private:
    enum {MAX_GAMES = 100};
    VideoGame gameList[MAX_GAMES];
    int numGames;
};