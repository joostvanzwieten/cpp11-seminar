/**
 * \file GaussRule.hpp
 *
 * This file is part of the seminar: From the basics of modern OOP to
 * parallel scientific programming in C++11.
 *
 * \author Matthias Moller
 *
 * \brief
 * This class implements a one-dimensional Gauss quadrature rule
 *
 */

// This is a standard trick to prevent that header files are included
// more than once. If this file has not been included yet than
// GAUSS_RULE_HPP is not defined. The first inclusion of this file
// defines GAUSS_RULE_HPP so that the content between #ifndef and
// #endif is not included for a second time.
#ifndef GAUSS_RULE_HPP
#define GAUSS_RULE_HPP

using namespace std;

class GaussRule{
  
private:
  // Number of quadrature points
  int N;

  // Quadrature points
  double *x;

  // Quadrature weight
  double *w;

public:
  // Standard constructor
  //
  // Here, we use so-called delegating constructors that were
  // introduced with C++11. This technique is very powerful to
  // delegate the real work, i.e. constructing an instance of this
  // class to another constructor. In this example, we want to
  // instantiate the 3-pt GaussRule object which we can do by
  // explicitely writing:
  //
  // GaussRule(){
  //   N = 3;
  //   x = new double[3] {0.0000000000000000000000000,
  //                      0.7745966692414833770358531,
  //                     -0.7745966692414833770358531};
  //    w = new double[3] {0.8888888888888888888888889,
  //                       0.5555555555555555555555556,
  //                       0.5555555555555555555555556};
  // }
  //
  // But that is a lot of double work since we have to write this
  // piece of code anyway in the constructor below. By means of
  // delegating constructors we can just tell the compile to call
  // another constructor with parameter 3 (for 3-pt GaussRule)
  // instead. It is even possible, but not required here, to perform
  // some post-processing work AFTER having called the constructor.
  GaussRule() : GaussRule(3){
    /* Here, we could add some post-work */
  }
  
