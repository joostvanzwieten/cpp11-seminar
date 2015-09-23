#include <iostream>
#include "matrix-vector.hpp"
using namespace std;

void test_identity(int n)
{
    DenseMatrix<double, int> eye(n, n);
    eye = 0;
    for (int i = 0; i < n; i++)
        eye(i,i) = 1;

    Vector<double, int> x(n);
    for (int i = 0; i < n; i++)
        x(i) = i;

    Vector<double, int> y = eye.matvec(x);
    cout << "|| eye x - x ||_2^2 = " << dot(x-y, x-y) << endl;
}

// TODO: Add more test functions here.

int main()
{
    test_identity(5);
    // TODO: Call more test functions here.
}
