#include <string>
#include <vector>
#include <iostream>

using namespace std;

class derivCal
{
    private:
        string equation;   // input of equation
        vector<char> eq;   // vector of equation for easier traversal
        char var;          // variable that we are solving for
        int equalsIndex;   // index of equals sign

        void setEqualsIndex(); // finds equals sign and sets equalsIndex

    public:
        derivCal();                           // default constructor
        derivCal(string equation, char var);  // overloaded constructor
        string solve(string sub_solution);
        string getEquation();                 // accessor for equation variable
        vector<char> getVector();             // accessor for vector variable (for testing purposes)
        vector<char> parseString(string equation);  // return string equation as vector
        char getVar();                        // accessor for var variable (for testing purposes)
        bool findMult(string s) ;      // find a mult (epic style)
        int getVarIndex();                    // find the index of the variable in the equation vector
        vector<int> findAddSub(string solution);  // return a vector of the +/- signs in the equation
        int getRule(string equation, string c, string u, string v);         // returns a number corresponding to the derivative rule to be executed
                                              //   using guide at https://www.cs.utexas.edu/users/novak/asg-symdif.html
        bool isPowerRule(string s);           // checks for powerrule
        bool isSin(string s);                 // checks for sin
        bool isCos(string s);                 // checks for cos
        bool isTan(string s);                 // checks for tan
};
