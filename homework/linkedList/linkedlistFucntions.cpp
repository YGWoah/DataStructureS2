#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};

node *addElement_begining(node *, int);
node *addElement_middle(node *, int, int);
node *addElement_end(node *, int);
node *deleteElement(node *, int, int);
int findElement(node *, int);
void printList(node *);
int main()
{

    node *HEAD = NULL;
    HEAD = addElement_end(HEAD, 1);
    HEAD = addElement_end(HEAD, 2);

    HEAD = addElement_begining(HEAD, 0);
    HEAD = addElement_middle(HEAD, 3, 3);
    HEAD = addElement_middle(HEAD, 4, 4);
    HEAD = addElement_middle(HEAD, 5, 5);
    HEAD = addElement_middle(HEAD, 6, 6);
    printList(HEAD);
    HEAD = deleteElement(HEAD, 0, 0);
    HEAD = deleteElement(HEAD, 1, 1);

    printList(HEAD);
    return 0;
}

node *addElement_end(node *HEAD, int number)
{
    node *temp = new node;
    temp->data = number;
    temp->next = NULL;
    if (HEAD == NULL)
    {
        return temp;
    }

    node *itereator_temp = HEAD;
    while (itereator_temp->next != NULL)
    {
        itereator_temp = itereator_temp->next;
    }
    itereator_temp->next = temp;
    return HEAD;
};

node *addElement_begining(node *HEAD, int number)
{
    node *temp = new node;
    temp->data = number;
    temp->next = HEAD;
    return temp;
};

node *addElement_middle(node *HEAD, int number, int position)
{
    node *temp = new node;
    temp->data = number;
    temp->next = NULL;
    if (HEAD == NULL)
    {
        return temp;
    }
    if (position == 0)
    {
        temp->next = HEAD;
        return temp;
    }
    node *iterator_temp = HEAD;
    for (int i = 0; i < position - 1; i++)
    {
        iterator_temp = iterator_temp->next;
    }
    temp->next = iterator_temp->next;
    iterator_temp->next = temp;
    return HEAD;
};

node *deleteElement(node *HEAD, int position, int number)
{
    if (HEAD == NULL)
    {
        return HEAD;
    }
    if (position == 0)
    {
        node *temp = HEAD;
        HEAD = HEAD->next;
        delete temp;
        return HEAD;
    }
    node *iterator_temp = HEAD;
    for (int i = 0; i < position - 1; i++)
    {
        iterator_temp = iterator_temp->next;
    }
    node *temp = iterator_temp->next;
    iterator_temp->next = iterator_temp->next->next;
    delete temp;
    return HEAD;
};

int findElement(node *HEAD, int number)
{
    int position = 0;
    node *iterator_temp = HEAD;
    while (iterator_temp != NULL)
    {
        if (iterator_temp->data == number)
        {
            return position;
        }
        iterator_temp = iterator_temp->next;
        position++;
    }
    return -1;
};

void printList(node *HEAD)
{
    node *iterator_temp = HEAD;
    while (iterator_temp != NULL)
    {
        cout << iterator_temp->data << " ";
        iterator_temp = iterator_temp->next;
    }
    cout << endl;
};