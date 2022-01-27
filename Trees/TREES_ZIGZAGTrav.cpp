#include <iostream>
#include <stack>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int data)
{
    struct node *n = new node;
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void zigzag(node *root)
{
    if (root == NULL)
    {
        return;
    }

    stack<node *> currlev, nextlev;
    bool lefttoright = true;

    currlev.push(root);

    while (!currlev.empty())
    {
        node *temp = currlev.top();
        currlev.pop();

        if (temp)
        {
            cout << temp->data << " ";

            if (lefttoright)
            {
                if (temp->left)
                {
                    nextlev.push(temp->left);
                }

                if (temp->right) 
                {
                    nextlev.push(temp->right);
                }
            }
            else
            {
                if (temp->right)
                {
                    nextlev.push(temp->right);
                }
                if (temp->left)
                {
                    nextlev.push(temp->left);
                }
            }
        }
        if (currlev.empty())
        {
            lefttoright = !lefttoright;
            swap(currlev, nextlev);
        }
    }
}

int main()
{

    struct node *p = createnode(4);
    struct node *p1 = createnode(1);
    struct node *p2 = createnode(6);
    struct node *p3 = createnode(5);
    struct node *p4 = createnode(2);
    // Finally The tree looks like this:
    //      4
    //     / \
    //    1   6
    //   / \
    //  5   2

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    zigzag(p);

    return 0;
}