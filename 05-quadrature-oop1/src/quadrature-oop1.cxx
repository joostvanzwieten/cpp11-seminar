/**
 * \file quadrature-oop1.cxx
 *
 * This file is part of the seminar: From the basics of modern OOP to
 * parallel scientific programming in C++11.
 *
 * \author Matthias Moller
 *
 * \brief
 * In this version we aim at implementing one-dimensional Gauss
 * quadrature rules in an object-oriented fashion that can be used to
 * evaluate arbitrary functions.
 */

// Include header file for standard input/output stream library
#include <iostream>

// Include header file for standard utility library
#include <cstdlib>

// Include header file for functionals
#include <functional>

// Include math constants; for a list of supported constants see
// http://www.gnu.org/software/libc/manual/html_node/Mathematical-Constants.html
#define _USE_MATH_DEFINES
#include <cmath>

// Include header file for Gauss quadrature rules
#include "GaussRule.hpp"

using namespace std;

// Callback function
double myfunc(double x){
  return cos(x);
}

// The global main function that is the designated start of the
// program. By means of the two parameters "argc" and "argv" it
// becomes possible to pass arguments to the executable, e.g.,
// quadrature-static arg1 arg2 Parameter argc holds the number of
// arguments that have been passed and the char pointer argv stores
// the values of the arguments in argv[1], argv[2], etc.
int main (int argc,  char** argv){

  // Get number of subdivision steps from command line arguments:
  double a=0.0, b=2.0*M_PI;
  int n = 1;
  
  // Check if command line arguments have been passed
  switch (argc){
  case 1:
    // adopt default values initialized above
    break;
  case 2:
    // std::atoi converts the string stored in argv[1] into an integer
    n = atoi(argv[1]);
    break; // do not forget break here since otherwise all other cases
           // would be processed !!!
  case 3:
    // std::atof converts the string stored in argv[1] into a floiting point number
    a = atof(argv[1]);
    b = atof(argv[2]);
    break;
  case 4:
    n = atoi(argv[1]);
    a = atof(argv[2]);
    b = atof(argv[3]);
    break;
  default:
    cout << "Usage: quadrature-oop1" << endl;
    cout << "       quadrature-oop1 n" << endl;
    cout << "       quadrature-oop1 a b" << endl;
    cout << "       quadrature-oop1 n a b" << endl;
    exit(-1);
  }

  // Instantiate 3-pt Gauss rule by default constructor
  GaussRule GR3; // no (), really not !!!

  // Instantiate n-pt Gauss rule by alternative constructor
  GaussRule GRn(n);

  // Output
  cout << "Numerical integration of cos(x) over [" << a << "," << b << "]:" << endl;

  // Make use of traditional way to pass callback functions
  cout << "3-pt Gauss quadrature rule: " << GR3.eval(myfunc, a, b) << endl;
  cout << n << "-pt Gauss quadrature rule: " << GRn.eval(myfunc, a, b) << endl;

  // Define C++11 Lambda expression of the general form
  // auto name = [] () {};
  //
  // The auto specifier (new in C++11) tells the compiler that the type of the
  // variable that is being declared will be automatically deduced from its
  // initializer. In the following example it is the function type taking one
  // double as argument and returning a double: double (*)(double) or
  // equivalently double(double).
  //
  // The so-called capture specification "[]" tells the compiler the
  // we are creating a lambda function.
  //
  // The list of arguments that is passed to the function is given
  // within "()"
  //
  // The function body, i.e. the expression that should be calculated
  // is given within "{}"
  //
  // Okay, let's go
  auto myfunc_lambda = [](double x){return cos(x);};
  
  // Pass callback function using C++11 Lambda expressions
  cout << "3-pt Gauss quadrature rule: " << GR3.eval(myfunc_lambda, a, b) << endl;
  cout << n << "-pt Gauss quadrature rule: " << GRn.eval(myfunc_lambda, a, b) << endl;

  // We can even inline the lambda expression. That is, what lambda
  // expressions are actually meant for, efficient coding.
  cout << "3-pt Gauss quadrature rule: " << GR3.eval([](double x){return cos(x);}, a, b) << endl;
  cout << n << "-pt Gauss quadrature rule: " << GRn.eval([](double x){return cos(x);}, a, b) << endl;
    
  // End program
  return 0;
}
