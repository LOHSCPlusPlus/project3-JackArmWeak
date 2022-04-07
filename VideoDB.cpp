#include "VideoDB.h"
#include "ReadUtils.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


//Sets Everything to 0
VideoDB::VideoDB() {
  numGames = 0;
  read();
}

void VideoDB::read() {
    ifstream gameFile("videogames.txt");
    while(gameFile.peek() != EOF && numGames < MAX_GAMES) {
        gameList[numGames].readVideoGame(gameFile);
        numGames++;
    }
}

void VideoDB::printAllGames() {
    for(int i = 0; i < numGames; i++) {
      cout << "Index " << i << ": ";
      gameList[i].printGame(cout);
      cout << endl;
    }
}

int VideoDB::reload() {
  ifstream gameFile("videogames.txt");
  VideoGame tempList[100];
  int temp = 0;
  while(gameFile.peek() != EOF) {
    tempList[temp].readVideoGame(gameFile);
    temp++;
    }  
  //Reloading list  
  for(int i = 0; i < MAX_GAMES; i++) {
    gameList[i] = tempList[i];
  }
  return temp;
}

//Adds Games
void VideoDB::addGame() {
  bool isGameAdded = false;
  for(int i = 0; i < MAX_GAMES; i++) {
    //Looping until it finds an empty slot for game (should always be at the end of the array)
    if(gameList[i].isTitle("") == true) {
      gameList[i].readFromUser();
      isGameAdded = true;
    }
  }
  if(isGameAdded == false) {
    cout << "Sorry! The array is full already" << endl;
  }
}

//Removes Games
void VideoDB::removeGame() {
  int deleteindex = -1;
  //Bounds for removing
  while(deleteindex < 0 || deleteindex > numGames-1) {
  cout << "Which game would you like to delete (0-" << numGames-1 << ")";
  deleteindex = readDouble("\nInput: ");
  }
  for(int i = deleteindex; i < numGames; i++) {
    gameList[i] = gameList[i+1];
  }
  cout << endl;
  cout << "Sucess! Game " << deleteindex << " has been removed.\n" << endl;
}

//Prints data of specific video games to screen
void VideoDB::printDSGames() {
    for(int i = 0; i < numGames; i++) {
      if(gameList[i].isPlatform("Nintendo DS") == true) {
        cout << "Index " << i << ": ";
        gameList[i].printGame(cout);
        cout << endl;
      }
    }
}

void VideoDB::gameListToFile(const char fileName[]) {
  ofstream outFile(fileName);
  for(int i = 0; i < numGames; i++) {
      gameList[i].printGame(outFile);
    }
}

void VideoDB::resetFile(const char fileName[]) {
  ifstream masterFile("mastervideogames.txt");
  ofstream outFile(fileName);
  //Loading mastervideogames.txt into tempList
  int counter = 0;
  VideoGame tempList[MAX_GAMES];
  while(masterFile.peek() != EOF) {
    tempList[counter].readVideoGame(masterFile);
    counter++;
  }
  //Should print every line of mastervideogames.txt into videogames.txt
  for(int i = 0; i < counter; i++) {
    tempList[i].printGame(outFile);
  }
}

void VideoDB::insertGame() {
  for(int i = 0; i < MAX_GAMES; i++) {
    if(gameList[i].isTitle("") == true) {
      int user = readInt("Where would you like to insert your game?");
      cout << endl;
      for(int insIndex = numGames; insIndex >= user; insIndex--) {
        gameList[insIndex-1] = gameList[insIndex];
      }
      break;
    }
  }
  
}