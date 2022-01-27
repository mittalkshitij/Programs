#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

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

void reversedll()
{
    node * temp= NULL;
    node * curr=head;

    while(curr!=NULL)
    {
        temp=curr->prev;
        curr->prev=curr->next;
        curr->next=temp;
        curr=curr->prev;
    }

    if(temp!=NULL)
    {
      head=temp->prev;
    }

}



void display()
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}
int main()
{
    InsertAtEnd(6);
    InsertAtEnd(5);
    InsertAtEnd(3);
    InsertAtEnd(4);
    cout<<"List Before Reversing :";
    display();
    cout<<" \nAfter Reversing :";
    reversedll();
    display();

    return 0;
}