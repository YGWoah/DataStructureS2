#include "stack.h"
#include "Expression.h"
#include <iostream>

// i want to add parenthesis to the expression if nedded
std::string simplifyExp(std::string exp)
{
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '*')
        {
            if (exp[i - 1].isDigit() && exp[i + 1].isDigit())
            {
                exp.insert(i - 1, "(");
                exp.insert(i + 3, ")");
            }
        }
    }
}

int main()
{
    // test Expression
    std::cout << "test Expression" << std::endl;
    Expression exp("2+3*4");
    std::string result = simplifyExp("2+3*4"));
    std::cout << result << std::endl;
    // float result = exp.eval();
    // std::cout << "the result is " << result << std::endl;

    return 0;
}