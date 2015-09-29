#pragma once
#include <ostream>

// Vector class.  Template argument `T` defines the type of the elements of the
// vector and `I` the type used to index the vector.  Elements of a vector can
// be retrieved using the `()` operator, e.g. `v(2)` returns the third element
// from some `Vector v`.  The `Vector` class supports adding and subtracting two
// vectors and scalar multiplication.
template<typename T, typename I>
class Vector
{
public:
    // Default constructor.  Will be called when a `Vector` is instantiated
    // without arguments.  Sets `length` and `data` to zero.
    Vector(): length(0), data(0) {}

    // Constructor taking a length.  Allocates `data` when length is
    // strict positive.
    Vector(I _length): length(_length)
    {
        if (this->length > 0)
            this->data = new T[this->length];
        else
            this->data = 0;
    }

    // Copy constructor.  Takes another `Vector` as an argument and copies the
    // data.
    Vector(const Vector &vector): Vector(vector.length)
    {
        for (I i = 0; i < this->length; i++)
            (*this)(i) = vector(i);
    }

    // Destructor.  Frees allocated `data`.
    ~Vector() { delete[] this->data; }

    // Get element at index `i`, with `0 <= i < length` (unchecked).  The first
    // version is used when the instance is marked `const`.
    const T& operator()(I i) const { return this->data[i]; }
    T& operator()(I i) { return this->data[i]; }

    // Assignment operator.  Resizes this vector if necessary and copies the
    // right hand side `r`.
    Vector& operator=(const Vector &r)
    {
        if (this->length != r.length)
        {
            delete[] this->data;
            this->length = r.length;
            if (this->length > 0)
                this->data = new T[this->length];
            else
                this->data = 0;
        }
        for (I i = 0; i < this->length; i++)
            (*this)(i) = r(i);
        return *this;
    }

    // Assignment operator.  Sets all elements of this vector to the scalar
    // right hand side `value`.
    Vector& operator=(T value)
    {
        for (I i = 0; i < this->length; i++)
            (*this)(i) = value;
        return *this;
    }

    // In-place add operator.  Computes the sum of this vector and `r` and
    // stores the result in this vector.
    Vector<T, I>& operator+=(const Vector &r)
    {
        for (I i = 0; i < this->length; i++)
            (*this)(i) += r(i);
        return *this;
    }

    // In-place subtract operator.  Computes the difference of this vector and
    // `r` and stores the result in this vector.
    Vector<T, I>& operator-=(const Vector &r)
    {
        for (I i = 0; i < this->length; i++)
            (*this)(i) -= r(i);
        return *this;
    }

    // Add operator.  Computes the sum of this vector and `r` and returns the
    // result.
    Vector operator+(const Vector<T, I> &r) const
    {
        Vector<T, I> result(this->length);
        for (I i = 0; i < this->length; i++)
            result(i) = (*this)(i)+r(i);
        return result;
    }

    // Subtract operator.  Computes the difference of this vector and `r` and
    // returns the result.
    Vector operator-(const Vector<T, I> &r) const
    {
        Vector<T, I> result(this->length);
        for (I i = 0; i < this->length; i++)
            result(i) = (*this)(i)-r(i);
        return result;
    }

    // Compare operator.  Returns `true` if the left and right hand side are
    // equal, `false` otherwise.
    bool operator==(const Vector &r) const
    {
        for (I i = 0; i < this->length; i++)
            if ((*this)(i) != r(i))
                return false;
        return true;
    }

    // Length of this vector.
    I length;

private:
    T *data;
};

// Scalar-vector multiplication.  Multiplies every element of `r` with scalar
// `l` and returns the result.
template<typename T, typename I>
Vector<T, I> operator*(T l, const Vector<T, I> &r)
{
    Vector<T, I> result(r.length);
    for (I i = 0; i < r.length; i++)
        result(i) = l*r(i);
    return result;
}

// Abstract matrix class.  Template argument `T` defines the type of the
// elements of the matrix and `I` the type used to index the matrix.  The
// `Matrix` has a shape, attributes `nrows` and `ncols`, and an abstract
// `matvec` method.
template<typename T, typename I>
class Matrix
{
public:
    // Constructor setting the shape of the matrix.
    Matrix(I _nrows, I _ncols): nrows(_nrows), ncols(_ncols) {}

    // Abstract `matvec` method.  To be implemented by derived classes.
    virtual Vector<T, I> matvec(const Vector<T, I> &vec) const = 0;

