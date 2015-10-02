#include <iostream>

class Base {
private:
  int my_a;

public:
  // Constructor of Base class
  Base(int a){ my_a=a; }
};

class Super: public Base {
private:
  int my_b;
  
public:
  // Constructor of Super class delegating part of the work to the
  // constructor of Base class
  Super(int a, int b): Base(a) { my_b=b; }
};

// Main program
int main() {
  Base  b(1);
  Super s(2,3);
  return 0;
}
