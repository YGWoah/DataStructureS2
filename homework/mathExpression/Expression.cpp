#include "Expression.h"

// static float valueOperation(int operand_1, int operand_2, char operatore);
// float valueExpression();
// int convertCharToInt(char c);
// int convertStringToInt(string s);

using namespace std;

Expression::Expression(string expression)
{
    this->expression = expression;
    this->length = expression.length();
    this->valueExpression();
}

float Expression::valueOperation(int operand_1, int operand_2, char operatore)
{
    float result;
    switch (operatore)
    {
    case '+':
        result = operand_1 + operand_2;
        break;
    case '-':
        result = operand_1 - operand_2;
        break;
    case '*':
        result = operand_1 * operand_2;
        break;
    case '/':
        result = operand_1 / operand_2;
        break;
    default:
        break;
    }
    return result;
}
int Expression::convertCharToInt(char c)
{
    int result = c - '0';
    return result;
}

float Expression::valueExpression()
{
    stack operation(0);
    stack shish(0);
    int i = 0;
    for (i = 0; i < expression.length(); i++)
    {

        cout << "\noperand: " << endl;
        operand.print();

        cout << "\noperator: " << endl;
        operation.print();

        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '(')
        {
            cout << "pushing  operator: " << expression[i] << endl;
            operation.push(expression[i]);
            cout << "pushing  operand: "
                 << "'_'" << endl;
            shish.push('_');
            cout << "test " << endl;
        }
        else
        {
            cout << "\n this is operand: " << expression[i] << endl;
        }
        // else if (expression[i] == ' ')
        // {
        //     continue;
        // }
        // // else if (expression[i] == ')')
        // // {
        // //     char temp;
        // //     int operand_2, operand_1;
        // //     int i = 0;
        // //     while (temp != ',')
        // //     {
        // //         operand_1 = convertCharToInt(operand.pop()) * pow(10, i) + operand_1;
        // //     }
        // //     i = 0;
        // //     while (temp != ',')
        // //     {
        // //         operand_2 = convertCharToInt(operand.pop()) * pow(10, i) + operand_2;
        // //     }
        // // }
        // else
        // {
        //     cout << "push operand: " << expression[i] << endl;
        //     operand.push(expression[i]);
        // }
    }
    float result = 0;
    // operand.print();
    return result;
}
