#include <iostream>
#include <fstream>
#ifndef FILE_READER 
#define FILE_READER 

using namespace std;

istream* fileReader(string filePath){

  ifstream in(filePath);
  streambuf *cinbuf = std::cin.rdbuf(); 
  cin.rdbuf(in.rdbuf());

  return &cin;
}

#endif