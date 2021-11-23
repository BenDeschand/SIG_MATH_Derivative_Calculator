#include "derivative.h"

derivCal::derivCal()
{
    equation = "No equation inputted";
    var = '0';
};

derivCal::derivCal(string equation, char var)
{
    this->equation = equation;
    this->var = var;
};

string derivCal::getString()
{
    return equation;
};

vector<char> derivCal::getVector()
{
    return eq;
};

char derivCal::getVar()
{
    return var;
}

string derivCal::powerRule(char var; string s) {
	string result;
	int exponent;      //athiest malding rn (he doesn't believe in a higher power)
	int constant;

	int sIndex = 0;
	int eIndex = s.find(var);
	constant = stoi(s.substr(sIndex, eIndex));  //kinkyyarn for constant

	int sIndex = s.find("^(");
	int eIndex = s.find(")");
	exponent = stoi(s.substr(sIndex, eIndex));  //substring for exponent

	if (exponent == 1) {
		result += var;
	}
	else if (exponent == 0) {
		return result;
	}
	else {
		result += var + "^" + to_string(exponent);
	}
	return result;
}
