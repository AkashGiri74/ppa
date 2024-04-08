//height 
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
int max(int a,int b)
{
   return a>b?a:b;
} 
int height(struct node * root)
{
    int lh,rh;
    if(root==NULL)
         return 0;
    lh=height(root->left);
    rh=height(root->right);
    return max(lh,rh)+1;     
}
int diameter(struct node * root)
{
    int op1,op2,op3;
    if(root==NULL)
    return 0;

    op1=diameter(root->left);
    op2=diameter(root->right);
    op3=height(root->left)+height(root->right);
    return max(op1,max(op2,op3));
}
int main ()
{
    struct node * root=NULL;
    root=build_tree();
     printf("inorder traversal:");
    inorder(root);
     
     int h=height(root);
       printf("\n height is %d",h);
     int d=diameter(root);
     printf("\n dimeter of tree %d",d);  

} 