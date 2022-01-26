#include<bits/stdc++.h>
using namespace std;

struct node {
  int data;
  struct node *left;
  struct node *right;
};

// New node creation
struct node *newNode(int data) {
  struct node *node = (struct node *)malloc(sizeof(struct node));

  node->data = data;

  node->left = NULL;
  node->right = NULL;
  return (node);
}

void preOrder(struct  node* root){
    if(root!=NULL){
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

bool searching(struct node * root, int key)
{
   
    if(root==NULL)
    {
        return NULL;
    }
    
    if(key==root->data)
    return 1;
    else if(key>root->data)
    searching(root->right,key);
    else
    searching(root->left,key);
   
}


int main() {
  struct node *root = newNode(4);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(1);

  cout<<searching(root,4);
    
    return 0;
}