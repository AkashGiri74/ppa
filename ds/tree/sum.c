//sum of all
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
    printf("enter data");
    scanf("%d",&data);
    if(data==-1)
    {
        return NULL;
    }
    root=createnode(data);
    printf("enter data for left of %d ",data);
    root->left=build_tree();
     printf("enter data for right of %d ",data);
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
int sum(struct node * root)
{
    int leftsum,rightsum;
    if(root==NULL)
    return 0;
    leftsum=sum(root->left);
    rightsum=sum(root->right);
    return root->data+leftsum+rightsum;

}
int main ()
{
    struct node * root=NULL;
    root=build_tree();
    inorder(root);

    printf("\nsum of all is %d ",sum(root));
} 