#include <iostream>
#include <cmath>
#include "matrix-vector.hpp"
#include "conjugate-gradient.hpp"
using namespace std;

#ifdef HAVE_UNISTD_H
# include <unistd.h>
#endif

bool TEST(const char *name, bool test)
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
        cout << clr_red << "FAILED" << clr_clear;
    cout << endl;
    return test;
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
    DenseMatrix<T, I> A(n, n);
    A = 0;
    for (I i = 0; i < n; i++)
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

bool test_laplace()
{
    const int n = 5;
    const double tol = 1e-8;

    DenseMatrix<double, int> A = negative_laplace<double, int>(n);
    Vector<double, int> x_exact = range<double, int>(n);
    Vector<double, int> b = A.matvec(x_exact);
    Vector<double, int> x_cg(n);

    // initial guess
    x_cg = 0;

    // solve `A x_cg = b` for `x_cg` using `cg`
    int m = cg(A, b, x_cg, tol, n);

    return TEST("test_laplace", m >= 0 && almost_equal(x_cg, x_exact, 10*tol));
}

bool test_maxiter()
{
    const int n = 5;
    const double tol = 1e-30;

    DenseMatrix<double, int> A = negative_laplace<double, int>(n);
    Vector<double, int> b = range<double, int>(n);
    Vector<double, int> x_cg(n);

    // initial guess
    x_cg = 0;

    // solve `A x_cg = b` for `x_cg` using `cg`
    int m = cg(A, b, x_cg, tol, 1);

    return TEST("test_maxiter", m < 0);
}

int main()
{
    test_laplace();
    test_maxiter();
}
