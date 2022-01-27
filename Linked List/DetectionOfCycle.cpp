#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node *InsertAtBeginning(int x)
{
    struct node *newnode = new node;
    newnode->data = x;
    newnode->next = head;
    head = newnode;
    return head;
}

struct node *InsertAtEnd(int x)
{
    struct node *newnode = new node;

    if (head == NULL)
    {
        newnode->data = x;
        newnode->next = NULL;
        head = newnode;
        return head;
    }
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->data = x;
    newnode->next = NULL;
    return head;
}

void makecycle(node * head,int pos)
{
    node * temp=head;
    node *startnode;

    int count=1;
    while(temp->next!=NULL)
    {
        if(count==pos)
        {
            startnode= temp;

        }
        temp=temp->next;
        count++;
    }
    temp->next=startnode;
}

bool detectcycle(node * head)
{
    node * fast=head;
    node * slow=head;
    
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;

        if(fast==slow)
        {
            return 1;
        }
    }
    return 0;
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
    InsertAtEnd(2);
    InsertAtEnd(8);
    InsertAtEnd(0);
    InsertAtEnd(7);
    cout<<detectcycle(head)<<endl;
    makecycle(head,3);
    cout<<detectcycle(head)<<endl;

    //display();

    return 0;
}