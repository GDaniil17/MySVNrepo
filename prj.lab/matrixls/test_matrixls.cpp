#include <iostream>
#include <sstream>
#include <matrixls/matrixls.h>

using namespace std;

int main()
{
    MatrixLs tmp(3, 2);
    cout << "tmp" << "\n";
    for (int i = 0; i < tmp.rowCount(); i++) {
        for (int j = 0; j < tmp.colCount(); j++) {
            tmp.at(i, j) = i + j + 2.0;
            cout << tmp.at(i, j) << " ";
        }
        cout << "\n";
    }

    MatrixLs tmp2(2, 3);
    cout << "tmp2" << "\n";
    for (int i = 0; i < tmp2.rowCount(); i++) {
        for (int j = 0; j < tmp2.colCount(); j++) {
            tmp2.at(i, j) = i + j + 2.0;
            cout << tmp2.at(i, j) << " ";
        }
        cout << "\n";
    }
    cout << "tmp3" << "\n";
    auto tmp3 = tmp2.multiply(tmp);
    
    for (int i = 0; i < tmp3.rowCount(); i++) {
        for (int j = 0; j < tmp3.colCount(); j++) {
            cout << tmp3.at(i, j) << " ";
        }
        cout << "\n";
    }
    
    cout << "tmp3 done" << tmp3.rowCount() << " col = " << tmp3.colCount() << "\n";

    tmp.swapColumns(0, 1);
    tmp = tmp.transpose();

    cout << "tmp transposed" << "\n";
    for (int i = 0; i < tmp.rowCount(); i++) {
        for (int j = 0; j < tmp.colCount(); j++) {
            cout << tmp.at(i, j) << " ";
        }
        cout << "\n";
    }
}