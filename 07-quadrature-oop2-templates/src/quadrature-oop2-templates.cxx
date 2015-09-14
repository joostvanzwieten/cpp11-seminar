/**
 * \file quadrature-oop2-templates.cxx
 *
 * This file is part of the seminar: From the basics of modern OOP to
 * parallel scientific programming in C++11.
 *
 * \author Matthias Moller
 *
 * \brief
 * In this version we aim at implementing an abstract function class
 * that provides the ability to integrate itself via one-dimensional
 * Gauss quadrature rules. A concrete function object is implemented
 * by inheriting from the abstract base class and implementing the
 * ()-operator.
 */

// Include header file for standard input/output stream library
#include <iostream>

// Include header file for standard utility library
#include <cstdlib>

// Include math constants; for a list of supported constants see
// http://www.gnu.org/software/libc/manual/html_node/Mathematical-Constants.html
#define _USE_MATH_DEFINES
#include <cmath>

// Include header file for functions
#include "FunctionBase.hpp"

using namespace std;

// Create templated class Function1 that inherits all public methods
// from class FunctionBase. In particular, it provides the generic
// implementation of one-dimensional Gauss quadrature rules. To make
// it work, we only need to implement the virtual ()-operator.
template<typename TData=double>
class Function1 : public FunctionBase<TData>{
public:
  TData operator()(TData x){
    return cos(x);
  }
};

// Define data types
typedef float DataType;
typedef int   IndexType;

// The global main function that is the designated start of the
// program. By means of the two parameters "argc" and "argv" it
// becomes possible to pass arguments to the executable, e.g.,
// quadrature-static arg1 arg2 Parameter argc holds the number of
// arguments that have been passed and the char pointer argv stores
// the values of the arguments in argv[1], argv[2], etc.
int main (int argc,  char** argv){

  // Get number of subdivision steps from command line arguments:
  DataType a=0.0, b=2.0*M_PI;
  IndexType n = 1;
  
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
    cout << "Usage: quadrature-oop2-templates" << endl;
    cout << "       quadrature-oop2-templates n" << endl;
    cout << "       quadrature-oop2-templates a b" << endl;
    cout << "       quadrature-oop2-templates n a b" << endl;
    exit(-1);
  }

  auto f1 = Function1<DataType>();

  // Output
  cout << "Numerical integration of cos(x) over [" << a << "," << b << "]:" << endl;
  cout << n << "-pt Gauss quadrature rule: " << f1.integrate(a,b,n) << endl;
  
  // End program
  return 0;
}
