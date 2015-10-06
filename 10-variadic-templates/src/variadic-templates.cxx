#include <iostream>

using namespace std;

// Forward declaration
template<typename T, T...args>
class Add{};


// 1-argument implementation
template<typename T, T arg0>
class Add<T,arg0>{
public:
  T static eval(){
    return arg0;
  }
};

// 1+(n-1)-argument implementation
template<typename T, T arg0, T...args>
class Add<T,arg0,args...>{
public:
  T static eval(){
    return arg0 + Add<T,args...>::eval();
  }
};

int main(){

  Add<int,1,2,3> A;
  cout << A.eval() << endl;
  
  return 0;
}
