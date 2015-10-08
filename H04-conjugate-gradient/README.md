Homework 4
==========

This is a follow-up on the previous homework assignment.  Your task is to
create a function named `cg` that solves a linear system using the Conjugate
Gradient method, given in pseudocode as

    p_0 = r_0 = b - A x_0
    for k = 0, 1, ..., maxiter-1
        alpha_k = dot(r_k,r_k) / A_dot(r_k,r_k)
        x_k+1 = x_k + alpha_k p
        r_k+1 = r_k - alpha_k A p
        if dot(r_k+1,r_k+1) < tol*tol
            stop
        beta_k = dot(r_k+1,r_k+1) / dot(r_k,r_k)
        p_k+1 = r_k+1 + beta_k p_k

Here, `A` is a symmetric positive definite matrix, `x_k`, `r_k` and `p_k` are
vectors, `dot` is the standard l2-inner product, `A_dot` is the `A`-inner
product, `tol` is an absolute tolerance for the residual and `maxiter` is the
maximum allowed number of iterations.

The `cg` function should have the following signature

    template<typename T, typename I>
    I cg(const Matrix<T, I> &A, const Vector<T, I> &b, Vector<T, I> &x, T tol, I maxiter)
    {
        ...
    }

The third argument serves both as the initial guess (`x_0` in the pseudocode)
and as the result (`x_k+1` in the pseudocode, where `k` is the last iteration).
The function should return the number of iterations used to acchieve the
desired tolerance if the Conjugate Gradient method converged within `maxiter`,
otherwise `-1`.

Use your implementation of the `Matrix` and `Vector` classes of [homework 3].
Test the conjugate gradient method using a Laplace matrix or any other
symmetric positive definite matrix.  Unlike the previous homeworks you have to
create a `CMakeLists.txt` yourself, e.g. copy the `CMakeLists.txt` from the
previous homework and update the project name, executable name and source
files.

[homework 3]: ../H03-matrix-vector/
