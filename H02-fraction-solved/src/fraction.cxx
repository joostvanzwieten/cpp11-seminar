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
    Fraction(int _n, int _d, bool _normalize) : Fraction(_n, _d)
    {
        if (_normalize)
            normalize();
    }

    void normalize()
    {
        int f = gcd(n, d);
        n /= f;
        d /= f;
        if (d < 0)
        {
            n *= -1;
            d *= -1;
        }
    }

    Fraction normalized() const
    {
        Fraction f(*this);
        f.normalize();
        return f;
    }

    Fraction operator-() const { return Fraction(-n, d); }

    explicit operator double() const { return double(n)/double(d); }

    int n, d;
};

Fraction operator+(const Fraction &l, const Fraction &r)
{
    return Fraction(l.n*r.d+r.n*l.d, l.d*r.d);
}

Fraction operator-(const Fraction &l, const Fraction &r)
{
    return Fraction(l.n*r.d-r.n*l.d, l.d*r.d);
}

Fraction operator*(const Fraction &l, const Fraction &r)
{
    return Fraction(l.n*r.n, l.d*r.d);
}

Fraction operator/(const Fraction &l, const Fraction &r)
{
    return Fraction(l.n*r.d, l.d*r.n);
}

std::ostream &operator<<(std::ostream &os, const Fraction &f)
{
    return os << f.n << "/" << f.d;
}

int main()
{
    using namespace std;
    Fraction a(2, -3);
    Fraction a_normalized(2, -3, true);
    Fraction b(1, 5);

    cout << "a = " << a << endl;
    cout << "a_normalized = " << a_normalized << endl;
    cout << "b = " << b << endl;

    cout << "3*a+b = " << 3*a+b << " = " << (3*a+b).normalized() << endl;
    cout << "a-b = " << a-b << " = " << (a-b).normalized() << endl;
    cout << "5*a*b = " << 5*a*b << " = " << (5*a*b).normalized() << endl;
    cout << "3*a/b = " << 3*a/b << " = " << (3*a/b).normalized() << endl;
}
