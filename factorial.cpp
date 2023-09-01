/*
  Program: Factorial Calculator
  Description: This C++ program calculates the factorial of a non-negative
  integer entered by the user. The factorial of a number N is the product of all
  positive integers from 1 to N.
  Author: Muhammad Ismail
  Website: ismailfaridi.com
  Date: 01-Sep-2023
*/

#include <iostream>
using namespace std;

// Function to calculate the factorial of a non-negative integer
long factorial(long num) {
  long result = 1;
  for (long i = 1; i <= num; i++) {
    result *= i;
  }
  return result;
}

int main() {
  long num;

  // Input: Ask the user to enter a non-negative number
  cout << "Enter a non-negative number: ";
  cin >> num;

  // Check if the input is negative
  if (num < 0) {
    cout << "Factorial is undefined for negative numbers." << endl;
  } else {
    // Calculate and display the factorial
    cout << "The factorial is: " << factorial(num) << endl;
  }

  return 0;
}
