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