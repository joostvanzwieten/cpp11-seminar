#include <iostream>
#include <cmath>
#include "matrix-vector.hpp"
using namespace std;

#ifdef HAVE_UNISTD_H
# include <unistd.h>
#endif

void TEST(const char *name, bool test)
{
    cout << name << ": ";
    const char *clr_red = "", *clr_green = "", *clr_clear = "";
#ifdef HAVE_UNISTD_H
    if (isatty(1))
    {
        clr_red = "\033[31m";
        clr_green = "\033[32m";
        clr_clear = "\033[0m";
    }
#endif
    if (test)
        cout << clr_green << "PASSED" << clr_clear;
    else
        cout << clr_green << "FAILED" << clr_clear;
    cout << endl;
}

template<typename I>
bool almost_equal(const Vector<double, I> &l, const Vector<double, I> &r, double tolerance)
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

template<typename T, typename I>
DenseMatrix<T, I> negative_laplace(I n)
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
    return A;
}

void test_identity(int n)
{
    DenseMatrix<double, int> eye(n, n);
    eye = 0;
    for (int i = 0; i < n; i++)
        eye(i,i) = 1;
    Vector<double, int> x = range<double, int>(n);
    TEST("test_identity", almost_equal(x, eye.matvec(x), 1e-14));
}

void test_matvec(int n)
{
    DenseMatrix<int, int> A = negative_laplace<int, int>(n);
    Vector<int, int> x(n), y(n);
    for (int i = 0; i < n; i++)
        x(i) = i*i-1;
    y = -2;
    y(n-1) = n*n-3;

    TEST("test_matvec", A.matvec(x) == y);
}

void test_vector_arithmetic(int n)
{
    Vector<int, int> x = range<int, int>(n);
    x = 2*x;
    x += x+2*x;
    x -= x-3*x;
    TEST("test_vector_arithmetic", x == range<int, int>(n, 24));
}

void test_dot(int n)
{
    DenseMatrix<int, int> A = negative_laplace<int, int>(n);
    Vector<int, int> x = range<int, int>(n);
    int value_standard = 0;
    for (int i = 0; i < n; i++)
        value_standard += i*i;
    TEST("test_dot - standard", dot(x, x) == value_standard);
    TEST("test_dot - laplace", dot(A, x, x) == n*(n-1));
}

int main()
{
    test_identity(5);
    test_matvec(5);
    test_vector_arithmetic(5);
    test_dot(5);
}
