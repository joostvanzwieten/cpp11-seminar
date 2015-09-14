/**
 * \file input-output.cxx
 *
 * This file is part of the seminar: From the basics of modern OOP to
 * parallel scientific programming in C++11.
 *
 * \author Matthias Moller
 *
 */

// Include header file for standard input/output stream library
#include <iostream>

// All classes from the C++ standard library are bundled in the
// namespace std. In order to avoid typing std::cout etcetera it is
// handy to make the namespace 'std' known globally
using namespace std;

// The global main function that is the designated start of the program
int main(){
  
  // Write string to standard output
  cout << "This string is written to standard output!" << endl;
  
  // Write string to standard output for errors
  cerr << "This string is written to standard output for errors!" << endl;

  // Write string to standard output for logging
  clog << "This string is written to standard output for logging!" << endl;

  // Request user to enter an integer value
  cout << "Please enter an integer value: ";
  int i;
  cin >> i;

  // Write integer value to standard output
  cout << "The integer value entered is: " << i << endl;

  // Return code 0 to the operating system (=no error)
  return 0;
}
