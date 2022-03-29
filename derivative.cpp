#include "derivative.h"

// default constructor
derivCal::derivCal() {
    equation = "No Equation";
    var = "No Var";
    equalsIndex = -1;
}

// parameterized constructor
derivCal::derivCal(string equation, string var) {
    this->equation = equation;
    this->var = var;

    equalsIndex = equation.find('=');
    if (equalsIndex == string::npos) {
        throw string("no equals sign in equation");
    }
}


// solve:
//   call derive method
//   TODO: clean equation
string derivCal::solve() {
    string ans;
    string sub_equation;

    // deletes the equal sign from the equation
    if(equation.find('=') < equation.find(var[0])) {
        sub_equation = equation.substr(equation.find('=') + 1);
    } else {
        sub_equation = equation.substr(0, equation.find('='));
    }

    ans = derive(sub_equation);

    return ans;
}

// derive:
//   try all the derivative rules and return a string of the solved equation
string derivCal::derive(string equation) {
    // TODO: base case?

    // check for +/- signs
    vector<int> indices = findAddSub(equation);

    // +/- was found, solve each segment
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
            //cout << "segment: " << segment << endl;  // DEBUG

            substring += derive(segment);
            if (i != indices.size()) {
                // add +/- symbols in between
                substring += equation[indices[i]];
            }
        } // end for

        return substring;
    } // end if

    // TODO: account for constants?
    string c = "c";
    string u = "u";
    string v = "v";
    int rule = getRule(equation, c, u, v);
    switch(rule) {
        case 1:  // c
            return "0";
        case 2:  // cx
            return c;
        case 3:  // v (v is a char != var)
            return "0";
        // case 4:  // u + v
        // case 5:  // u - v
        case 6:  // -v
            // TODO: do we need this?
            return "-" + derive(v);
        case 7:  // u * v
            return  u + " * " + derive(v) + " + " + v + " * " + derive(u);
        case 8:  // u / v
            return  "(" + v + " * " + derive(u) + " - " + u + " * " + derive(v) + ") / " + v + "^2";
        case 9:  // u^(c)
            return c + " * " + u + "^(" + c + " - 1) * " + derive(u);
        case 10:  // sqrt(u)
            return "(1 / 2) * " + derive(u) + " / sqrt(" + u + ")";
        case 11:  // log(u)
            return derive(u) + " / " + u;
        case 12:  // exp(u)
            return "exp(" + u + ") * " + derive(u);
        case 13:  // sin(u)
            return "cos(" + u + ") * " + derive(u);
        case 14:  // cos(u)
            return "-sin(" + u + ") * " + derive(u);
        case 15:  // tan(u)
            return "(1 + tan( " + u + ")^2) * " + derive(u);
        case 16:  // ln(u)
            return derive(u) + " / " + u;
        default:
            return equation;
    }
}


// getRule:
//   return an int corresponding to the derivative rule to be used
//   guide at https://www.cs.utexas.edu/users/novak/asg-symdif.html
int derivCal::getRule(string equation, string& c, string& u, string& v) {
    //cout << "equation: " << equation << endl;

    // find multiplication sign
    if (equation.find("*") != string::npos) {
        u = equation.substr(0, equation.find('*'));
        v = equation.substr(equation.find('*') + 1);
        return 7;
    }

    // find division sign
    if(equation.find('/') != string::npos) {
        //cout << "found division" << endl;
        u = equation.substr(0, equation.find('/'));
        v = equation.substr(equation.find('/') + 1);
        return 8;
    }

    // find parentheses
    int parentheses = equation.find('(');  // index of first parentheses
    // TODO: we do equation.substr(parentheses + 1, equation.find(')') - parentheses - 1)
    //       so many times, simplify it

    if(parentheses != string::npos) {  // there are parentheses
        // power rule
        if(equation.substr(parentheses - 1, 1) == "^") {
            c = equation.substr(parentheses + 1, equation.find(')') - parentheses - 1);
            u = equation.substr(0, equation.find('^'));
            // cout << "c: " << c << endl;
            // cout << "u: " << u << endl;
            return 9;
        }

        // sqrt
        if(parentheses > 3) {
            if(equation.substr(parentheses - 4, 4) == "sqrt") {
                u = equation.substr(parentheses + 1, equation.find(')') - parentheses - 1);
                // cout << "u: " << u << endl;
                // TODO: we're dropping parentheses here with y=sqrt(x^(2)) since there's an extra one
                return 10;
            }
        }

        // log
        if(equation.substr(parentheses - 3, 3) == "log") {
            u = equation.substr(parentheses + 1, equation.find(')') - parentheses - 1);
            return 11;
        }

         // ln (same as log)
        if(equation.substr(parentheses - 2, 2) == "ln") {
            u = equation.substr(parentheses + 1, equation.find(')') - parentheses - 1);
            return 11;
        }

        // exp
        if(equation.substr(parentheses - 3, 3) == "exp") {
            u = equation.substr(parentheses + 1, equation.find(')') - parentheses - 1);
            return 12;
        }

        // sin
        if(equation.substr(parentheses - 3, 3) == "sin") {
            u = equation.substr(parentheses + 1, equation.find(')') - parentheses - 1); // -4 for the "sin(" and -1 for the ")".
            return 13;
        }

        // cos
        if(equation.substr(parentheses - 3, 3) == "cos") {
            u = equation.substr(parentheses + 1, equation.find(')') - parentheses - 1);
            return 14;
        }

        // tan
        if(equation.substr(parentheses - 3, 3) == "tan") {
            u = equation.substr(parentheses + 1, equation.find(')') - parentheses - 1);
            return 15;
        }

    } else {  // no parentheses
        // TODO: comment this. what is it doing and why????
        int varPos = equation.find(var[0]);
        if(varPos >= 0) {
            if(equation.size() > 1) {
                c = equation.substr(0, varPos);
                return 2;
            } else {
                c = "1";
                return 2;
            }
        } else {
            return 1;
        }
    }

    return 0;
}


// findAddSub:
//   finds the position of every addition and subtraction sign in the given solution
vector<int> derivCal::findAddSub(string solution) {
    vector<int> indices;

    for(int i = 0; i < solution.size(); i++) {
        if(solution.at(i) == '+' || solution.at(i) == '-') {
            indices.push_back(i);
        }
    }

    return indices;
};
