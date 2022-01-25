#include <iostream>
using namespace std;

char stack[100];
int top = -1;
int n = 100;
int i;

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

void push(char x)
{
    if (isFull())
        cout<<"Stack Overflow";

    else
    {
        top++;
        stack[top] = x;
    }
}

char pop()
{
    if (isEmpty())
        return 0;

    else
    {
        char val = stack[top];
        top--;
        return val;
    }
}

int match(char a, char b)
{
    if (a == '{' && b == '}')
    {
        return 1;
    }
    if (a == '(' && b == ')')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }
    return 0;
}

int parenthesisMatch(string s)
{   
    char ele;
    for (i = 0; s[i]!='\0'; i++)
    {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(')
            push(s[i]);

        else if (s[i] == '}' || s[i] == ']' || s[i] == ')')
        {
            if (isEmpty())
            {
               cout << "Stack underflow \n";
               return 0;
            }
            else
            {
                ele = pop();
                if (!match(ele, s[i]))
                {
                    return 0;
                }
            }
        }
    }
    if(isEmpty()){
        return 1;
    }
    else{
        return 0;
    }
}

int main()
{

    string s = "[4-6]}((8){(9-8)})";

    if (parenthesisMatch(s))
    {
        cout << "The parenthesis is balanced";
    }
    else
    {
        cout << "The parenthesis is not balanced";
    }

        return 0;
}