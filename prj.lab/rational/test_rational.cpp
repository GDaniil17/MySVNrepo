#include<rational/rational.h>
#include<iostream>
#include<sstream>
using namespace std;

int main()
{
	Rational a(7, 3); 
	Rational b(4, 2);
	Rational tmp;
	tmp = a * b;
	bool x = tmp == tmp;
	cout << x;

}