#include "VideoClass.h"
#include "ReadUtils.h"
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

VideoGame::VideoGame() {
 for (int i = 0; i < MAX_CHAR_LEN; i++) {
        Title[i] = '\0';
        Platform[i] = '\0';
        ReleaseDate[i] = '\0';
        Developer[i] = '\0';
        Publisher[i] = '\0';
    }
  Sales = 0.0; 
}

void VideoGame::printGame(ostream &out) {
  out << Title << ";";
  out << Sales << ";";
  out << Platform << ";";
  out << ReleaseDate << ";";
  out << Developer << ";";
  out << Publisher << endl;
}

void VideoGame::readFromUser() {
  cout << "Title: ";
  cin.ignore(100,'\n');
  cin.getline(Title,VideoGame::MAX_CHAR_LEN);
  double tempDouble = readDouble("\nSales: ");
  Sales = tempDouble;
  cout << "\nPlatform: ";
  cin.ignore(100,'\n');
  cin.getline(Platform,VideoGame::MAX_CHAR_LEN);
  cout << "\nRelease Date: ";
  cin.getline(ReleaseDate,VideoGame::MAX_CHAR_LEN);
  cout << "\nDeveloper: ";
  cin.getline(Developer,VideoGame::MAX_CHAR_LEN);
  cout << "\nPublisher: ";
  cin.getline(Publisher,VideoGame::MAX_CHAR_LEN);
  cout << endl;
}

 void VideoGame::readVideoGame(ifstream &inFile) {
  inFile.get(Title, VideoGame::MAX_CHAR_LEN, ';');
  inFile.ignore(100,';');
  inFile >> Sales;
  inFile.ignore(100,';');
  inFile.get(Platform, VideoGame::MAX_CHAR_LEN, ';');
  inFile.ignore(100,';');
  inFile.get(ReleaseDate, VideoGame::MAX_CHAR_LEN, ';');
  inFile.ignore(100,';');
  inFile.get(Developer, VideoGame::MAX_CHAR_LEN, ';');
  inFile.ignore(100,';');
  inFile.get(Publisher, VideoGame::MAX_CHAR_LEN, '\n');
  inFile.ignore(100,'\n');
}

bool VideoGame::isTitle(const char compare[]) {
  if(strcmp(Title,compare) == 0) {
  return true;
  }
  return false;
}

bool VideoGame::isPlatform(const char compare[]) {
  if(strcmp(Platform,compare) == 0) {
  return true;
  }
  return false;
}