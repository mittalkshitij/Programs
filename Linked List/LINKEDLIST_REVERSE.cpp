#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;

struct node *reverse()
{
    struct node *curr = head, *prev = NULL, *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
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
    display();
    cout << "THE ELEMENTS AFTER REVERSING:" << endl;
    reverse();
    display();

    return 0;
}