#include "derivative.h"

// Default Constructor
derivCal::derivCal()
{
    equation = "No equation inputted";
    var = '0';
    equalsIndex = -1;
};

// Overloaded Constructor
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

string derivCal::getEquation() {
    return equation;
}

// solve:
// try all the derivative rules and return a string of the solved equation
// will return string "error" if something went wrong
// TODO(Adam): double check recursive logic
string derivCal::solve(string equation) {
    // base case

    // check for add sub
    vector<int> indices = derivCal::findAddSub(equation);

    if (indices.size() > 0) {
        string substring = "";
        for (int i = 0; i < indices.size() + 1; i++) {
            // EX: indicies.size() == 2
            //   indices = [6, 9]
            //   y=4x^2+3x+2
            //   two +/- signs = 3 segments
            int left, right;
            if (i == 0) {
                // first segment
                // equalsIndex to indices[i]
                left = equalsIndex;
                right = indices[i];
            } else if (i == indices.size()) {
                // last segment
                // indices[i-1] to end
                left = indices[i-1];
                right = indices.size();
            } else {
                // middle segment
                // indices[i-1] to indices[i]
                left = indices[i-1];
                right = indices[i];
            }

            int length = right - left - 1;
            string segment = equation.substr(left + 1, length);
            cout << "segment: " << segment << endl;
            substring += solve(segment);
            if (i != indices.size()) {
                substring += equation[indices[i]];
            }
        }

        return substring;
    }

    // TODO: check each rule
    return equation;
}

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

//findMult
//find mult symbol
vector<int> derivCal::findMult(string s) {
	vector<int> mults;      //my bag of mults

	for (int i = 0; i < s.size(); i++) {
		if (s.at(i) == '*') {
			mults.push_back(s.at(i));    //putting some mults in my bag
		}
	}

	return mults;     //you can have my bag now
}

// getVarIndex
// find the index of the variable in the equation vector
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

// findAddSub
// finds the position of every addition and subtraction sign in the given solution
vector<int> derivCal::findAddSub(string solution)
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

//findPowerrule
//checks if substring is powerrule
bool derivCal::isPowerRule(string s) {
	if(s.find("^") != string::npos) {
        return true;
    }
	return false;
}

//isSin
//checks if substring is sin
bool derivCal::isTan(string s) {
	if(s.find("sin(") != string::npos) {
        return true;
    }
	return false;
}

//isCos
//checks if substring is cos
bool derivCal::isTan(string s) {
	if(s.find("cos(") != string::npos) {
        return true;
    }
	return false;
}
//isTan
//checks if substring is tan
bool derivCal::isTan(string s) {
	if(s.find("tan(") != string::npos) {
        return true;
    }
	return false;
}
