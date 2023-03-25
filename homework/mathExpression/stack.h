
typedef char elementType;

class element
{
public:
    element(elementType k);
    elementType value;
    element next;
};
class stack
{
public:
    element top;
    int size;
    stack(elementType);
    void push(elementType);
    elementType pop();
    elementType peek();
    bool isEmpty();
    void print();
};