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

node* inordersucc(struct node *root)
{
   struct node * curr=root;
   while(curr->left!=NULL)
   {
       curr=curr->left;
   }
   return curr;
}

node* deletion(struct node *root, int key)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data > key)
    {
        root->left=deletion(root->left,key);
    }
    else if(root->data < key)
    {
        root->right=deletion(root->right,key);
    }
    else{
      if(root->left==NULL)
      {
          struct node * temp=root->right;
          free(root);
          return temp;
      }

      else if(root->right==NULL)
      {
          struct node * temp=root->left;
          free(root);
          return temp;
      }
       struct node * temp=inordersucc(root->right);
       root->data =temp->data;
       root->right=deletion(root->right,temp->data);
    }
    return root;
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
    
    cout<<"Before Deltion :";
    inorder(p);
    cout<<endl;
    cout<<"After Deletion :";
    deletion(p,1);
    inorder(p);

    

    return 0;
}