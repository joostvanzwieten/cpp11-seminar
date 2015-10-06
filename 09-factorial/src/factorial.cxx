/**
 * \file factorial.cxx
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

// Implementation using run-time recursion
template<typename I>
class FactorialRunTime {
public:
  I eval(I n){
    return (n == 0) ? 1 : n*eval(n-1);
  }
};


// Implementation using compile-time recursion
class FactorialCompileTime1 {
public:
  template<int n>
  int eval(){
    return n*eval<n-1>();    
  }
};
// Specialization of eval method
template<>
int FactorialCompileTime1::eval<0>(){
  return 1;
}


// Implementation using compile-time recursion
template<typename I, I n>
class FactorialCompileTime2{
public:
  I static eval(){
    return n*FactorialCompileTime2<I,n-1>::eval();
  }
};
// Specialization of eval method for data type int
template<>
int FactorialCompileTime2<int,0>::eval() {return 1;}
// Specialization of eval method for data type long
template<>
long FactorialCompileTime2<long,0>::eval() {return 1;}
// Specialization of eval method
template<>
long long FactorialCompileTime2<long long,0>::eval() {return 1;}

/*
template<typename I>
I FactorialCompileTime2<I,0>::eval() {return (I)1;}
*/


// Demo of partial specialization
template<typename Ta, typename Tb>
class Demo {
public:
  void get(Ta a, Tb b){
    cout << "Generic implementation for arbitrary types " << a << ", " << b << endl;
  }
};

template<typename T>
class Demo<T,T> {
public:
  void get(T a, T b){
    cout << "Special implementation for identical types " << a << ", " << b << endl;
  }
};

template<typename T>
class Demo<T,bool> {
public:
  void get(T a, bool b){
    cout << "Special implementation for arbitrary first type and bool second type " << a << ", " << b << endl;
  }
};

// The global main function that is the designated start of the program
int main(){

  FactorialRunTime<int> F_RT;

  cout << F_RT.eval(0) << endl;
  cout << F_RT.eval(1) << endl;
  cout << F_RT.eval(2) << endl;
  cout << F_RT.eval(3) << endl;
  cout << F_RT.eval(4) << endl;
  cout << F_RT.eval(5) << endl;
  cout << F_RT.eval(6) << endl;
  cout << F_RT.eval(7) << endl;
  cout << F_RT.eval(8) << endl;
  cout << F_RT.eval(9) << endl;
  cout << F_RT.eval(10) << endl;

  FactorialCompileTime1 F_CT1;

  cout << F_CT1.eval<0>() << endl;
  cout << F_CT1.eval<1>() << endl;
  cout << F_CT1.eval<2>() << endl;
  cout << F_CT1.eval<3>() << endl;
  cout << F_CT1.eval<4>() << endl;
  cout << F_CT1.eval<5>() << endl;
  cout << F_CT1.eval<6>() << endl;
  cout << F_CT1.eval<7>() << endl;
  cout << F_CT1.eval<8>() << endl;
  cout << F_CT1.eval<9>() << endl;
  cout << F_CT1.eval<10>() << endl;

  cout << FactorialCompileTime2<int,0>::eval() << endl;
  cout << FactorialCompileTime2<int,1>::eval() << endl;
  cout << FactorialCompileTime2<int,2>::eval() << endl;
  cout << FactorialCompileTime2<int,3>::eval() << endl;
  cout << FactorialCompileTime2<int,4>::eval() << endl;
  cout << FactorialCompileTime2<int,5>::eval() << endl;
  cout << FactorialCompileTime2<int,6>::eval() << endl;
  cout << FactorialCompileTime2<int,7>::eval() << endl;
  cout << FactorialCompileTime2<int,8>::eval() << endl;
  cout << FactorialCompileTime2<int,9>::eval() << endl;
  cout << FactorialCompileTime2<int,10>::eval() << endl;

  /*
  // Small demo
  Demo<double,int> D1;
  D1.get(10.0, 1);

  Demo<double,double> D2;
  D2.get(10.0,1.0);

  Demo<double,bool> D3;
  D3.get(10.0,true);
  */
}
