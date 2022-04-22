#include <complex/complex.h>
#include <iostream>
#include <sstream>

bool testParse(const std::string& str) {
	using namespace std;
	istringstream istrm(str);
	Complex z;
	istrm >> z;
	if (istrm.good()) {
		cout << "Read success: " << str << " -> " << z << endl;
	}
	else {
		cout << "Read error : " << str << " -> " << z << endl;
	}
	return istrm.good();
}

void Test(Complex f, Complex s, char symbol, Complex ans) {
	if (symbol == '+') {
		if (f + s == ans) {
			std::cout << "Correct!" << "\n";
		}
		else {
			std::cout << "Incorrect" << f << '+' << s << "!=" << ans << "\n";
			std::cout << "ans = " << f + s << "\n";
		}
	}
	else if (symbol == '-') {
		if (f - s == ans) {
			std::cout << "Correct!" << "\n";
		}
		else {
			std::cout << "Incorrect" << f << '-' << s << "!=" << ans << "\n";
			std::cout << "ans = " << f - s << "\n";
		}
	}
	else if (symbol == '*') {
		if (f * s == ans) {
			std::cout << "Correct!" << "\n";
		}
		else {
			std::cout << "Incorrect" << f << '*' << s << "!=" << ans << "\n";
			std::cout << "ans = " << f * s << "\n";
		}
	}
	else if (symbol == '/') {
		if (f / s == ans) {
			std::cout << "Correct!" << "\n";
		}
		else {
			std::cout << "Incorrect" << f << '/' << s << "!=" << ans << "\n";
			std::cout << "ans = " << f / s << "\n";
		}
	}
	else {
		std::cout << "Incorrect input" << f << symbol << s << " ?= " << ans << "\n";
	}
}

void TestWithoutSign(Complex f, Complex ans) {
	if (f == ans) {
		std::cout << "Correct!" << "\n";
	}
	else {
		std::cout << "Incorrect" << f << "!=" << ans << "\n";
		std::cout << "ans = " << f << "\n";
	}
}

void TestData() {
	testParse("{8.9,9}");
	testParse("{8.9,  9}");
	testParse("{8.9,9");
	testParse("8.9,9");
	testParse("8.9,9}");
	Complex a = Complex(3, 4);
	Complex b = Complex(8, 9);
	Test(a, b, '+', Complex(11, 13));
	Test(b, a, '-', Complex(5, 5));
	Test(Complex(1, -1), Complex(3, 6), '*', Complex(9, 3));
	Test(Complex(13, 1), Complex(7, -6), '/', Complex(1, 1));
	a += b;
	std::cout << "a+=b" << "\n";
	TestWithoutSign(a, Complex(11, 13));
	a = Complex(3, 4);
	b -= a;
	std::cout << "b-=a" << "\n";
	TestWithoutSign(b, Complex(5, 5));
	a = Complex(1, -1);
	b = Complex(3, 6);
	a *= b;
	std::cout << "a*=b" << "\n";
	TestWithoutSign(a, Complex(9, 3));
	a = Complex(1, -1);
	b = Complex(3, 6);
	b *= a;
	std::cout << "b*=a" << "\n";
	TestWithoutSign(b, Complex(9, 3));
	a = Complex(13, 1);
	b = Complex(7, -6);
	a /= b;
	std::cout << "a/=b" << "\n";
	TestWithoutSign(a, Complex(1, 1));

}

int main() {
	TestData();
	return 0;
}