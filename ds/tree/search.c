#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node * left;
    int data;
    struct node * right;
};
struct node * createnode(int value)
{
    struct node* newnode=NULL;
    newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        return NULL;
    }
    newnode->data=value;
    newnode->left=newnode->right=NULL;
    return newnode;
}
struct node * build_tree()
{   struct node * root=NULL;
    int data;
    printf("enter data :");
    scanf("%d",&data);
    if(data==-1)
    {
        return NULL;
    }
    root=createnode(data);
    printf("enter data for left child of %d : ",data);
    root->left=build_tree();
     printf("enter data for right of child %d : ",data);
     root->right=build_tree();
     return root;

}
void inorder (struct node * root)
{    if(root==NULL)
    {
    return ;
   }
   else  if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
struct node * search(struct node * root,int val)
{  if(root==NULL||root->data==val)
   {
   return root;
  }
  struct node * left=search(root->left,val);
    if(left !=NULL)
    {
        return left;
    }

    search(root->right,val);

}
int main ()
{
    struct node * root=NULL;
    root=build_tree();
    inorder(root);
    int val;
    printf("enter element to search:");
    scanf("%d",&val);
   struct node * r= search(root,val);
   if(r!=NULL)
   {
    printf("%d element is found ",val);
   }
   else
   {
    printf("%d element not found ",val);
   }
} 