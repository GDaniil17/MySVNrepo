#include<arrayd/arrayd.h>
#include<iostream>
#include<sstream>

int main()
{
	ArrayD tmp(10);
	for (int i = 0; i < tmp.size(); i++) {
		tmp[i] = i*1.0f;
	}
	for (int i = 0; i < tmp.size(); i++) {
		std::cout << tmp[i] << " ";
	}
	std::cout << "\n";
	tmp.resize(5);
	std::cout << "tmp.size() = " << tmp.size() << "\n";
	for (int i = 0; i < tmp.size(); i++) {
		std::cout << tmp[i] << " ";
	}
	ArrayD tmp2(7);
	for (int i = 0; i < tmp2.size(); i++){
		tmp2[i] = i * 10.0f;
	}
	tmp = tmp2;
	std::cout << "\n";
	for (int i = 0; i < tmp.size(); i++) {
		std::cout << tmp[i] << " ";
	}
	tmp = ArrayD(tmp2);
	std::cout << "\n";
	for (int i = 0; i < tmp.size(); i++) {
		std::cout << tmp[i] << " ";
	}
	std::cout << "\ntmp.size() = " << tmp.size() << "\n";
	int tmpin;
	std::cin >> tmpin;
}