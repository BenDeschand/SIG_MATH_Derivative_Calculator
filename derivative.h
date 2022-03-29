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
    string derive(string equation);
    vector<char> parseString(string equation);  // return string equation as vector
    vector<int> findAddSub(string solution);  // return a vector of the +/- signs in the equation
    int getRule(string equation, string& c, string& u, string& v); // returns a number corresponding to the derivative rule to be executed using guide at https://www.cs.utexas.edu/users/novak/asg-symdif.html

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
