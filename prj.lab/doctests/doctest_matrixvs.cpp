#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <matrixvs/matrixvs.h>
#include <iostream>
using namespace std;

TEST_CASE("subcases") {
    MatrixVs tmp(3, 2);
    for (int i = 0; i < tmp.rowCount(); i++) {
        for (int j = 0; j < tmp.colCount(); j++) {
            tmp.at(i, j) = i + j + 2.0;
        }
    }

    MatrixVs tmp2(2, 3);
    for (int i = 0; i < tmp2.rowCount(); i++) {
        for (int j = 0; j < tmp2.colCount(); j++) {
            tmp2.at(i, j) = i + j + 2.0;
        }
    }
    auto tmp3 = tmp2.multiply(tmp);

    for (int i = 0; i < tmp.rowCount(); i++) {
        for (int j = 0; j < tmp.colCount(); j++) {
            cout << tmp.at(i, j);
        }
        cout << "\n";
    }

    tmp.swapColumns(0, 1);
    tmp3 = tmp.transpose();
    cout << "\n";
    for (int i = 0; i < tmp3.rowCount(); i++) {
        for (int j = 0; j < tmp3.colCount(); j++) {
            cout << tmp3.at(i, j);
        }
        cout << "\n";
    }

    /*
    CHECK(Complex(13, 1) / Complex(7, -6) == Complex(1, 1));
    CHECK_THROWS(a / Complex());
    CHECK_NOTHROW(Complex(7, 5));
    */
}