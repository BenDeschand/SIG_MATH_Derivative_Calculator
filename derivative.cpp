#include "derivative.h"

derivCal::derivCal()
{
    equation = "No equation inputted";
    var = '0';
    equalsIndex = -1;
};

derivCal::derivCal(string equation, char var)
{
    this->equation = equation;
    this->var = var;
    this->eq = parseString(equation);
    setEqualsIndex();
};

void derivCal::setEqualsIndex() {
    for (int i = 0; i < eq.size(); i++) {
        if (eq[i] == '=') {
            equalsIndex = i;
            return;
        }
    }
    // if you get here without finding an equals sign, error
    throw string("no equals sign in equation");
}

// solve:
// try all the derivative rules and return a string of the solved equation
// will return string "error" if something went wrong
// TODO(Adam): double check recursive logic
string derivCal::solve(string sub_solution) {
    // base case 1
    if (sub_solution == "0" || sub_solution == "1")
        return "";

    // base case 2
    if (sub_solution.length() == 1 && sub_solution[0] == var)
        return "1";

    string solution = "error";
    bool found = false;

    // check for add sub
    vector<int> indices = findAddSub(sub_solution);
    if (indices.size() > 0) {
        for (int i = 0; i < indices.size(); i++) {
            // EX: indicies.size() == 2
            //   two +/- signs = 3 chunks
            string substring;
            if (i == 0) {
                // substring is = to indices[0]
                int len = indices[0] - equalsIndex + 1;
                substring = equation.substr(equalsIndex, len);
            } else {
                // substring is indices[i-1] to indices[i]
                // indices[i] - indices[i-1] + 1] is length
                int len = indices[i] - indices[i-1] + 1;
                substring = equation.substr(indices[i-1], len);
            }

            sub_solution += solve(substring);
        }
    }

    // TODO(Adam): check each rule

    return sub_solution;
}

vector<char> derivCal::parseString(string equation)
{
    vector<char> result;
    for(int i = 0; i < equation.length(); i++)
    {
        result.push_back(equation[i]);
    }

    return result;
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

// getVarIndex:
// returns the index of the first occurence of string var in vector eq
// returns -1 if not found
int derivCal::getVarIndex() {
    int index = -1;  // -1 if not found
    // iterate through vector
    for (int i = 0; i < eq.size(); i++) {
        if (eq[i] == var) {
            // if found break
            index = i;
            break;
        }
    }
    return index;
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
