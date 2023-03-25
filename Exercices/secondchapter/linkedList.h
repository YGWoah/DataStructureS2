#include <iostream>

typedef int type;

using namespace std;

struct node
{
    type data;
    node *next;

    node(type value = 0, node *nextNode = nullptr)
    {
        this->data = value;
        this->next = nextNode;
    }
    void print();
};
