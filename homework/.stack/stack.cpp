#include "stack.h"
#include <iostream>

using namespace std;

stack::stack(int k)
{
    top = NULL;
    size = 0;
}

void stack::push(int value)
{
    element *newElement = new element;
    newElement->value = value;
    newElement->next = top;
    top = newElement;
    size++;
}

int stack::pop()
{

    if (top == NULL || size == 0)
    {
        cout << "The stack is empty " << size << " ; \n";
        return -1;
    }
    else
    {
        try
        {
            element *temp = top;
            top = top->next;
            int value = temp->value;
            delete temp;
            size--;
            return value;
        }
        catch (const std::exception &e)
        {
            cout << "exception" << endl;
        }
    }
}
int stack::peek()
{
    if (top == NULL)
    {
        throw "Stack is empty";
        return -1;
    }
    else
    {
        return top->value;
    }
}

bool stack::isEmpty()
{
    return top == NULL;
}

void stack::print()
{
    if (size == 0)
    {
        cout << "the stack is empty" << endl;
        return;
    }
    element *temp = top;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}