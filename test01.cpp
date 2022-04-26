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
int test13();
int test14();
int test15();

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
    test13();
    test14();
    test15();

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

    derivCal test = derivCal("y=log(x^(2))", "x");
    string correct = "2 / x";
    cout << "test09: ";
    printSolveCorrect(test, correct);

    return 0;
}

int test10() {

    derivCal test = derivCal("y=sin(x)/cos(x)", "x");
    string correct = "1/cos(x)^2";
    cout << "test10: ";
    printSolveCorrect(test, correct);

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
    derivCal test = derivCal("y=sin(x^(2))+cos(x^(2))", "x");
    string correct = "2x * cos(x^(2)) - 2x * sin(x^(2))";
    cout << "test12: ";
    printSolveCorrect(test, correct);
    return 0;
}

int test13() {
    derivCal test = derivCal("y=2x+3", "x");
    string correct = "m";
    cout << "test13: ";
    printSolveCorrect(test, correct);
    return 0;
}

int test14() {
    derivCal test = derivCal("y=x+x^(2)", "x");
    string correct = "1 + 2 * x";
    cout << "test14: ";
    printSolveCorrect(test, correct);
    return 0;
}

int test15() {
    derivCal test = derivCal("y=sqrt(3 * x^(2)) + tan(4 * x^(2))", "x");
    string correct = "";
    cout << "test15: ";
    printSolveCorrect(test, correct);
    return 0;
}
