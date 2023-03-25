#include "Expression.h"
#include <iostream>
#include "stack.h"
// #include <string>

using namespace std;
Expression::Expression(std::string exp)
{
    this->exp = exp;
}

float Expression::evalOp(float a, float b, char op) const
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    default:
        return 0;
    }
}

std::string Expression::gettokenType(std::string op) const
{
    if (op == "+")
    {
        return "plus";
    }
    else if (op == "-")
    {
        return "minus";
    }
    else if (op == "*")
    {
        return "multiply";
    }
    else if (op == "/")
    {
        return "divide";
    }
    else if (op == "(")
    {
        return "left";
    }
    else if (op == ")")
    {
        return "right";
    }
    else
    {
        return "number";
    }
};

float Expression::eval()
{
    ArrayStack operand;
    ArrayStack operators;
    for (int i = 0; i < exp.length(); i++)
    {
        string token = std::string(1, exp[i]);
        string tokenType = gettokenType(token);
        cout << "operand" << endl;
        operand.print();
        cout << "operator" << endl;
        operators.print();
        // if (tokenType == " ")
        //     continue;            // i can define a function that cleans the string from spaces
        // else
        if (tokenType == "number")
        {
            operand.push(token);
        }
        else if (tokenType == "left")
        {
            operators.push(token);
        }
        else if (tokenType == "right")
        {
            while (operators.peek() != "(")
            {
                float a = std::stof(operand.pop());
                float b = std::stof(operand.pop());
                std::string op = operators.pop();
                operand.push(std::to_string(evalOp(a, b, op[0])));
            }
            operators.pop();
        }
        else if (tokenType == "plus" || tokenType == "minus" || tokenType == "multiply" || tokenType == "divide")
        {
            operators.push(token);
        }
    }
    if (!operators.isEmpty())
    {

        while (!operators.isEmpty())
        {
            cout << "is the problem here?" << endl;
            float a = std::stof(operand.pop());
            cout << "a " << a << endl;
            float b = std::stof(operand.pop());
            cout << "b" << b << endl;
            std::string op = operators.pop();
            operand.push(std::to_string(evalOp(a, b, op[0])));
        }
    }

    return std::stof(operand.pop());
}