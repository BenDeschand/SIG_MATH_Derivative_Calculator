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
int test07();
int test08();

int main() {
    test01();
    test02();
    test03();
    test04();
    test05();
    test06();
    test07();
    test08();
}

int test01()
{
    cout << "test01: constructor" << endl;
    derivCal test = derivCal();
    cout << "\n        constructor worked" << endl;

    return 0;
}

int test02() {
    cout << "test02: getVarIndex()" << endl;
	derivCal test = derivCal("y=mx+b", "x");

	int index = test.getVarIndex();
	assert(index == 3);

    cout << "\n        getVarIndex() worked" << endl;

	return 0;
}

int test03() {
    derivCal test = derivCal("y=tan(x)/sin(x)", "x");
    cout << "test03: Equation: " << test.getEquation() << "\n        Solved: " << test.solve() << endl;
    return 0;
}

int test04() {
    derivCal test = derivCal("y=2*x^(2)", "x");
    cout << "test04: Equation: " << test.getEquation() << "\n        Solved: " << test.solve() << endl;
    return 0;
}

int test05() {
    derivCal test = derivCal("y=x/sin(x)", "x");
    cout << "test05: Equation: " << test.getEquation() << "\n        Solved: " << test.solve() << endl;
    return 0;
}

int test06() {
    derivCal test = derivCal("y=x*sin(x)", "x");
    cout << "test06: Equation: " << test.getEquation() << "\n        Solved: " << test.solve() << endl;
    return 0;
}

int test07() {
    derivCal test = derivCal("y=sqrt(x^(2))", "x");
    cout << "test07: Equation: " << test.getEquation() << "\n        Solved: " << test.solve() << endl;
    return 0;
}

int test08() {
    derivCal test = derivCal("y=log(2x)", "x");
    cout << "test08: Equation: " << test.getEquation() << "\n        Solved: " << test.solve() << endl;
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
