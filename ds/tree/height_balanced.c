//height balanced  
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
int is_height_balanced(struct node * root)
{
    int lh,rh,diff,currentans;
    if(root==NULL)
    return 1;
    lh=height(root->left);
    rh=height(root->right);
    diff=abs(lh-rh);
    currentans=diff<=1;
  int  left_ans=is_height_balanced(root->left);
int  right_ans=is_height_balanced(root->right);
if(currentans && left_ans && right_ans )
{
    return 1;
}
else
{
    return 0;
}
}
int main ()
{
    struct node * root=NULL;
    root=build_tree();
     printf("inorder traversal:");
    inorder(root);
     
     int h=height(root);
       printf("\n height is %d",h);
       if(is_height_balanced(root))
       {
        printf("\ntree is height balnced\n");
       }
       else
       {
        printf("tree is not height balancedd");
       }

} 