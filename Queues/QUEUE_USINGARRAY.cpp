#include <iostream>
using namespace std;
int queue[100];
int f = -1;
int r = -1;
int n = 100;

int isEmpty()
{
    if (f == r)
    {
        return 1;
    }
    return 0;
}

int isFull()
{
    if (r == n - 1)
    {
        return 1;
    }
    return 0;
}

void enqueue(int x)
{
  if(isFull())
  {
    cout<<"QUEUE OVERFLOW";
  }
  else{
      f=0;
      r++;
      queue[r]=x;
  }
}

int dequeue()
{
  if(isEmpty())
  {
      cout<<"QUEUE UNDEFLOW";
      return -1;
  }
  else{
      int a=queue[f];
      f++;
      return a;
  }
}

void display()
{
  if(f==-1)
  {
      cout<<"Queue is empty";
  }
  else{
    for(int i=f;i<=r;i++)
    {
        cout<<queue[i]<<" "<<endl;
    }

  }


}
int main()
{
    enqueue(7);
    enqueue(4);
    enqueue(2);
    enqueue(9);
    display();
    cout<<"The popped element is:" <<dequeue()<<endl;
    display();


    return 0;
}