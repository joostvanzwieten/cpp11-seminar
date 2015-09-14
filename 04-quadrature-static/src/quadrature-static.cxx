/**
 * \file quadrature-static.cxx
 *
 * This file is part of the seminar: From the basics of modern OOP to
 * parallel scientific programming in C++11.
 *
 * \author Matthias Moller
 *
 * \brief
 * In this version we aim at implementing one-dimensional numerical
 * integration, which is most closely to the MATLAB command
 *
 * \verbatim
 * quad(@(x) cos(x), 0, 2*pi)
 * \endverbatim
 *
 */

// Include header file for standard input/output stream library
#include <iostream>

// Include header file for standard utility library
#include <cstdlib>

// Include math constants; for a list of supported constants see
// http://www.gnu.org/software/libc/manual/html_node/Mathematical-Constants.html
#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

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
    cout << "Usage: quadrature-static" << endl;
    cout << "       quadrature-static n" << endl;
    cout << "       quadrature-static a b" << endl;
    cout << "       quadrature-static n a b" << endl;
    exit(-1);
  }
  
  // Compute the integral int(cos(x), x=0..2*pi) using:
  
  // (a) Simpson's rule: int_a^b f(x) dx = (b-a)/2 * (f(a) + 4*f((a+b)/2) + f(b))
  double Int1 = (b-a)/6.0 *( cos(a) + 4.0*cos((a+b)/2.0) + cos(b) );

  // (b) Composite Simpson's rule
  double Int2 = 0.0;

  // h = (b-a)/n
  double h = (b-a)/(double)n;
  
  // int_a^b f(x) dx = sum_{k=1}^n \int_{x_{k-1}}^{x_k} f(x) dx
  // with x_k = 0 + kh, 
  for (int k=1; k<=n; k++)
    Int2 += h/6.0 * (cos(a+(k-1)*h) + 4.0*cos(a+(k-0.5)*h) + cos(a+k*h));

  // (c) 3-pt Gauss quadrature rule
  double Int3 = 0.0;
  const double x3[3] = {-sqrt(15.0)/5.0,
                         0.0,
                         sqrt(15.0)/5.0};
  const double w3[3] = { 5.0/9.0,
                         8.0/9.0,
                         5.0/9.0};

  // int_a^b f(x) dx = (b-a)/2 * sum_{k=0}^n w[k]*f((b-a)/2 * x[k] + (a+b)/2 ) 
  for (int k=0; k<3; k++)
    Int3 += w3[k] * cos((b-a)/2.0 * x3[k] + (a+b)/2.0);
  Int3 *= (b-a)/2.0;

  // (d) 4-pt Gauss quadrature rule
  double Int4 = 0.0;
  const double x4[4] = {-sqrt(525.0+70.0*sqrt(30.0))/35.0,
                        -sqrt(525.0-70.0*sqrt(30.0))/35.0,
                         sqrt(525.0-70.0*sqrt(30.0))/35.0,
                         sqrt(525.0+70.0*sqrt(30.0))/35.0};
  const double w4[4] = { (18.0-sqrt(30.0))/36.0,
                         (18.0+sqrt(30.0))/36.0,
                         (18.0+sqrt(30.0))/36.0,
                         (18.0-sqrt(30.0))/36.0};


  // int_a^b f(x) dx = (b-a)/2 * sum_{k=0}^n w[k]*f((b-a)/2 * x[k] + (a+b)/2 ) 
  for (int k=0; k<4; k++)
    Int4 += w4[k]*cos((b-a)/2.0 * x4[k] + (a+b)/2.0);
  Int4 *= (b-a)/2.0;
  
  // Output
  cout << "Numerical integration of cos(x) over [" << a << "," << b << "]:" << endl;
  cout << "Simpson's rule:             " << Int1 << endl;
  cout << "Composite Simpson's rule:   " << Int2 << endl;
  cout << "3-pt Gauss quadrature rule: " << Int3 << endl;
  cout << "4-pt Gauss quadrature rule: " << Int4 << endl;
  
  // End program
  return 0;
}
