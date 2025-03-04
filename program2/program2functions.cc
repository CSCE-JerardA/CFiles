// Copyright 2025 Jerard Austin

#include "program2functions.h"

// Method determining if an integer can be squared or not
bool IsSquare(int num){
  if(num < 0){
    return false;
  }

  for(int i = 0; i * i <= num; i++){
    if(i * i == num){
      return true;
    }
  }
    return false;
}


// Function to determine whether the integer is a perfect number
bool IsPerfect(int num){
  if(num <= 1){
    return false;
  }
  int sum = 0;
  for(int i = 1; i < num; i++){
    if(num % i == 0){
      sum += i;
    }
  }
  return sum == num;
}

// Function that determines whether a character is a vowel or not
bool IsVowel(char c, bool someY){
  if(c >= 'A' && c <= 'Z'){
    c = c + 32;
  }
  if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
    return true;
  }
  if(c == 'y' && someY){
    return true;
  }
  return false;
}

// Function that determines whether a character is a consonant or not
bool IsConsonant(char c, bool someY){
  if(c >= 'A' && c <= 'Z'){
    c = c + 32;
  }

  if(!someY && c == 'y'){
    return false;
  }

  if(someY && c == 'y'){
    return true;
  }


  if((c >= 'a' &&  c <= 'z') && !IsVowel(c, someY)){
    return true;
  }
  return false;
}

// Function that convert a string character to an integer
int ToDigit(char c){
  if(c >= '0' && c <= '9'){
    return c - '0';
  }
  return 0;
}

// Function that calculates the difference between the two integers
// The function also makes sure that the smaller value is assigned to first argument
int Range(int &a, int &b){
  if(a > b){
    int temp = a;
    a = b;
    b = temp;
  }
  return b - a;
}

// Function that uses divsion for left-side digits and multiplication for the right side digits
int DigitInPosition(double n, int p){
  if(p < 0){
    int intPart = n;
    for(int i = 0; i < -p; i++){
      intPart /= 10;
    }
    return intPart % 10;
  }
  else {
    for(int i = 0; i < p; i++){
      n *= 10;
    }
    int intN = n;
    return intN % 10;
  }

}

