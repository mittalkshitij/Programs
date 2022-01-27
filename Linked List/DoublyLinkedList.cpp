#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

struct node *InsertAtBeginning(int x)
{
    struct node *newnode = new node;
    newnode->data = x;
    if (head == NULL)
    {
        newnode->next = NULL;
        newnode->prev = NULL;
        head = newnode;
        return head;
    }
    else
    {
        newnode->next = head;
        newnode->prev=NULL;
        head->prev = newnode;
        head = newnode;
        return head;
    }
}

struct node *InsertAtEnd(int x)
{
    struct node *newnode = new node;
    newnode->data = x;

    if (head == NULL)
    {
        newnode->next = NULL;
        newnode->prev=NULL;
        head = newnode;
        return head;
    }

    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev=temp;
    newnode->next = NULL;
    return head;
}

struct node *InsertatPos(int x, int pos)
{
    struct node *newnode = new node, *p = head;
    int i = 0;

    while (i != pos - 1)
    {
        p = p->next;
        i++;
    }
    newnode->data = x;
    newnode->next = p->next;
    newnode->prev=p;
    p->next = newnode;
    p->next->prev=newnode;
    return head;
}

void display()
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        cout << "Element:" << ptr->data << endl;
        ptr = ptr->next;
    }
}
int main()
{
    InsertAtEnd(6);
    InsertAtEnd(5);
    InsertAtEnd(3);
    InsertAtBeginning(2);
    InsertatPos(8, 2);
    display();

    return 0;
}