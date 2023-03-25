#include "Expression.h"
#include <iostream>

using namespace std;
int main()
{
    string s = "(9+3)*4";
    Expression e(s);
    float result = e.valueExpression();
    cout << result << endl;
    cout << "Hello World!" << endl;
    return 0;
}