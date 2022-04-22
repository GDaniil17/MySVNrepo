#include<stackl/stackl.h>
#include<iostream>
#include<sstream>
using namespace std;

int main() {
	StackL tmp;
	tmp.push(11.0f);
	std::cout << tmp.is_empty() << "\n";
	tmp.push(20.0f);
	std::cout << tmp.is_empty() << "\n";
	std::cout << tmp.top() << "\n";
	tmp.pop();
	std::cout << tmp.top() << "\n";
	tmp.pop();
	tmp.pop();
	std::cout << tmp.is_empty() << "\n";
}