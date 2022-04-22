#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <arrayd/arrayd.h>
#include <iostream>
using namespace std;

TEST_CASE("subcases") {
	ArrayD tmp(10);
	CHECK(tmp.size() == 10);
	for (int i = 0; i < tmp.size(); i++) {
		tmp[i] = i*10.0f;
	}

	for (int i = 0; i < tmp.size(); i++) {
		CHECK(tmp[i] == i * 10.0f);
	}

	CHECK_THROWS(tmp.resize(-1));
	CHECK_NOTHROW(tmp.resize(5));

	ArrayD tmp2(7);
	for (int i = 0; i < tmp2.size(); i++) {
		tmp2[i] = i * 20.0f;
	}
	tmp = tmp2;
	CHECK(tmp.size() == 7);
	for (int i = 0; i < tmp.size(); i++) {
		CHECK(tmp[i] == i * 20.0f);
	}
	tmp = ArrayD(tmp2);
	CHECK(tmp.size() == 7);
	for (int i = 0; i < tmp.size(); i++) {
		CHECK(tmp[i] == i * 20.0f);
	}
}