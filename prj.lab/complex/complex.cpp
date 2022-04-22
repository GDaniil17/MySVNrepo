#include<complex/complex.h>

#include<iostream>
#include<limits>
#include<stdexcept>

Complex::Complex(const double real) : Complex(real, 0.0) {
}

Complex::Complex(const double real, const double imaginary) : re(real), im(imaginary) {
}

bool Complex::operator==(const Complex& rhs)const noexcept {
	return std::abs(re - rhs.re) < 2 * std::numeric_limits<double>::epsilon() && std::abs(im - rhs.im) < 2 * std::numeric_limits<double>::epsilon();
}

Complex& Complex::operator+=(const Complex& rhs) noexcept {
	re += rhs.re;
	im += rhs.im;
	return *this;
}

Complex& Complex::operator-=(const Complex& rhs) noexcept {
	re -= rhs.re;
	im -= rhs.im;
	return *this;
}

Complex operator+(const Complex& lhs, const Complex& rhs) noexcept {
	Complex sum(lhs);
	sum += rhs;
	return sum;
}

Complex& Complex::operator*=(const Complex& rhs) noexcept {
	double tmp_re, tmp_im;
	tmp_re = re * rhs.re - im * rhs.im;
	tmp_im = im * rhs.re + re * rhs.im;
	re = tmp_re;
	im = tmp_im;
	return *this;
}

Complex operator-(const Complex& lhs, const Complex& rhs) noexcept {
	return Complex(lhs.re - rhs.re, lhs.im - rhs.im);
}

Complex& Complex::operator/=(const double rhs) {
	re /= rhs;
	im /= rhs;
	return *this;
}

Complex& Complex::operator/=(const Complex& rhs) {
	const double denum = rhs.re * rhs.re + rhs.im * rhs.im;
	if ((rhs.re * rhs.re + rhs.im * rhs.im) < 2 * std::numeric_limits<double>::epsilon()) {
		throw std::invalid_argument("Division by zero in Complex::operator /= (const Complex& rhs), please fix the input !");
	}
	operator*=(Complex(rhs.re, -rhs.im));
	operator/=(denum);
	/*
	double tmp_re, tmp_im;
	tmp_re = (re * rhs.re + im * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im);
	tmp_im = (im * rhs.re - re * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im);
	re = tmp_re;
	im = tmp_im;
	*/
	return *this;
}

std::ostream& Complex::writeTo(std::ostream& ostrm) const {
	ostrm << leftBrace << re << separator << im << rightBrace;
	return ostrm;
}

std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs) {
	return rhs.writeTo(ostrm);
}

std::istream& operator>>(std::istream& istrm, Complex& rhs) {
	return rhs.readFrom(istrm);
}

std::istream& Complex::readFrom(std::istream& istrm) {
	char leftBrace(0);
	double real(0.0);
	char comma(0);
	double imaganary(0.0);
	char rightBrace(0);
	istrm >> leftBrace >> real >> comma >> imaganary >> rightBrace;
	if (istrm.good()) {
		if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma)
			&& (Complex::rightBrace == rightBrace)) {
			re = real;
			im = imaganary;
		}
		else {
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}