#include <iostream>
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

void inorder(struct node *root)
{

    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void insert(struct node *root, int value)
{
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (value == root->data)
        {
            cout << "Already in BST";
            return;
        }
        else if (value > root->data)
        {
            root = root->right;
        }
        else
        {
            root = root -> left;
        }
    }
        struct node *n = createnode(value);
        if (value < prev->data)
        {
            prev->left = n;
        }
        else
        {
            prev->right = n;
        }
}

    int main()
    {
        struct node *p = createnode(5);
        struct node *p1 = createnode(3);
        struct node *p2 = createnode(6);
        struct node *p3 = createnode(1);
        struct node *p4 = createnode(4);
        // Finally The tree looks like this:
        //      5
        //     / \
        //    3   6
        //   / \
        //  1   4

        // Linking the root node with left and right children
        p->left = p1;
        p->right = p2;
        p1->left = p3;
        p1->right = p4;
        inorder(p);
        cout << endl;
        int value;
        cout<<"Enter data to be inserted:";
        cin>>value;
        insert(p, value);
        cout<<endl;
        inorder(p);

        return 0;
    }