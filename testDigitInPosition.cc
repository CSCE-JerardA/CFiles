// Copyright 2025 bhipp
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<iomanip>
#include"program2functions.h"

int main() {
  cout << std::setiosflags(std::ios::fixed) << std::setprecision(4);
  double example_num = 154321.8076;
  int digit;
  int expected[10] = {0, 1, 5, 4, 3, 2, 1, 8, 0, 7};

  for ( int position = -6; position < 4; ++position ) {
    digit = DigitInPosition(example_num, position);
    if ( digit == expected[position + 6] ) {
      cout << "Passed DigitInPosition test " << position + 7 << endl;
    } else {
      cout << "Failed DigitInPosition test " << position + 7
           << ": DigitInPosition(" << example_num << ", " << position
           << ") returned = " << digit << ", expected "
           << expected[position + 6] << endl;
    }
  }

  return 0;
}
