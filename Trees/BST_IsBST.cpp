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

bool isBST(node * root,node * min,node *max)
{
  if(root==NULL)
  {
      return true;
  }
  if(min!=NULL && root->data <= min->data)
  {
    return false;
  }
  if(max!=NULL && root->data >=max->data)
  {
      return false;
  }

  bool lvalid=isBST(root->left,min,root);
  bool rvalid=isBST(root->right,root,max);

  return lvalid && rvalid;
}

int main()
    {
        struct node *p = createnode(5);
        struct node *p1 = createnode(3);
        struct node *p2 = createnode(6);
        struct node *p3 = createnode(8);
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

        cout<<isBST(p,NULL,NULL);

        return 0;
    }