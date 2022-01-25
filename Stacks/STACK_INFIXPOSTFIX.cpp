#include <iostream>
#include <string>
#include <cstring>
using namespace std;

char stack[100];
int top = -1;
int n = 100;
int i, j;

int isEmpty()
{
    if (top == -1)
        return 1;

    return 0;
}

int isFull()
{
    if (top == n - 1)
    {
        return 1;
    }
    else
        return 0;
}

void push(char c)
{
    if (isFull())
    {
        cout << "STACK OVERFLOW \n";
    }
    else
    {
        top++;
        stack[top] = c;
    }
}

char pop()
{
    if (isEmpty())
    {
        return -1;
    }
    else
    {
        char ch = stack[top];
        top--;
        return ch;
    }
}
int precendence(char x)
{
    if (x == '*' || x == '/')
        return 3;
    else if (x == '+' || x == '-')
        return 2;
    else
        return 0;
}

int isoperator(char l)
{
    if (l == '+' || l == '-' || l == '*' || l== '/')
        return 1;
    else
    return 0;
}

int stacktop()
{
    return stack[top];
}

char *infixtopostfix(char *infix)
{
     char * postfix = (char *) malloc((strlen(infix)+1) * sizeof(char));

    int i = 0, j = 0;

   while(infix[i]!='\0')
    {

        if (!isoperator(infix[i]))
        {
            postfix[j]=infix[i];
            j++;
            i++;
        }
        else
        {
            if (precendence(infix[i]) > precendence(stacktop()))
            {
                push(infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop();
                j++;
            }
        }
    }

    while (!isEmpty())
    {
        postfix[j] = pop();
        j++;
    }
    postfix[j] = '\0';

    return postfix;
}

int main()
{

    char * infix = "a+b";
   cout<< infixtopostfix(infix);

    return 0;
}