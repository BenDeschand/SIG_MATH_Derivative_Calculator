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
        string getString();                   // accessor for string variable (for testing purposes)
        string getEquation();
        vector<char> getVector();             // accessor for vector variable (for testing purposes)
        vector<char> parseString(string equation);
        char getVar();                        // accessor for var variable (for testing purposes)
        vector<int> findMult(string s) ;       // find a mult (epic style)
        int getVarIndex();
        vector<int> findAddSub(string solution);
        int getRule(string equation);
        bool isPowerRule(string s);  //checks for powerrule
        bool isSin(string s);         //checks for sin
        bool isCos(string s);        //checks for sin
        bool isTan(string s);       //checks for sin
};
