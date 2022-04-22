#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <complex/complex.h>

#include <iostream>
using namespace std;

TEST_CASE("lots of nested subcases") {
    Complex a = Complex(3, 4);
    Complex b = Complex(8, 9);
    CHECK(-a == Complex(-3, -4));
    CHECK(a+b == Complex(11, 13));
    CHECK(b-a == Complex(5, 5));
    CHECK(Complex(1, -1) * Complex(3, 6) == Complex(9, 3));
    CHECK(Complex(13, 1) / Complex(7, -6) == Complex(1, 1));
    CHECK_THROWS(a / Complex());
    CHECK_NOTHROW(Complex(7, 5));
}