#ifndef RATIONAL_RATIONAL_H_20211007
#define RATIONAL_RATIONAL_H_20211007

#include <iostream>
#include <algorithm>

struct  Rational
{
    Rational operator-() const noexcept { return Rational(-chis, znam); }

    Rational& operator+=(const Rational& arg) noexcept;

    Rational& operator/=(const Rational& first);

    Rational& operator*=(const Rational& rhs) noexcept;

    Rational& operator-=(const Rational& rhs) noexcept;

    Rational& operator=(const Rational& rhs) = default;

    bool operator==(const Rational& rhs)const noexcept;

    bool operator!=(const Rational& rhs)const noexcept;

    bool operator<(const Rational& first)const noexcept;

    bool operator>(const Rational& first)const noexcept;

    bool operator>=(const Rational& first)const noexcept;

    bool operator<=(const Rational& first)const noexcept;

    int gcd(int a, int b);

    Rational() = default;
    explicit Rational(const int chislit) { chis = chislit; znam = 1; Rational::simple(); };
    Rational(const int chislitel, const int znamenatel);
    ~Rational() = default;
    Rational(const Rational& rhs) = default;

    void check();

    std::ostream &WriteTo(std::ostream &ostrm) const;
    std::istream &ReadFrom(std::istream &istrm);

    int chis{ 0 };
    int znam{ 1 };
    static const char sep{ '/' };

    void simple();
};

Rational operator+(const Rational& first, const Rational& second) noexcept;
Rational operator*(const Rational& first, const Rational& second) noexcept;
Rational operator-(const Rational& first, const Rational& second) noexcept;
Rational operator/(const Rational& first, const Rational& second);
std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs);
std::istream& operator>>(std::istream& istrm, Rational& rhs);

#endif RATIONAL_RATIONAL_H_20211007
