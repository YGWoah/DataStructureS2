#include "stack.h"
#include <iostream>

using namespace std;

element::element(elementType k)
{
    value = k;
    next = nullptr;
};

stack::stack(elementType k)
{
    size = 0;
};

void stack::push(elementType value)
{
    element newElement(value);
    newElement.next = top;
    top = newElement;
    size++;
}
elementType stack::pop()
{
    if (top == nullptr || size == 0)
    {
        cout << "The stack is empty " << size << " ; \n";
        return -1;
    }
    else
    {
        try
        {
            element temp = top;
            top = top.next;
            elementType value = temp.value;
            delete temp;
            size--;
            return value;
        }
        catch (const std::exception &e)
        {
            cout << "exception" << endl;
        }
    }
    return 0;
};
elementType stack ::peek()
{
    if (top == nullptr)
    {
        throw "Stack is empty";
        return -1;
    }
    else
    {
        return top.value;
    }
};
bool stack::isEmpty()
{
    return (size == 0) || (top == nullptr);
};
void stack::print()
{
    if (top == nullptr or size == 0)
    {
        cout << "The stack is empty  ; \n";
    }
    else
    {
        element temp = top;
        while (&temp != nullptr)
        {
            cout << temp.value << " ";
            temp = temp.next;
        }
        cout << " ;" << endl;
    }
};