  // Constructor
  GaussRule(int n){
    N = n;

    // Allocate memory and initialize quadrature points and weights
    switch(n){
    case 1:
      // n = 1
      x = new double[n] {0.0};
      w = new double[n] {2.0};
      break;
    case 2:
      // n = 2
      x = new double[n] {0.5773502691896257645091488,
                         -0.5773502691896257645091488};
      w = new double[n] {1.0000000000000000000000000,
                         1.0000000000000000000000000};
      break;
    case 3:
      // n = 3
      x = new double[n] {0.0000000000000000000000000,
                         0.7745966692414833770358531,
                         -0.7745966692414833770358531};
      w = new double[n] {0.8888888888888888888888889,
                         0.5555555555555555555555556,
                         0.5555555555555555555555556};
      break;
    case 4:
      // n = 4
      x = new double[n] {0.3399810435848562648026658,
                         0.8611363115940525752239465,
                         -0.3399810435848562648026658,
                         -0.8611363115940525752239465};
      w = new double[n] {0.6521451548625461426269361,
                         0.3478548451374538573730639,
                         0.6521451548625461426269361,
                         0.3478548451374538573730639};
      break;
    case 5:
      // n = 5
      x = new double[n] {0.0000000000000000000000000,
                         0.5384693101056830910363144,
                         0.9061798459386639927976269,
                         -0.5384693101056830910363144,
                         -0.9061798459386639927976269};
      w = new double[n] {0.5688888888888888888888889,
                         0.4786286704993664680412915,
                         0.2369268850561890875142640,
                         0.4786286704993664680412915,
                         0.2369268850561890875142640};
      break;
    case 6:
      // n = 6
      x = new double[n] {0.2386191860831969086305017,
                         0.6612093864662645136613996,
                         0.9324695142031520278123016,
                         -0.2386191860831969086305017,
                         -0.6612093864662645136613996,
                         -0.9324695142031520278123016};
      w = new double[n] {0.4679139345726910473898703,
                         0.3607615730481386075698335,
                         0.1713244923791703450402961,
                         0.4679139345726910473898703,
                         0.3607615730481386075698335,
                         0.1713244923791703450402961};
      break;
    case 7:
      // n = 7
      x = new double[n] {0.0000000000000000000000000,
                         0.4058451513773971669066064,
                         0.7415311855993944398638648,
                         0.9491079123427585245261897,
                         -0.4058451513773971669066064,
                         -0.7415311855993944398638648,
                         -0.9491079123427585245261897};
      w = new double[n] {0.4179591836734693877551020,
                         0.3818300505051189449503698,
                         0.2797053914892766679014678,
                         0.1294849661688696932706114,
                         0.3818300505051189449503698,
                         0.2797053914892766679014678,
                         0.1294849661688696932706114};
      break;
    case 8:
      // n = 8
      x = new double[n] {0.1834346424956498049394761,
                         0.5255324099163289858177390,
                         0.7966664774136267395915539,
                         0.9602898564975362316835609,
                         -0.1834346424956498049394761,
                         -0.5255324099163289858177390,
                         -0.7966664774136267395915539,
                         -0.9602898564975362316835609};
      w = new double[n] {0.3626837833783619829651504,
                         0.3137066458778872873379622,
                         0.2223810344533744705443560,
                         0.1012285362903762591525314,
                         0.3626837833783619829651504,
                         0.3137066458778872873379622,
                         0.2223810344533744705443560,
                         0.1012285362903762591525314};
      break;
    case 9:
      // n = 9
      x = new double[n] {0.0000000000000000000000000,
                         0.3242534234038089290385380,
                         0.6133714327005903973087020,
                         0.8360311073266357942994298,
                         0.9681602395076260898355762,
                         -0.3242534234038089290385380,
                         -0.6133714327005903973087020,
                         -0.8360311073266357942994298,
                         -0.9681602395076260898355762};
      w = new double[n] {0.3302393550012597631645251,
                         0.3123470770400028400686304,
                         0.2606106964029354623187429,
                         0.1806481606948574040584720,
                         0.0812743883615744119718922,
                         0.3123470770400028400686304,
                         0.2606106964029354623187429,
                         0.1806481606948574040584720,
                         0.0812743883615744119718922};
      break;
    case 10:
      // n = 10
      x = new double[n] {0.1488743389816312108848260,
                         0.4333953941292471907992659,
                         0.6794095682990244062343274,
                         0.8650633666889845107320967,
                         0.9739065285171717200779640,
                         -0.1488743389816312108848260,
                         -0.4333953941292471907992659,
                         -0.6794095682990244062343274,
                         -0.8650633666889845107320967,
                         -0.9739065285171717200779640};
      w = new double[n] {0.2955242247147528701738930,
                         0.2692667193099963550912269,
                         0.2190863625159820439955349,
                         0.1494513491505805931457763,
                         0.0666713443086881375935688,
                         0.2955242247147528701738930,
                         0.2692667193099963550912269,
                         0.2190863625159820439955349,
                         0.1494513491505805931457763,
                         0.0666713443086881375935688};
      break;
    default:          
      cout << "Non-supported number of quadrature points." << endl;
      exit(1);
    }
  }

  // Destructor (and there can only be one !!!)
  ~GaussRule(){
    // Delete memory for quadrature points and weights
    delete[] x;
    delete[] w;
  }

  // Method that evaluates the integral of a given callback function
  // over the interval [a,b]. This is the simplest way to pass a
  // callback function.
  double eval(double f(double), double a, double b){
    // Initialize local variable
    double Int = 0.0;

    // int_a^b f(x) dx = (b-a)/2 * sum_{k=0}^n w[k]*f((b-a)/2 * x[k] + (a+b)/2 ) 
    for (int k=0; k<N; k++)
      Int += w[k]*f((b-a)/2.0 * x[k] + (a+b)/2.0);
    Int *= (b-a)/2.0;
    return Int;
  }
  
}; // Do not forget ";" after the closing brace of a class definition !!!

#endif // GAUSS_RULE_HPP
