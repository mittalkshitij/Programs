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

node *sortedarr(int arr[], int start, int end)
{
    if(start>end)
    {
       return NULL;
    }
    int mid = (start + end)/2;
    node * root= new node;
    root->data=arr[mid];
    root->left=NULL;
    root->right=NULL;

    root->left=sortedarr(arr,start,mid-1);
    root->right=sortedarr(arr,mid+1,end);

    return root;
}


void preorder(struct node *root)
{

    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    int arr[]={2,3,6,7,9,11}; 
    node * root= sortedarr(arr,0,5);

    preorder(root);
    
    return 0;
}