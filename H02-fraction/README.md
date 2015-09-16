Homework 2
==========

In [src/fraction.cxx] a partial implementation of a fraction class is given.  In
the following three tasks you are going to extend and improve the class.

1.  Add the missing operators `-`, `*` and `/`.  See the definition of
    `operator+` in [src/fraction.cxx] for an example.

2.  Add a class method `normalize` that normalizes the numerator and denominator
    in-place, e.g. the fraction `14/-6` should become `-7/3`.  You may use the
    `gcd` function defined in [src/fraction.cxx] to find the greatest common
    divisor of two numbers.  Take into account that the `gcd` function can give
    a negative value if one or both of the parameters is negative.  Example
    code outline:

        class Fraction
        {
        public:
            ...

            void normalize()
            {
                // normalize `n` and `d` here
            }

            ...
        }

3.  Add a constructor to class `Fraction` that optionally normalizes the
    numerator and denominator upon instantiation.  The constructor should take a
    third parameter of type `bool` and if this parameter is `true` should call
    class method `normalize` defined in task 2.  Use the [delegating
    constructor] technique to call the already defined constructor before
    normalization.  The new constructor can be used as follows:

        Fraction a(14, -6, true); // result should equal `Fraction a(-7, 3);`

[src/fraction.cxx]: src/fraction.cxx
[delegating constructor]: http://en.cppreference.com/w/cpp/language/initializer_list#Delegating_constructor
