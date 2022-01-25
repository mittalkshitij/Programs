#include <iostream>
using namespace std;
int cicularq[100];
int f = 0;
int r = 0;
int n = 5;

int isEmpty()
{
    if (f == r)
        return 1;

    return 0;
}

int isFull()
{
    if ((r + 1) % n == f)
        return 1;

    return 0;
}

void enqueue(int x)
{
    if (isFull())
    {
        cout << "QUEUE FULL";
    }
    else
    {
        cicularq[r] = x;
       
        cout << "Enqueued element at "<<r<<" positon is: " << x << endl;
         r = (r + 1) % n;
         cout<<r;
    }
}

void dequeue()
{
    if (isEmpty())
    {
        cout << "Queue Underflow";
    }
    else
    {   
        int a = cicularq[f];
        f = (f + 1) % n;
        

        cout << "\nThe popped element is:" << a << endl;
    }
}

int main()
{
    enqueue(7);
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);
   

    return 0;
}