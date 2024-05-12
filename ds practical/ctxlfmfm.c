#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left,*right;
};
struct node * createnode(int value)
{
struct node * newnode=(struct node *)malloc(sizeof(struct node));
 newnode->data=value;
 newnode->left=newnode->right=NULL;
 return newnode;
}
struct node * insertnode(struct node * root,int value)
{
    if(root==NULL)
    {
        return  createnode(value);
    }
    if(value <root->data)
    {
        root->left=insertnode(root->left,value);
    }
    if (value>=root->data)
    {
        root->right=insertnode(root->right,value);
    }
    return root;
}
int count(struct node * root)
{
    static int c=0;
    if(root!=NULL)
    {  c++;
     count(root->left);
     count(root->right);
    
     return c;
    }
}
int min(struct node * root)
{  struct node * temp=root;
    while((temp!=NULL) && (temp->left!=NULL))
    { 
    
        temp=temp->left;
    
       
    }
    return temp->data;
}
int max(struct node * root)
{  struct node * temp=root;
    while((temp!=NULL) && (temp->right!=NULL))
    {
        temp=temp->right;
       
    }
     return temp->data;
}
void inorder(struct node * root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
int countleaf(struct node * root)
{   static int d=0;
    struct node * temp=root;
     
    if(temp!=NULL)
    {  countleaf(root->left);
       if((temp->left==NULL) &&( temp->right==NULL))
       {
        d++;
       }
       countleaf(root->right);

    }
     return d;
}
int main ()
{
    struct node *root=NULL;
       root=insertnode(root,20);
       insertnode(root,20);
       insertnode(root,10);
       insertnode(root,40);
       insertnode(root,80);
       insertnode(root,10);
       insertnode(root,40);
       insertnode(root,30);
       inorder(root);
       int c=count(root);
       printf("\ntotal node %d\n",c);
       int b=countleaf(root);
       printf("leaf nodes %d\n",b);

       int d=min(root);
       printf("min elemet %d",d);

       int e=max(root);
       printf("\n max eleemtn %d",e);
       
}