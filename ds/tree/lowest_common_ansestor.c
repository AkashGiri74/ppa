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
struct node* lowestcommonansector(struct node * root,struct node * p,struct node * q)
{    struct node *l,*r;
    if(root==NULL )
    {
          return NULL;
    }

    if( root->data==p->data )
    {
    return p;
     }
     if( root->data==q->data )
    {
    return q;
     }
  l=lowestcommonansector(root->left,p,q);
  r=lowestcommonansector(root->right,p,q);
  if(l && r)
  {
    return root;
  }
  else if(l)
  {
    return l;
  }
  else
  {
    return r;
  }

}
int main ()
{
    struct node * root=NULL;
    root=build_tree();
    inorder(root);

  
    int pData, qData;
    
    printf("Enter data for node p:");
    scanf("%d", &pData);
     

    printf("Enter data for node q: ");
    scanf("%d", &qData);
    

    printf("pData: %d, qData: %d\n", pData, qData);



    struct node *lca =lowestcommonansector(root, createnode(pData), createnode(qData));
    if(lca!=NULL)
    {
   printf("Lowest Common Ancestor of %d and %d is %d\n", pData, qData, lca->data);
    
    }
    else
    {
      printf("lca not found");
    }
      
    
    

} 