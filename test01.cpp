#include <iostream>
#include <cassert>
#include "derivative.h"
using namespace std;

int test01();
int test02();

int main() {
    test01();
    test02();
}

int test01()
{
    derivCal test1 = derivCal();
    cout << "Worked" << endl;

    return 0;
}

int test02() {
	derivCal test2 = derivCal("y=mx+b", 'x');

	int index = test2.getVarIndex();
	assert(index == 3);

	return 0;
}
