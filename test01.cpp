#include <iostream>
#include <cassert>
#include "derivative.h"
using namespace std;

int test01();
int test02();
int test03();
int test04();
int test05();
int test06();

int main() {
    test01();
    test02();
    test03();
    test04();
    test05();
    test06();}

int test01()
{
    derivCal test1 = derivCal();
    cout << "Worked" << endl;

    return 0;
}

int test02() {
	derivCal test2 = derivCal("y=mx+b", "x");

	int index = test2.getVarIndex();
	assert(index == 3);

	return 0;
}

int test03() {
    derivCal test3 = derivCal("y=tan(x)/sin(x)", "x");
    cout << test3.solve() << endl;
    return 0;
}

int test04() {
    derivCal test4 = derivCal("y=2*x^(2)", "x");
    cout << test4.solve() << endl;
    return 0;
}

int test05() {
    derivCal test = derivCal("y=x/sin(x)", "x");
    cout << test.solve() << endl;
    return 0;
}

int test06() {
    derivCal test = derivCal("y=x*sin(x)", "x");
    cout << test.solve() << endl;
    return 0;
}

int test07() {
    return 0;
}

int test08() {
    return 0;
}

int test09() {
    return 0;
}

int test10() {
    return 0;
}

int test11() {
    derivCal test = derivCal("y=x^(sin(x))", "x");
    cout << test.solve() << endl;
    return 0;
}

int test12() {
    return 0;
}