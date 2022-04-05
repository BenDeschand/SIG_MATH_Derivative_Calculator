#include <iostream>
#include <cassert>
#include "derivative.h"
using namespace std;

void printSolveCorrect();
int test01();
int test02();
int test03();
int test04();
int test05();
int test06();
int test07();
int test08();
int test09();
int test10();
int test11();
int test12();

int main() {
    cout << endl << "----------  DERIVCAL TESTS ----------" << endl << endl;

    test01();
    test02();
    test03();
    test04();
    test05();
    test06();
    test07();
    test08();
    test09();
    test10();
    test11();
    test12();

    cout << "----------  DERIVCAL TESTS ----------" << endl << endl;
}

void printSolveCorrect(derivCal& test, string correct) {
   cout << test.getEquation() << endl;
   cout << "        " << "Solved: " << test.solve() << endl;
   cout << "        " << "Correct Answer: " << correct << endl << endl;
}

int test01() {
    cout << "test01: default constructor" << endl;
    derivCal test = derivCal();

    assert(test.getEquation() == "No Equation");
    assert(test.getVar() == "No Var");

    cout << "        " << "assert success" << endl << endl;
    return 0;
}

int test02() {
    cout << "test02: parameterized constructor" << endl;
	derivCal test = derivCal("y=mx+b", "x");

    assert(test.getEquation() == "y=mx+b");
    assert(test.getVar() == "x");
    assert(test.getEqualsIndex() == 1);

    cout << "        " << "assert success" << endl << endl;
	return 0;
}

int test03() {
    derivCal test = derivCal("y=tan(x)/sin(x)", "x");
    string correct = "dy/dx = (sec(x)^(2) * sin(x) - tan(x) * cos(x)) / sin(x)^(2)";
    cout << "test03: ";
    printSolveCorrect(test, correct);
    return 0;
}

int test04() {
    derivCal test = derivCal("y=2*x^(2)", "x");
    string correct = "4x";
    cout << "test04: ";
    printSolveCorrect(test, correct);
    return 0;
}

int test05() {
    derivCal test = derivCal("y=x/sin(x)", "x");
    string correct = "(sin(x)- x * cos(x)) / sin(x)^(2)";
    cout << "test05: ";
    printSolveCorrect(test, correct);
    return 0;
}

int test06() {
    derivCal test = derivCal("y=x*sin(x)", "x");
    string correct = "sin(x) + x * cos(x)";
    cout << "test06: ";
    printSolveCorrect(test, correct);
    return 0;
}

int test07() {
    derivCal test = derivCal("y=sqrt(x^(2))", "x");
    string correct = "x / abs(x)";
    cout << "test07: ";
    printSolveCorrect(test, correct);
    return 0;
}

int test08() {
    derivCal test = derivCal("y=log(2x)", "x");
    string correct = "1 / x";
    cout << "test08: ";
    printSolveCorrect(test, correct);
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
    string correct = "x^(sin(x)) (sin(x)/x + cos(x) * ln(x))";
    cout << "test11: ";
    printSolveCorrect(test, correct);
    return 0;
}

int test12() {
    return 0;
}
