// Copyright 2025 Jerard

#include "word_search_functions.h"
#include<iostream>
#include<fstream> // for file handling

using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;

//Reads the word search grid from a file
bool ReadWordSearch(string file_name, char word_search[][kSize])  {
  ifstream file(file_name);

  if(!file)  {
    cerr << "Error: Could not open file grid.txt" << endl;
    return false;
  }

  for(int i = 0; i < kSize; ++i)  {
    for(int j = 0; j < kSize; ++j)  {
     file >> word_search[i][j];
     if(file.eof()) {
       cerr << "Not enough characters in file" << endl;
       return false;
     }
     }
  }

  file.close();
  return true;
}


void PrintWordSearch(const char word_search[][kSize]){
  for(int i = 0; i < kSize; ++i)  {
    for(int j = 0; j < kSize; ++j)  {
      cout << word_search[i][j] << " ";
    }
    cout << endl;
  }

}


bool FindWordRight(const char word_search[][kSize], string to_find, int& row, int& col)  {
  int len = to_find.length();

  for(int i = 0; i < kSize; ++i)  {
    for(int j = 0; j <= kSize - len; ++j)  {
       if(word_search[i][j] == to_find[0])  {
          bool found = true;
          for(int k = 1; k < len; ++k)  {
             if(word_search[i][j + k] != to_find[k]) {
		found = false;
		break;
             }
          }
          if(found)  {
             row = i;
             col = j;
             return true;
          }
       }
    }
  }
  return false;
}


bool FindWordLeft(const char word_search[][kSize], string to_find, int& row, int& col) {
   int len = to_find.length();

   for (int i = 0; i < kSize; ++i) {
      for (int j = len - 1; j < kSize; ++j) {
	  if (word_search[i][j] == to_find[0]) {
             bool found = true;
             for (int k = 1; k < len; ++k) {
                 if (word_search[i][j - k] != to_find[k]) {
                    found = false;
                    break;
                 }
             }
             if (found) {
                row = i;
                col = j;
                return true;
             }
          }
       }
   }
   return false;
}


bool FindWordUp(const char word_search[][kSize], string to_find, int& row, int& col) {
   int len = to_find.length();

   for (int j = 0; j < kSize; ++j) {
       for (int i = len - 1; i <kSize; ++i) {
           if (word_search[i][j] == to_find[0]) {
              bool found = true;
              for (int k = 1; k < len; ++k) {
                  if (word_search[i - k][j] != to_find[k]) {
                     found = false;
                     break;
                  }
              }
              if (found) {
                 row = i;
                 col = j;
                 return true;
              }
           }
        }
    }
   return false;
}


bool FindWordDown(const char word_search[][kSize], string to_find, int& row, int& col) {
   int len = to_find.length();


   for (int j = 0; j < kSize; ++j) {
       for (int i = 0; i <= kSize; ++i) {
           if (word_search[i][j] == to_find[0]) {
              bool found = true;
              for (int k = 1; k < len; ++k) {
                  if (word_search[i + k][j] != to_find[k]) {
                     found = false;
                     break;
                  }
              }
              if (found) {
                 row = i;
                 col = j;
                 return true;
              }
          }
       }
   }
   return false;
}


bool FindWordDiagonal(const char word_search[][kSize], string to_find, int& row, int& col) {

  int len = to_find.length();

  for (int i = 0; i <= kSize - len; ++i) {
      for (int j = 0; j <= kSize - len; ++j) {
          if (word_search[i][j] == to_find[0]) {
             bool found = true;
             for (int k = 1; k < len; ++k) {
                 if (word_search[i + k][j + k] != to_find[k]) {
                     found = false;
                     break;
                 }
             }
             if (found) {
                row = i;
                col = j;
                return true;
             }
          }
      }
   }
   return false;
}
