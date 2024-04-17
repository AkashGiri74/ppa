#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node * left,*right;
    int data;
};
struct node * createnode(int data)
{
    struct node * new=(struct node *)malloc(sizeof(struct node));
    new->data=data;
    new->left=new->right=NULL;
    return new;
}
struct node * create_bst(struct node * root,int data)
{
    if(root==NULL)
    {
        return createnode(data);
        
    }
    if(data <root->data)
    {
        root->left=create_bst(root->left,data);
    }
    if(data >=root->data)
    {
      root->right=create_bst(root->right,data);  
    }
    return root;
}
void inorder(struct node* root)
{ 
     if(root!=NULL)
   { 
     inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);  
  }

}
void main ()
{
    struct node * root=NULL;
    int data;
    do
    {
        puts("enter data");
        scanf("%d",&data);
        if (data !=-1)
        {
           root= create_bst(root,data);
        }
    } while (data!=-1);

    printf("inorder traversal:");
    inorder(root);
    
}