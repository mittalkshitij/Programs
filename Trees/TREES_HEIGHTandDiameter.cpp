#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int data)
{
    struct node *n=new node;
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}

int height(node *root) 
{
    if(root==NULL)
    {
        return -1;
    }

    int lheight=height(root->left);
    int rheight=height(root->right);

    return max(lheight,rheight)+1;
}

int diameter(node *root)
{
   if(root==NULL)
   {
       return 0;
   }

   int lheight=height(root->left);
   int rheight=height(root->right);

   int ldiameter=diameter(root->left);
   int rdiameter=diameter(root->right);

   return max(lheight+rheight+1,max(ldiameter,rdiameter));

}

int main(){
    struct node *p = createnode(4);
    // struct node *p1 = createnode(1);
    // struct node *p2 = createnode(6);
    // struct node *p3 = createnode(5);
    // struct node *p4 = createnode(2);
    // struct node *p5 = createnode(8);
    // struct node *p6 = createnode(9);
    // struct node *p7 = createnode(10);
    // Finally The tree looks like this:
    //      4
    //     / \
    //    1   6
    //   / \
    //  5   2  
    // /     \
    //8       9
    //         \
    //          10

    // Linking the root node with left and right children
    // p->left = p1;
    // p->right = p2;
    // p1->left = p3;
    // p1->right = p4;
    // p3->left = p5;
    // p4->right = p6;
    // p6->right = p7;

   
   cout<<"Height of Binary Tree :"<<height(p)<<endl;
   cout<<"Diameter of Binary Tree :"<<diameter(p);
    

 
return 0;
}