class element
{
public:
    int value;
    element *next;
};
class stack
{
public:
    element *top;
    int size;
    stack(int);
    void push(int);
    int pop();
    int peek();
    bool isEmpty();
    void print();
};