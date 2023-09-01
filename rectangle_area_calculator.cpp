/*
  Program: Rectangle Area Calculator
  Description: This C++ program calculates and displays the area of a rectangle.
  Formula: Area = Length x Width.
  Author: Muhammad Ismail
  Website: ismailfaridi.com
  Date: 01-Sep-2023
*/

#include <iostream>
using namespace std;
// Parameterized Macro
#define AREA(length, width) ((length) * (width))

int main() {
  double length, width;

  cout << "Enter the length of the rectangle: ";
  cin >> length;
  // Check if the length is valid (positive)
  if (length <= 0) {
    cout << "Invalid input! Length must be a positive number." << endl;
    return 1;
  }

  cout << "Enter the width of the rectangle: ";
  cin >> width;
  // Check if the width is valid (positive)
  if (width <= 0) {
    cout << "Invalid input! width must be a positive number." << endl;
    return 1;
  }

  cout << "The area of a rectangle is " << AREA(length, width) << endl;

  return 0;
}