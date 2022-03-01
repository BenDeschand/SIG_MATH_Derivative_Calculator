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

// getEquation
// accessor for string equation variable
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

    // +/- was find, solve each segment
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
            cout << "segment: " << segment << endl;  // DEBUG

            substring += solve(segment);
            if (i != indices.size()) {
                // add +/- symbols in between
                substring += equation[indices[i]];
            }
        }
        return substring;
    }

    // TODO: check each rule
    // TODO: account for constants
    string c = "c";
    string u = "u";
    string v = "v";
    int rule = getRule(equation, c, u, v);
    switch(rule) {
        case 1:  // c
            return "0";
        case 2:  // cx
            return "c";
        case 3:  // v (v is a char != var)
            return "0";
        // case 4:  // u + v
        // case 5:  // u - v
        case 6:  // -v
            // TODO: do we need this?
            return "-" + solve(v);
        case 7:  // u * v
            return  u + " * " + solve(v) + " + " + v + " * " + solve(u);
        case 8:  // u / v
            return  "(" + v + " * " + solve(u) + " - " + u + " * " + solve(v) + ") / " + v + "^2";
        case 9:  // u^c
            return c + " * " + u + "(" + c + " - 1) * " + solve(u);
        case 10:  // sqrt(u)
            return "(1/2) * " + solve(u) + "/ sqrt(" + u + ")";
        case 11:  // log(u)
            return solve(u) + " / " + u;
        case 12:  // exp(u)
            return "exp(" + u + ") * " + solve(u);
        case 13:  // sin(u)
            return "sin(" + u + ") * " + solve(u);
        case 14:  // cos(u)
            return "-sin(" + u + ") * " + solve(u);
        case 15:  // tan(u)
            return "(1 + tan( " + u + ")^2) * " + solve(u);
        default:
            return equation;
    }
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

int derivCal::getRule(string equation, string& c, string& u, string& v) {
    // find multi (Adam)
    if (equation.find("*") != std::npos) {
        u = equation.substr(0, equation.find('*'));
        v = equation.substr(equation.find('*') + 1);
        return 7;
    }

    // find division (Ben)
    if(equation.find('/') != string::npos) {
        u = equation.substr(0, equation.find('/'));
        v = equation.substr(equation.find('/') + 1);
        return 8;
    }

    // find parentheses (Dylan) MESSAGE FROM DYLAN: "Lemme know if these are okay before i do more of em, thanks"
    int paranthesis = 0;  //index of first paranthesis
    for(int i = 0; i < equation.size() && equation.at(i) != '('; i++) {
        paranthesis++;
    }

    //pow
    if(equation.substr(paranthesis - 1, 1) == "^") {
        c = equation.substr(paranthesis, equation.size() - 4); //prolly the right amount idk
        u = equation.substr(0, 1);
        return 9;
    }

    //sin
    if(equation.substr(paranthesis - 3, 3) == "sin") {
        u = equation.substr(paranthesis, equation.size() - 5); //-4 for the "sin(" and -1 for the ")".
        return 13;                                              //didn't do the math, didnt test it, hope it works
    }

    //cos
    if(equation.substr(paranthesis - 3, 3) == "cos") {
        u = equation.substr(paranthesis, equation.size() - 5);
        return 14;
    }

    //tan
    if(equation.substr(paranthesis - 3, 3) == "tan") {
        u = equation.substr(paranthesis, equation.size() - 5);
        return 15;
    }



        // use functions already made

    return 0;
}

//findMult
//find mult symbol
bool derivCal::findMult(string s) {
	if(s.find("*") != string::npos) {
        return true;
    }
	return false;
}

// findPowerrule
// checks if substring is powerrule
bool derivCal::isPowerRule(string s) {
	if(s.find("^") != string::npos) {
        return true;
    }
	return false;
}

// isSin
// checks if substring is sin
bool derivCal::isSin(string s) {
	if(s.find("sin(") != string::npos) {
        return true;
    }
	return false;
}

// isCos
// checks if substring is cos
bool derivCal::isCos(string s) {
	if(s.find("cos(") != string::npos) {
        return true;
    }
	return false;
}
// isTan
// checks if substring is tan
bool derivCal::isTan(string s) {
	if(s.find("tan(") != string::npos) {
        return true;
    }
	return false;
}
