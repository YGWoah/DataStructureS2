#include <iostream>

using namespace std;

typedef string dataType;

class stack
{
private:
    int capacity;
    int top;
    dataType *values;

public:
    stack(int size = 10);
    ~stack();
    void push(dataType value);
    dataType pop();
    dataType peek() const;
    bool isEmpty() const;
    bool isFull() const;
    void affiche() const;
};

stack::stack(int size)
{
    capacity = size;
    top = -1;
    values = new dataType[capacity];
}

void stack::push(dataType value)
{
    if (isFull())
    {
        cout << "Stack is full" << endl;
        return;
    }
    values[++top] = value;
}

dataType stack::pop()
{
    if (isEmpty())
    {
        cout << "Stack is empty" << endl;
        return 0;
    }
    return values[top--];
}

dataType stack::peek() const
{
    if (isEmpty())
    {
        cout << "Stack is empty" << endl;
        return 0;
    }
    return values[top];
}