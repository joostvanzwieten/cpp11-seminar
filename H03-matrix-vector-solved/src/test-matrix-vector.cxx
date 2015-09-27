#include <iostream>
#include <cmath>
#include "matrix-vector.hpp"
using namespace std;

#define TEST(name, test) cout << (name) << ": " << ((test) ? "PASSED" : "FAILED") << endl;

template<typename I>
bool equal(const Vector<int, I> &l, const Vector<int, I> &r)
{
    for (I i = 0; i < l.length; i++)
        if (l(i) != r(i))
            return false;
    return true;
}

template<typename I>
bool equal(const Vector<double, I> &l, const Vector<double, I> &r, double tolerance)
{
    for (I i = 0; i < l.length; i++)
        if (abs(l(i)-r(i)) > tolerance)
            return false;
    return true;
}

template<typename T, typename I>
Vector<T, I> range(I n, I step=1)
{
    Vector<T, I> vec(n);
    for (I i = 0; i < n; i++)
        vec(i) = i*step;
    return vec;
}

void test_identity(int n)
{
    DenseMatrix<double, int> eye(n, n);
    eye = 0;
    for (int i = 0; i < n; i++)
        eye(i,i) = 1;
    Vector<double, int> x = range<double, int>(n);
    TEST("test_identity", equal(x, eye.matvec(x), 1e-14));
}

void test_matvec(int n)
{
    DenseMatrix<int, int> A(n, n);
    A = 0;
    for (int i = 0; i < n; i++)
    {
        A(i,i) = 2;
        if (i > 0)
        {
            A(i-1,i) = -1;
            A(i,i-1) = -1;
        }
    }

    Vector<int, int> x(n), y(n);
    for (int i = 0; i < n; i++)
        x(i) = i*i-1;
    y = -2;
    y(n-1) = n*n-3;

    TEST("test_matvec", equal(A.matvec(x), y));
}

void test_vector_arithmetic(int n)
{
    Vector<int, int> x = range<int, int>(n);
    x = 2*x;
    x += x+2*x;
    x -= x-3*x;
    TEST("test_vector_arithmetic", equal(x, range<int, int>(n, 24)));
}

int main()
{
    test_identity(5);
    test_matvec(5);
    test_vector_arithmetic(5);
}
