// Copyright 2025 bhipp
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include"program2functions.h"

int main() {
  if ( IsVowel('E') ) {
    cout << "Passed IsVowel('E') test" << endl;
  } else {
    cout << "Failed IsVowel('E') test" << endl;
  }

  if ( !IsVowel('b') ) {
    cout << "Passed IsVowel('b') test" << endl;
  } else {
    cout << "Failed IsVowel('b') test" << endl;
  }

  if ( !IsVowel('?') ) {
    cout << "Passed IsVowel('?') test" << endl;
  } else {
    cout << "Failed IsVowel('?') test" << endl;
  }

  if ( IsVowel('y') ) {
    cout << "Passed IsVowel('y') test" << endl;
  } else {
    cout << "Failed IsVowel('y') test" << endl;
  }

  if ( !IsVowel('y', false) ) {
    cout << "Passed IsVowel('y', false) test" << endl;
  } else {
    cout << "Failed IsVowel('y', false) test" << endl;
  }

  return 0;
}