    // Shape of the matrix.
    I nrows;
    I ncols;
};


// Implementation of a dense matrix deriving from class `Matrix`.  Internally
// the matrix stores all elements in a linear array `data`.  Elements of a
// matrix can be retrieved using the `()` operator, e.g. `m(1,2)` returns the
// value of a `DenseMatrix m` at the second row and third column.
template<typename T, typename I>
class DenseMatrix: public Matrix<T, I>
{
public:
    // Default constructor.  Sets the shape of the matrix to `(0,0)`.
    DenseMatrix(): Matrix<T, I>(0, 0), data(0) {}

    // Constructor taking a shape as argument.  Allocates `data` when the shape
    // is nonzero.
    DenseMatrix(I _nrows, I _ncols): Matrix<T, I>(_nrows, _ncols)
    {
        if (this->nrows > 0 && this->ncols > 0)
            this->data = new T[this->nrows*this->ncols];
        else
            this->data = 0;
    }

    // Copy constructor.  Takes another `DenseMatrix` as an argument and copies
    // the data.
    DenseMatrix(const DenseMatrix &matrix): DenseMatrix(matrix.nrows, matrix.ncols)
    {
        for (I i = 0; i < this->nrows*this->ncols; i++)
            this->data[i] = matrix.data[i];
    }

    // Destructor.  Frees allocated `data`.
    ~DenseMatrix() { delete[] data; }

    // Get element at row `i` and column `j`, with `0 <= i < nrows` and `0 <= j
    // < ncols` (unchecked).  The first version is used when the instance is
    // marked `const`.
    const T& operator()(I i, I j) const
    {
        return this->data[i*this->ncols+j];
    }
    T& operator()(I i, I j)
    {
        return this->data[i*this->ncols+j];
    }

    // Assignment operator.  Resizes this matrix if necessary and copies the
    // right hand side `r`.
    DenseMatrix& operator=(const DenseMatrix &r)
    {
        if (this->nrows*this->ncols != r.nrows*r.ncols)
        {
            delete[] this->data;
            if (r.nrows > 0 && r.ncols > 0)
                this->data = new T[r.nrows*r.ncols];
            else
                this->data = 0;
        }
        this->nrows = r.nrows;
        this->ncols = r.ncols;
        for (I i = 0; i < this->length; i++)
            (*this)(i) = r(i);
        return *this;
    }

    // Assignment operator.  Sets all elements of this matrix to the scalar
    // right hand side `value`.
    DenseMatrix& operator=(T value)
    {
        for (I i = 0; i < this->nrows*this->ncols; i++)
            this->data[i] = value;
        return *this;
    }

    // Matrix vector product.
    virtual Vector<T, I> matvec(const Vector<T, I> &vec) const
    {
        Vector<T, I> result(this->nrows);
        for (I i = 0; i < this->nrows; i++)
        {
            result(i) = 0;
            for (I j = 0; j < this->ncols; j++)
                result(i) += (*this)(i,j)*vec(j);
        }
        return result;
    }

private:
    T* data;
};

// Standard inner product.
template<typename T, typename I>
T dot(const Vector<T, I> &l, const Vector<T, I> &r)
{
    T result = 0;
    for (I i = 0; i < l.length; i++)
        result += l(i)*r(i);
    return result;
}

// `A`-inner product.  `Matrix A` should be symmetric positive definite.
template<typename T, typename I>
T dot(const Matrix<T, I> &A, const Vector<T, I> &l, const Vector<T, I> &r)
{
    return dot(l, A.matvec(r));
}

// `std::ostream` operator.  Writes all elements of the `Vector` to the stream.
template<typename T, typename I>
std::ostream &operator<<(std::ostream &os, const Vector<T, I> &v)
{
    os << "[";
    for (I i = 0; i < v.length; i++)
    {
        if (i > 0)
            os << ", ";
        os << v(i);
    }
    os << "]";
    return os;
}

// `std::ostream` operator.  Writes all elements of the `Matrix` to the stream.
template<typename T, typename I>
std::ostream &operator<<(std::ostream &os, const DenseMatrix<T, I> &m)
{
    os << "[";
    for (I i = 0; i < m.nrows; i++)
    {
        if (i > 0)
            os << ", ";
        os << "[";
        for (I j = 0; j < m.ncols; j++)
        {
            if (j > 0)
                os << ", ";
            os << m(i,j);
        }
        os << "]";
    }
    os << "]";
    return os;
}
