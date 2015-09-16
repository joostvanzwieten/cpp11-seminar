#include <iostream>

int gcd(int a, int b)
{
    while (b)
    {
        int c = a%b;
        a = b;
        b = c;
    }
    return a;
}

class Fraction
{
public:

    Fraction(int _n, int _d=1): n(_n), d(_d) {}
    // TODO: Task 3: Add a constructor here!

    // TODO: Task 2: Add the method `normalize` here!

    Fraction operator-() const { return Fraction(-n, d); }

    explicit operator double() const { return double(n)/double(d); }

    int n, d;
};

Fraction operator+(const Fraction &l, const Fraction &r)
{
    return Fraction(l.n*r.d+r.n*l.d, l.d*r.d);
}

// TODO: Task 1: Add operators `-`, `*` and `/` here!

std::ostream &operator<<(std::ostream &os, const Fraction &f)
{
    return os << f.n << "/" << f.d;
}

int main()
{
    using namespace std;
    Fraction a(2, -3);
    Fraction b(1, 3);
    Fraction c = 1+a+b;
    cout << "fraction: " << c << ", double: " << double(c) << endl;
}
