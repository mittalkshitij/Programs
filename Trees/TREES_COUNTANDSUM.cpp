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

int countnodes(node *root)
{   
    if(root==NULL)
    {
        return 0;
    }
    return countnodes(root->left) + countnodes(root->right) + 1;
}

int sumofnodes(node *root)
{
    if(root==NULL){
        return 0;
    }
    return sumofnodes(root->left) +sumofnodes(root->right) + root->data;
}

int main(){
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

    cout<<"Count of Nodes :"<<countnodes(p)<<endl;
    cout<<"Sum of Nodes :"<<sumofnodes(p);
    

 
return 0;
}