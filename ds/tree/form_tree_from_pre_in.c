#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node * left;
    struct node * right;
    int data;
};
struct node * createnode(int value)
{
    struct node * new=(struct node*)malloc(sizeof(struct node));
    new->data=value;
    new->left=new->right=NULL;

}

int search_element(int in[],int n,int data)
{
    int i;
    for(i=0;i<n;i++)
    {  
        if( in[i]==data)
       { return i;
       }
    }

}
int post(struct node * root)
{  
    if(root!=NULL)
    {
        post(root->left);
        post(root->right);
        printf("%d ",root->data);
    }
}

struct node * create_t_from_pre_in(int pre[],int in[],int n,int *index,int inorder_start,int inorder_end )
{  int data,i;
   struct node *root=NULL;
     if(*index>=n || inorder_start > inorder_end)
   {
    return NULL ;
   }
   
   data=pre[*index];
  root= createnode(data);
  (*index)++;
   i=search_element(in,n,data);
   root->left=create_t_from_pre_in(pre,in,n,index,inorder_start,i-1);
   root->right=create_t_from_pre_in(pre,in,n,index,i+1,inorder_end);
   return root;
}
void main ()
{
    struct node* root=NULL;
    int pre[]={3,9,20,15,7};
    int in[]={9,3,15,20,7};
    int n=5;
    int index=0;
    struct node * root1=create_t_from_pre_in(pre,in,n,&index,0,n-1);
    printf("postorder traversal : ");
    post(root1);


}