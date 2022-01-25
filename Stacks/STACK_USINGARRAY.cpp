#include <iostream>
using namespace std;

int stack[100];
int top = -1;
int n = 100;

int isEmpty()
{
    if (top == -1)
        return 1;

    else
        return 0;
}

int isFull()
{
    if (top == n - 1)
        return 1;

    else
        return 0;
}

int push(int x)
{
    if (isFull())
        return 0;

    else
    {
        top++;
        stack[top] = x;
        return 1;
    }
}

int pop()
{
    if (isEmpty())
        return 0;

    else
    {
        top--;
        return 1;
    }
}

int peek(int i)
{
    if (top - i + 1 < 0)
    {
        cout << "Invalid";
    }
    else
    {

        return stack[top - i + 1];
    }
}

void display()
{
    cout << "Stack elements are:" << endl;
    for (int i = top; i >= 0; i--)
        cout << stack[i] << endl;
}

int main()
{
    push(7);
    push(8);
    display();
    pop();
    display();
    push(5);
    push(8);
    push(3);
    push(2);
    display();
    int i;
    cin >> i;
    cout << "Element at pos "<<i<<" is : "<<peek(i);

    return 0;
}