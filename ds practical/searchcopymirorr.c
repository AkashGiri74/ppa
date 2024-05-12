#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * left ,*right;
};
struct node * createnode(int value)
{
    struct node * newnode=(struct node *)malloc(sizeof(struct node));
      newnode->data=value;
      newnode->left=newnode->right=NULL;
      return newnode;
}
struct node * insertnode(struct node *root,int value)
{
    if(root==NULL)
    {
        return createnode(value);
    }
    if (value<root->data)
    {
        root->left=insertnode(root->left,value);
    }
    else if (value>=root->data)
    {
        root->right=insertnode(root->right,value);
    }
    return root;
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
struct node * treecopy(struct node * root)
{  if (root !=NULL)
     {
        struct node * temp=(struct node *)malloc(sizeof(struct node));
       temp->data=root->data;
       temp->left=treecopy(root->left);
       temp->right= treecopy( root->right);
       return temp;
     }
     inorder(root);

}

struct node * search(struct node * root,int key)
{  if(root->data==key)
  {
    return root;
  }
  else if (key <root->data )
  {
    return search(root->left,key);
  }
  else if(key >root->data)
 {
    return search(root->right,key);
 }
}
void pre(struct node * root)
{  if(root!=NULL)
{
    printf("%d ",root->data);
    pre(root->left);
    pre(root->right);
}
}
void mirror(struct node * root)
{
    if(root!=NULL)
    {
        if(root->left!=NULL)
          mirror(root->left);
        if(root->right!=NULL)
           mirror(root->right);
        struct node * temp1=root->left;
        root->left=root->right;
        root->right=temp1;     
    }
}

int main ()
{
    struct node* root=NULL;
    root=insertnode(root,45);

    insertnode(root,32);
    insertnode(root,67);
    insertnode(root,21);
    pre(root);
    printf("\n");
    int key;
    printf("enter element to search :");
    scanf("%d",&key);
  struct node * s= search(root,key);
  if (s!=NULL)
  {
   printf("%d found at address %u\n",key,s);
  }
  else
  {
    printf("%d not found",key);
  }

  struct node * root1=  treecopy(root); 
    printf("copy\n");
    inorder(root1);

   mirror(root);
   printf("mirror\n");
     inorder(root); 
   free(root);
}