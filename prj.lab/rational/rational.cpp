#include <iostream>
#include <sstream>
#include <locale>
#include <string>
#include <algorithm>
#include <rational/rational.h>
#include <limits>

Rational::Rational(const int chislitel, const int znamenatel) {
    chis = chislitel;
    znam = znamenatel;
    check();
    Rational::simple();
}

void Rational::check() {
    if (znam == 0) { 
        throw std::invalid_argument("Division by zero");
    }
}

int Rational::gcd(int a, int b) {
    if (a == 0 || b == 0) {
        if (a > b) {
            return a;
        }
        return b;
    }
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return(a);
}

Rational& Rational::operator+=(const Rational& first) noexcept {
    Rational tmp(chis * first.znam + first.chis * znam, znam * first.znam);
    chis = tmp.chis;
    znam = tmp.znam;
    Rational::simple();
    return *this;
}
Rational& Rational::operator/=(const Rational& first) {
    if (first.chis == 0) {
        throw std::invalid_argument("Division by zero");
    }
    chis *= first.znam;
    znam *= first.chis;
    Rational::simple();
    return *this;
};

Rational& Rational::operator*=(const Rational& first) noexcept {
    chis *= first.chis;
    znam *= first.znam;
    Rational::simple();
    return *this;
};

Rational& Rational::operator-=(const Rational& first) noexcept {
    Rational tmp(chis, znam);
    chis *= first.znam;
    znam *= first.znam;
    chis -= first.chis * tmp.znam;
    Rational::simple();
    return *this;
};

bool Rational::operator==(const Rational& rhs)const noexcept {
    return chis * rhs.znam == rhs.chis * znam;
}

bool Rational::operator!=(const Rational& first)const noexcept {
    return chis * first.znam != first.chis * znam;
}

bool Rational::operator<(const Rational& first)const noexcept {
    return chis * first.znam < first.chis * znam;
}

bool Rational::operator>(const Rational& first)const noexcept {
    return chis * first.znam > first.chis * znam;
}

bool Rational::operator>=(const Rational& first)const noexcept {
    return chis * first.znam >= first.chis * znam;
}

bool Rational::operator<=(const Rational& first)const noexcept {
    return chis*first.znam <= first.chis*znam;
}

Rational operator+(const Rational& first, const Rational& second) noexcept {
    Rational sum;
    sum.chis = first.chis * second.znam + second.chis * first.znam;
    sum.znam = first.znam * second.znam;
    sum.simple();
    return sum;
};

Rational operator-(const Rational& first, const Rational& second) noexcept {
    Rational res;
    res.chis = first.chis * second.znam - second.chis * first.znam;
    res.znam = first.znam * second.znam;
    res.simple();
    return res;
};

Rational operator*(const Rational& first, const Rational& second) noexcept {
    Rational mul;
    mul.chis = first.chis * second.chis;
    mul.znam = first.znam * second.znam;
    mul.simple();
    return mul;
}

Rational operator/(const Rational& first, const Rational& second) {
    Rational div;
    div.chis = first.chis * second.znam;
    div.znam = first.znam * second.chis;
    div.check();
    div.simple();
    return div;
};

void Rational::simple() {
    int i = gcd(chis, znam);
    chis /= i;
    znam /= i;
    if (znam < 0) {
        chis = -chis;
        znam = -znam;
    }
}

std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) {
    return rhs.WriteTo(ostrm);
}

std::istream& operator>>(std::istream& istrm, Rational& rhs) {
    return rhs.ReadFrom(istrm);
}

std::ostream& Rational::WriteTo(std::ostream& ostrm) const {
    ostrm <<chis << sep << znam;
    return ostrm;
}

std::istream& Rational::ReadFrom(std::istream& istrm) {
    int ch = 0;
    int zn = 0;
    char sep{ '/' };
    char delim;

    istrm >> ch;
    delim = istrm.get();

    if (istrm.peek() == ' ') {
        istrm.setstate(std::ios_base::failbit);
    }
    istrm >> zn;
    if (delim != sep || zn < 0) {
        istrm.setstate(std::ios_base::failbit);
    }
    if (istrm.fail() == false) {
        chis = ch;
        znam = zn;
        simple();
    }
    return istrm;
}