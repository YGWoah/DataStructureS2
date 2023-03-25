#include <string>
#include <cmath>
#include "stack.h"
#include <iostream>
class Expression
{
public:
    std::string expression;
    std::string postfix;
    std::string prefix;
    std::string infix;
    std::string result;
    int length;

public:
    Expression(std::string expression);
    static float valueOperation(int operand_1, int operand_2, char operatore);
    float valueExpression();
    static int convertCharToInt(char c);
    // int convertStringToInt(std:: s);
};