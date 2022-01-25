#include "derivative.h"

// Default Constructor
derivCal::derivCal()
{
    equation = "No equation inputted";
    var = '0';
};

// Overloaded Constructor
derivCal::derivCal(string equation, char var)
{
    this->equation = equation;
    this->var = var;
    this->eq = parseString(equation);
};

// parseString
// parses the string into a vector
vector<char> derivCal::parseString(string equation)
{
    vector<char> result;
    for(int i = 0; i < equation.length(); i++)
    {
        result.push_back(equation[i]);
    }

    return result;
};

// getString
// accessor for equation
string derivCal::getString()
{
    return equation;
};

// getVector
// accessor for eq
vector<char> derivCal::getVector()
{
    return eq;
};

// getVar
// accessor for var
char derivCal::getVar()
{
    return var;
}

// getVarIndex
// find the inex of the variable in the equation vector
int derivCal::getVarIndex() {
    int index = -1;
    for (int i = 0; i < eq.size(); i++) {
        if (eq[i] == var) {
            index = i;
            break;
        }
    }
    return index;
};

// findAddSub
// finds the position of every addition and subtraction sign in the given solution
vector<int> findAddSub(string solution)
{
    vector<int> result;

    for(int i = 0; i < solution.size(); i++)
    {
        if(solution.at(i) == '+' || solution.at(i) == '-')
        {
            result.push_back(i);
        }
    }

    return result;
};

string derivCal::powerRule(char var, int constant, int exponent) {
	string result;

	result = to_string(constant * exponent);

	exponent -= 1;

	if (exponent == 1) {
		result += var;
	}
	else if (exponent == 0) {
		return result;
	}
	else {
		result += var + "^(" + to_string(exponent) + ")";
	}
	return result;
}
