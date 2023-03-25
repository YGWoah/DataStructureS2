#include "linkedList.h"
// it's recomended to use a generic type for the linked list
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

void node::print()
{
    cout << data << endl;
}

struct linkedList
{
    node *head, *tail, *cursor;
    int size;

    void create(type value = 0);  // constructor
    bool isEmpty() const;         // getter
    void addFirst(type newValue); // setter
    void addLast(type newValue);  // setter
    void add(type newValue);      // setter it addes where the cursor is
    void removeFirst();           // setter
    void removeLast();            // setter
    void remove();                // setter
    void clear();                 // setter
    void peek() const;            // getter
    node *find(type value);       // setter beacuse it changes the value of cursor
    void affiche() const;         // getter
};

void linkedList::create(type value)
{
    head = tail = cursor = new node;
    head->data = value;
    head->next = nullptr;
    size++;
}

bool linkedList::isEmpty() const
{
    return head == nullptr;
}

void linkedList::addFirst(type newValue)
{
    if (isEmpty())
    {
        create(newValue);
        return;
    }
    node *temp = new node;
    temp->data = newValue;
    temp->next = head;
    head = temp;
    size++;
}

void linkedList::addLast(type newValue)
{
    cursor = new node(newValue);
    tail->next = cursor;
    tail = cursor;
    size++;
}

void linkedList::add(type newValue)
{
    if (isEmpty())
    {
        create(newValue);
    }
    else
    {
        cursor->next = new node(newValue, cursor->next);
        size++;
    }
}

void linkedList::removeFirst()
{
    if (isEmpty())
    {
        cout << "The list is empty" << endl;
    }
    else
    {
        cursor = head;
        head = head->next;
        delete cursor;
        size--;
    }
}

void linkedList::removeLast()
{
    if (isEmpty())
    {
        cout << "The list is empty" << endl;
    }
    else
    {
        cursor = head;
        while (cursor->next != tail)
        {
            cursor = cursor->next;
        }
        delete tail;
        tail = cursor;
        tail->next = nullptr;
        size--;
    }
}

void linkedList::remove()
{
    if (isEmpty())
    {
        cout << "The list is empty" << endl;
    }
    else
    {
        if (cursor)
        {
            node *temp;
            temp = head;
            while (temp->next != cursor)
                temp = temp->next;
            temp->next = cursor->next;
            delete cursor;
            cursor = temp;
        }
    }
}

void linkedList::affiche() const
{
    if (isEmpty())
    {
        cout << "the list is empty" << endl;
        return;
    }
    node *temp = head;
    while (temp != nullptr)
    {
        temp->print();
        temp = temp->next;
    }
}

void linkedList ::clear()
{
    while (head)
    {
        this->removeFirst();
    }
}

// im not sure about his function
void linkedList::peek() const
{
    if (isEmpty())
    {
        cout << "The list is empty" << endl;
    }
    else
    {
        cout << "The first element is " << head->data << endl;
    }
}

node *linkedList::find(type value)
{
    cursor = head;
    while (cursor)
    {
        if (cursor->data == value)
        {
            return cursor;
        }
        cursor = cursor->next;
    }
}

// mian function
int main()
{
    cout << "Hello World" << endl;
    linkedList list;
    list.addFirst(1);
    list.addFirst(2);
    list.addFirst(3);
    list.addFirst(4);
    list.removeFirst();

    list.addLast(55);
    list.removeLast();
    list.affiche();
    list.clear();
    list.affiche();

    return 0;
}