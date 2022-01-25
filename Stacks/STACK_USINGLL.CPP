#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

int isFull()
{

    struct node *p = new node;

    if (p == NULL)
    {
        return 1;
    }
    return 0;
}

int isEmpty()
{

    if (top == NULL)
    {
        return 1;
    }
    return 0;
}

void push(int x)
{
    if (isFull())
    {
        cout << "Stack Overflow";
    }
    else
    {
        struct node *newnode = new node;
        newnode->data = x;
        newnode->next = top;
        top = newnode;
    }
}

void pop()
{
    if (isEmpty())
    {
        cout << "Stack underflow";
    }
    else
    {
        struct node *n = top;
        top = top->next;
        cout << "The popped element is:" << n->data << endl;
        free(n);
    }
}

int peek(int i)
{
    struct node *p = top;

    for (int j = 0; j< i - 1 && p != NULL; j++)
    {
        p = p->next;
    }
    if (p != NULL)
    {
        return p->data;
    }
    else
    return -1;
}

void display()
{
    struct node *ptr;
    if (top == NULL)
        cout << "Stack is empty";
    else
    {
        ptr = top;
        cout << "Stack elements are:\n";
        while (ptr != NULL)
        {
            cout << ptr->data << endl;
            ptr = ptr->next;
        }
    }
}

int main()
{

    push(7);
    push(5);
    push(3);
    display();
    pop();
    push(8);
    push(6);
    display();
    int i;
    cin >> i;
    cout << "Element at position " << i << " is :" << peek(i);

    return 0;
}