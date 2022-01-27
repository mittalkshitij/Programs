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

bool isidentical(node * root1,node * root2)
{
  if(root1==NULL && root2==NULL)
  {
      return true;
  }
  else if(root1==NULL || root2==NULL)
  {
    return false;
  }
  else
  {
      bool cond1=root1->data==root2->data;
      bool cond2=isidentical(root1->left,root2->left);
      bool cond3=isidentical(root1->right,root2->right);

      if(cond1 && cond2 && cond3)
      {
          return true;
      }
      return false;
  }
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

        struct node *r = createnode(5);
        struct node *r1 = createnode(3);
        struct node *r2 = createnode(6);
        struct node *r3 = createnode(8);
        struct node *r4 = createnode(2);
        // Finally The tree looks like this:
        //      5
        //     / \
        //    3   6
        //   / \
        //  1   4

          // Linking the root node with left and right children
        r->left = r1;
        r->right = r2;
        r1->left = r3;
        r1->right = r4;

        cout<<isidentical(p,r);

        return 0;
    }