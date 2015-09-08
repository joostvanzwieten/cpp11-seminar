/**
 * 03-variables.cxx
 *
 * This file is part of the seminar: From the basics of modern OOP to
 * parallel scientific programming in C++11.
 *
 * \author Matthias Moller
 *
 */

// Include header file for standard input/output stream library
#include <iostream>

using namespace std;

// Function that tries to change the value of an integer argument that
// is passed by value (cannot work by definition and makes a physical
// copy of the data!)
void change_int_by_value(int i)
{
  cout << "Integer value as passed by value:         " << i << endl;
  i=42;
  cout << "Integer value modified locally:           " << i << endl;
}

// Function that changes the value of an integer argument that is
// passed by reference
void change_int_by_reference(int &i)
{
  cout << "Integer value as passed by reference:     " << i << endl;
  i=42;
  cout << "Integer value modified locally:           " << i << endl;
}

// Function that tries to change the value of an integer argument that
// is passed by constant reference (cannot work but does not make a
// physical copy of the data!)
void change_int_by_const_reference(const int &i)
{
  cout << "Integer value as passed by const reference: " << i << endl;
  //i=42;
  cout << "Integer value modified locally:             " << i << endl;
}

// Function that changes the value of an integer argument that is
// passed by address
void change_int_by_address(int *i)
{
  cout << "Integer is stored in memory at address:   " <<  i << endl;
  cout << "Integer value as passed by address:       " << *i << endl;

  // This is WRONG!!!
  // i=42;

  // This is RIGHT!!!
  *i=42;
  
  cout << "Integer value modified locally:           " << *i << endl;
}

// Function that returns an integer by value
int return_int_by_value(int i)
{
  int j = 2*i; // local variable
  return j;    // return a copy of j here
} // variable j goes out of scope here

/*
// Function that returns an integer by reference
int& return_int_by_reference(int i)
{
  int j = 2*i; // local variable
  // return j;    // return a reference to j here
} // variable j goes out of scope here
*/

/*
// Function that returns an integer by address
int* return_int_by_reference(int i)
{
  int j = 2*i; // local variable
  return &j;   // return j by address here
} // variable j goes out of scope here
*/

// The global main function that is the designated start of the program
int main(){

  // Declaration of variables
  int i1,i2;
  float f1,f2;
  double d1,d2;

  // Initialization of variables
  i1=1, i2=2;
  f1=0.0, f2=1.0;
  d1=0.0, d2=1.0;

  // Declaration and initialization of variables
  int j=30;
  
  cout << "integers: " << i1 << ", " << i2 << endl;
  cout << "floats:   " << f1 << ", " << f2 << endl;
  cout << "doubles:  " << d1 << ", " << d2 << endl;
  cout << endl;

  j=30;
  
  // Try to change the value of a variable passed by value
  cout << "Integer value before passed by value:     " << j << endl;
  change_int_by_value(j);
  cout << "Integer value after passed by value:      " << j << endl;
  cout << endl;

  j=30;
  
  // Try to change the value of a variable passed by reference
  cout << "Integer value before passed by reference: " << j << endl;
  change_int_by_reference(j);
  cout << "Integer value after passed by reference:  " << j << endl;
  cout << endl;

  j=30;
  
  // Try to change the value of a variable passed by address
  cout << "Integer value before passed by address:   " << j << endl;
  change_int_by_address(&j);
  cout << "Integer value after passed by address:    " << j << endl;
  cout << endl;

  // Let us play around with values, references, pointers

  j=30;
  
  cout << "Integer value before passed by value:     " << j << endl;
  change_int_by_value(*&j);
  cout << "Integer value after passed by value:      " << j << endl;
  cout << endl;
  
  // Let us test different ways to return parameters
  int k = return_int_by_value(j);
  cout << "Integer value returned by value:          " << k << endl;
  
  // Return code 0 to the operating system (=no error)
  return 0;
}
