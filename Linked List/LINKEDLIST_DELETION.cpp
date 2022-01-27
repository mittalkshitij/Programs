#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node *DeletionatBeginning()
{
 struct node *ptr=head;
 head=head->next;
 free(ptr);
 return head;
}

struct node *DeletionatLast()
{
    struct node *p=head;
    struct node *q=head->next;
    while(q->next!=NULL)
    {
        p=p->next;          //
        q=q->next;
    }             
    p->next=NULL;
    free(q);
    return head;
}

struct node *DeletionatPos(int pos)
{
    struct node *p=head;
    struct node *q=head->next;
    for(int i=0;i<pos-1;i++)
    {
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;
}
void display()
{   
   struct node * ptr=head;
    while (ptr != NULL)
    {
        cout<<"Element:"<< ptr->data<<endl;
        ptr = ptr->next;
    }

}
int main() {
    struct node *second;
    struct node *third;
    struct node *fourth;

    head = new node;
    second = new node;
    third = new node;
    fourth = new node;

    head->data = 4;
    head->next = second;

    second->data = 3;
    second->next = third;

    third->data = 8;
    third->next = fourth;

    fourth->data = 1;
    fourth->next = NULL;
    //display();
    DeletionatBeginning();
    //display();
     DeletionatPos(2);
    //display();
     DeletionatLast();
     display();

return 0;
}