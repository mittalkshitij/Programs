#include<iostream>
#include<queue>
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

void rightview(node *root)
{
   if(root==NULL)
   {
       return ;
   }

   queue<node*>q;
   q.push(root);

   while(!q.empty())
   {
       int size=q.size();

       for(int i=0;i<size;i++)
       {
          struct node * curr=q.front();
          q.pop();
                                                           
          if(i==size-1)
          {
              cout<<curr->data<<" ";
          }

          if(curr->left!=NULL)
          {
              q.push(curr->left);
          }

          if(curr->right!=NULL)
          {
              q.push(curr->right);
          }

       }
   }

}

void leftview(node *root)
{
   if(root==NULL)
   {
       return ;
   }

   queue<node*>q;
   q.push(root);

   while(!q.empty())
   {
       int size=q.size();

       for(int i=0;i<size;i++)
       {
          struct node * curr=q.front();
          q.pop();

          if(i==0)
          {
              cout<<curr->data<<" ";
          }

          if(curr->left!=NULL)
          {
              q.push(curr->left);
          }

          if(curr->right!=NULL)
          {
              q.push(curr->right);
          }

       }
   }

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
    cout<<"Right View Of Binary tree :";
    rightview(p);
    cout<<endl;
    cout<<"Left View Of Binary tree :";
    leftview(p);
 
 
return 0;
}