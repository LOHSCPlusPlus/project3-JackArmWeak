#include "VideoDB.h"
#include "ReadUtils.h"
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

//Menu function
int menu() {
  int menuChoice = 0;
  int temp = 0;
  cout << "Welcome to our Video Game Database!" << endl;
  cout << "Please choose from the following options: (1, 2, etc)" << endl;
  cout << "1) Reload database from the file" << endl;
  cout << "2) Print database" << endl;
  cout << "3) Add new entry" << endl;
  cout << "4) Remove entry" << endl;
  cout << "5) Print all video games for the Nintendo DS" << endl;
  cout << "6) Save database to the file" << endl;
  cout << "7) Reset file (videogames.txt)" << endl;
  cout << "8) Quit" << endl;
  temp = readDouble("\nInput: ");
  menuChoice = temp;
  cout << endl;
  //Return user choice 
  return menuChoice;
}

const int MAX_GAMES = 100;

int main() {
//Delcaring Variables
  int menuSelect = 0;
  int counter = 0;
  int constantCount = 0;
  //Reading data into gameList from the videogames.txt file

  VideoDB gameList;
 
  menuSelect = menu();

  //Menu Select Tree
  while(menuSelect != 8) {
    switch(menuSelect) {
      //Reload Database
      case 1:
        //redefines counter since Database is being reset
        constantCount = gameList.reload();
        counter = constantCount;
        cout << "Success! Database has been reloaded.\n" << endl;
        break;
      //Print Database
      case 2:
        gameList.printAllGames();
        break;
      //Adding new entry
      case 3:
        gameList.addGame();
        counter++;
        break;
      //Removing entry
      case 4:
        gameList.removeGame();
        counter--;
        break;
      //Print all games for DS
      case 5:
        gameList.printDSGames();
        break;
      //Save current Database back to file
      case 6:
        gameList.gameListToFile("videogames.txt");
        cout << "\nSuccess! The current Database has been transfered to the videogames.txt file.\n" << endl;
        break;
      //Reset videogames.txt file
      case 7:
        gameList.resetFile("videogames.txt");
      //Quit
      case 8:
        break;
      //Safety
      default :
        cout << "\nInvalid Selection! Please Try Again" << endl;
        break;
  }
  menuSelect = menu();
}
}
