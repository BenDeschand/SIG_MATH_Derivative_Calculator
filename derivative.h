#include <string>
#include <vector>
#include <iostream>

using namespace std;

class derivCal {
 private:
    string equation;   // input of equation
    string var;          // variable that we are solving for
    int equalsIndex;   // index of equals sign

    // helper methods
    string derive(string equation);  // recursive method to find derivative of the equation
    int getRule(string equation, string& c, string& u, string& v); // choose derivative rule to be used
    vector<int> findAddSub(string solution);  // find indices of the +/- signs in the equation

 public:
    // constructors
    derivCal();
    derivCal(string equation, string var);

    // recursively find the derivative of the equation
    string solve();

    // getters and setters for private variables
    string getEquation() {return equation;}
    void setEquation(string equation) {this->equation = equation;}

    string getVar() {return var;}
    void setVar(string var) {this->var = var;}

    int getEqualsIndex() {return equalsIndex;}
    void setEqualsIndex(int equalsIndex) {this->equalsIndex = equalsIndex;}
};
