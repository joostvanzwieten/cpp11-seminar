#pragma once
#include "matrix-vector.hpp"

template<typename T, typename I>
I cg(const Matrix<T, I> &A, const Vector<T, I> &b, Vector<T, I> &x, T tol, I maxiter)
{
    Vector<T, I> r = b - A.matvec(x);
    Vector<T, I> p = r;
    T dot_r_r = dot(r,r);
    if (dot_r_r < tol*tol)
        return 0;
    for (I k = 0; k < maxiter; k++)
    {
        T alpha = dot_r_r / dot(A,p,p);
        x += alpha*p;
        r -= alpha*A.matvec(p);
        T prev_dot_r_r = dot_r_r;
        dot_r_r = dot(r,r);
        if (dot_r_r < tol*tol)
            // cg converged in `k+1` iterations
            return k+1;
        T beta = dot_r_r/prev_dot_r_r;
        p = r + beta*p;
    }
    // cg did not converge in `maxiter` iterations
    return -1;
}
