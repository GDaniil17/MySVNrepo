#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include<doctest/doctest.h>
#include<rational/rational.h>
#include <iostream>

TEST_CASE("bool and arithmetics")
{
	Rational a(1, 4);
	Rational b(1, 4);
	std::cout << a.gcd(2,4);
	CHECK(Rational(-2, 8) == Rational(1, -4));
	CHECK((a-Rational(1,8)) == Rational(1, 8));
	CHECK((a + b) == Rational(1, 2));
	CHECK((b - a) == Rational(0, 16));
	CHECK_THROWS(Rational(0, 0));
	CHECK((a - Rational(1, 8)) == Rational(1, 8));
	CHECK((a * b) == Rational(1, 16));
	a = Rational(1, 2);
	b = Rational(2, 4);
	CHECK((a == b) == true);
	CHECK((a != b) == false);
	CHECK((a < b) == false);
	CHECK((a >= b) == true);
	CHECK((a > b) == false);
	CHECK((a <= b) == true);
}