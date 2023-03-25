#include <iostream>
#include "stack.h"
#include <string>

using namespace std;

int checkExpression(string str)
{
    stack tempstack(0);
    char start = '(';
    char end = ')';
    int length = str.length();
    for (int i = 0; i < length; i++)
    {
        if (str[i] == start)
        {
            tempstack.push(9); // instead of pushing ( i pushed 9 becuasue the stac only accepts integes and they are easy to deal with
        }
        else
        {
            if (str[i] == end)
            {
                int temp = tempstack.pop();
                if (temp != 9)
                {
                    cout << "the stack is not correct " << endl;

                    return 0;
                }
            }
        }
    }
    if (tempstack.isEmpty())
    {
        cout << "the stack is correct " << endl;
        return 1;
    }
    else
    {
        cout << "the stack is not correct " << endl;
        return 0;
    }
    return 0;
}

int main()
{
    string str;

    cout << "Enter the expression : ";
    getline(cin, str);
    cout << "The expression is : " << str << endl;

    checkExpression(str);
    cout << "hello world" << endl;
    return 0;
}