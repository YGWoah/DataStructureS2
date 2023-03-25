#include <iostream>
#include "stack.h"
#include <string>

#define PLUS 1
#define MINUS 2
#define MULTIPLY 3
#define DIVIDE 4
#define LEFT_BRACKET 5
#define RIGHT_BRACKET 6

int valueExpression(std::string expression)
{
    stack operand(0);
    stack operation(0);

    int taille = expression.length();
    int i = 0;
    char left_bracket = '(', right_bracket = ')', plus = '+', minus = '-', multiply = '*', divide = '/';
    int result = 0;
    for (i = 0; i < taille; i++)
    {
        if (expression == left_bracket)
        {
            operation.push(LEFT_BRACKET);
        }
        else if (expression == right_bracket)
        {
            operation.push(RIGHT_BRACKET);
        }
        else if (expression == plus)
        {
            operation.push(PLUS);
        }
        else if (expression == minus)
        {
            operation.push(MINUS);
        }
        else if (expression == multiply)
        {
            operation.push(MULTIPLY);
        }
        else if (expression == divide)
        {
            operation.push(DIVIDE);
        }
        else
        {
            operand.push(expression[i]);
        }
    }
};

int main()
{

    return 0;
}