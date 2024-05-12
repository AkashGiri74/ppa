#include<stdio.h>
#include<stdlib.h>
struct node 
{
  int data;
  struct node *left,*right;
};
struct node * createnode(int value)
{  struct node * newnode=(struct node *)malloc(sizeof(struct node));
   newnode->data=value;
   newnode->left=newnode->right=NULL;
   return newnode;
}
struct node * insertnode(struct node * root,int value)
{
  if(root==NULL)
  {
   return createnode(value);
  }
  else if (value <root->data)
  { root->left=insertnode(root->left,value);
  }
  else if (value >= root->data)
    {
  root->right=insertnode(root->right,value);
   }
  return root;
}
void pre(struct node * root)
{
   if(root!=NULL)
{
  printf("%d ",root->data);
  pre(root->left);
  pre(root->right);
}

}
void post(struct node * root)
{ 
    if (root!=NULL)
    {
        post(root->left);
        post(root->right);
        printf("%d ",root->data);
    }
}



void main ()
{ struct node * root=NULL;
  root=insertnode(root,45);
  insertnode(root,34);
  insertnode(root,21);
  insertnode(root,32);
  insertnode(root,78);
  insertnode(root,9);
   pre(root);
   printf("\n");
   post(root);

}