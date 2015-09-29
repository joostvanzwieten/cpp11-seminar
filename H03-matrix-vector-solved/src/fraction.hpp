#include <iostream>

inline int gcd(int a, int b)
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

    Fraction() {}
    Fraction(int _n, int _d=1): n(_n), d(_d) {}
    Fraction(int _n, int _d, bool _normalize) : Fraction(_n, _d)
    {
        if (_normalize)
            this->normalize();
    }

    void normalize()
    {
        int f = gcd(this->n, this->d);
        this->n /= f;
        this->d /= f;
        if (this->d < 0)
        {
            this->n *= -1;
            this->d *= -1;
        }
    }

    Fraction normalized() const
    {
        Fraction f(*this);
        f.normalize();
        return f;
    }

    Fraction operator-() const { return Fraction(-this->n, this->d); }
    Fraction operator+=(const Fraction &r);
    Fraction operator-=(const Fraction &r);
    Fraction operator*=(const Fraction &r);
    Fraction operator/=(const Fraction &r);

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

Fraction Fraction::operator+=(const Fraction &r) { (*this) = (*this)+r; }
Fraction Fraction::operator-=(const Fraction &r) { (*this) = (*this)-r; }
Fraction Fraction::operator*=(const Fraction &r) { (*this) = (*this)*r; }
Fraction Fraction::operator/=(const Fraction &r) { (*this) = (*this)/r; }

bool operator==(const Fraction &l, const Fraction &r) { return l.n*r.d == r.n*l.d; }
bool operator!=(const Fraction &l, const Fraction &r) { return l.n*r.d != r.n*l.d; }

std::ostream &operator<<(std::ostream &os, const Fraction &f)
{
    return os << f.n << "/" << f.d;
}
