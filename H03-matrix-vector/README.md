Homework 3
==========

A possible implementation of the Conjugate Gradient method in pseudocode is
given by

    p_0 = r_0 = b - A x_0
    for k = 0, 1, ...
        alpha_k = dot(r_k,r_k) / A_dot(p_k,p_k)
        x_k+1 = x_k + alpha_k p
        r_k+1 = r_k - alpha_k A p
        if dot(r_k+1,r_k+1) < tol
            stop
        beta_k = dot(r_k+1,r_k+1) / dot(r_k,r_k)
        p_k+1 = r_k+1 + beta_k p_k

Here, `A` is a matrix, `x_k`, `r_k` and `p_k` are vectors, `dot` is the standard
l2-inner product and `A_dot` is the `A`-inner product.

We would like to write a C++ implementation of the Conjugate Gradient
method that closely follows the pseudocode given above.  To achieve this we
will implement a `DenseMatrix` and a `Vector` class with appropriate operators
and methods.  The `DenseMatrix` class should have a `matvec` method such that
we can write `A.matvec(x_k)` replacing `A x_k` in the pseudocode.  The `Vector`
class should support summing and subtracting two vectors and multiplication of
a scalar with a vector.

The [src/] folder contains two files: [matrix-vector.hpp] containing a partial
implementation of the `Matrix` and `Vector` classes and [test-matrix-vector.cxx]
containing a `main` function with a simple test.  Your task is complete the
implementation and add appropriate tests in function `main`.  All incomplete
parts in the source files are marked `TODO`.

[src/]: src/
[matrix-vector.hpp]: src/matrix-vector.hpp
[test-matrix-vector.cxx]: src/test-matrix-vector.cxx
