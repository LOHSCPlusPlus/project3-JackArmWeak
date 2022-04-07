#include <iostream>
#include <fstream>
using namespace std;

class VideoGame {
  public:
    VideoGame();
    void printGame(ostream &out);
    void readFromUser(); //"new" splitting old add function into reading and validiting if you can add
    void readVideoGame(ifstream &inFile);
    bool isTitle(const char compare[]);
    bool isPlatform(const char compare[]);
  private:
    enum {MAX_CHAR_LEN = 100};
    char Title[MAX_CHAR_LEN];
    double Sales;
    char Platform[MAX_CHAR_LEN];
    char ReleaseDate[MAX_CHAR_LEN];
    char Developer[MAX_CHAR_LEN];
    char Publisher[MAX_CHAR_LEN];
};