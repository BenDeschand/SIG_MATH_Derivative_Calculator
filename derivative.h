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

    public:
        derivCal();                           // default constructor
        derivCal(string equation, char var);  // overloaded constructor
        string solve();
        string getString();                   // accessor for string variable (for testing purposes)
        vector<char> getVector();             // accessor for vector variable (for testing purposes)
        char getVar();                        // accessor for var variable (for testing purposes)
        int getVarIndex();
        vector<char> parseString(string equation);
        string powerRule(char var, int constant, int exponent);
};
