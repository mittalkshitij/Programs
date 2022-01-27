#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

int search(int inorder[],int start,int end,int val)
{
    for(int i=start;i<=end;i++)
    {
        if(inorder[i]==val)
        {
            return i;
        }

    }
   return -1;
}


struct node * buildtree(int preorder[],int inorder[],int start,int end)
{
   static int i=0;

   if(start>end)
   {
       return NULL;
   }

   int val=preorder[i];
   i++;
   struct node *curr=new node;
   curr->data=val;
   curr->left=NULL;
   curr->right=NULL;
   if(start==end)
   {
       return curr;
   }
   
   int pos=search(inorder,start,end,val);
   curr->left=buildtree(preorder,inorder,start,pos-1);
   curr->right=buildtree(preorder,inorder,pos+1,end);

   return curr;


}

void inorderprint(struct node *root)
{

    if (root != NULL)
    {
        inorderprint(root->left);
        cout << root->data << " ";
        inorderprint(root->right);
    }
}

int main()
{
    int preorder[]={1,2,4,3,5};
    int inorder[]={4,2,1,5,3}; 

    struct node * root=buildtree(preorder,inorder,0,4);
    inorderprint(root);


    return 0;
}