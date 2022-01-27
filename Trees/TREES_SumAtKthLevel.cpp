#include <iostream>
#include <algorithm>
#include <queue>
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

int sumatk(node *root, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    queue<node *> q;
    q.push(root);
    int level = 0;
    int sum = 0;
    int flag = 0;

    while (!q.empty())
    {

        int size = q.size();

        while (size--)
        {
            node *n = q.front();
            q.pop();
            if (level == k)
            {
                flag = 1;
                sum += n->data;
            }
            else
            {
                if (n->left != NULL)
                    q.push(n->left);

                if (n->right != NULL)
                    q.push(n->right);
            }
        }
        level++;
        if (flag == 1)
            break;
    }
    return sum;
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

    cout << sumatk(p, 2);

    return 0;
}