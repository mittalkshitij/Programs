#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
struct node *f=NULL, *r=NULL;
int i;
void enqueue(int x)
{
    struct node *n=new node;
    if(n==NULL)
    {
        cout<<"Queue is full";
    }
    else{
        n->data=x;
        n->next=NULL;

        if(f==NULL)
        {
            f=r=n;
        }
        else{
            r->next=n;
            r=n;
        }
    }
}

int dequeue()
{
    struct node *ptr=f;

    if(f==NULL)
    {
        cout<<"Queue is empty";
        return 0;
    }
    else{
        f=f->next;
        int val=ptr->data;
        free(ptr);
        return val;
    }
    
}

void display()
{
    struct node *ptr=f;
    cout<<"ELEMENTS IN QUEUE ARE : \n";
    while (ptr != NULL)
    {
        cout<<ptr->data<<endl;
        ptr = ptr->next;
    }
}



int main() {

    enqueue(7);
    enqueue(4);
    enqueue(3);
    enqueue(8);
    display();
    int a=dequeue();
    cout<<"DEQUEUED ELEMENT :"<<a<<endl;
    display();
    
    

return 0;
}