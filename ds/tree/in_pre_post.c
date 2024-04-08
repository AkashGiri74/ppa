#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node * left;
    int data;
    struct node * right;
};
struct queuenode
{
    struct node * nodedata;
    struct queuenode * next;
};
struct queue
{
    struct queuenode* front;
    struct queuenode * rear;

};
struct node * createnode(int value)
{  struct node * newnode=NULL;
   newnode=(struct node *)malloc(sizeof(struct node));
      if(newnode==NULL)
      {
        return NULL;

      }
      newnode->data=value;
      newnode->left=newnode->right=NULL;
      return newnode;
}
struct node* build_tree()
{
  int data;
  puts("enter data");
  scanf("%d",&data);
  if(data==-1)
  {
    return NULL;
  }
  struct node *root=NULL;
     root=createnode(data);
    printf("enter data left of %d",data);
    root->left=build_tree();
    printf("enter data right of %d",data);
    root->right=build_tree();
    return root; 
}
struct queue * createqueue()
{
    struct queue * newnode=NULL;
     newnode=(struct queue* )malloc(sizeof(struct queue));
     if(newnode==NULL)
     {
        return NULL;
     }
     newnode->front=newnode->rear=NULL;
     return newnode;
}
struct queuenode* create_qnode(struct node * root)
{ struct queuenode * newnode=NULL;
     newnode=(struct queuenode* )malloc(sizeof(struct queuenode));
     if(newnode==NULL)
     {
        return NULL;
     }
   newnode->nodedata=root;
   newnode->next=NULL;
   return newnode;
}
void enqueue(struct queue * q,struct node * root)
{   
    struct queuenode * qnode=NULL;
    qnode=create_qnode(root);
    if(q->front==NULL)
       q->front=q->rear=qnode;
    q->rear->next=qnode;
    q->rear=q->rear->next;   

}
int is_empty(struct queue * q)
{
    return q->front==NULL;
}
struct node * deueue(struct queue * q)
{   struct queuenode * tempnode=NULL;
struct node *tempdata=NULL;
     
    if(is_empty(q))
    {
        return NULL;
    }
    tempnode=q->front;
    tempdata=q->front->nodedata;
    q->front=q->front->next;
    free(tempnode);
    return tempdata;

} 
void level_order_traverse(struct node * root)
{   struct node * temp=NULL;
    struct  queue* q=NULL;
       q=createqueue();

       enqueue(q,root);
       while(!is_empty(q))
       {  temp=deueue(q);
          printf("%d ",temp->data);
          if(temp->left !=NULL)
          {
            enqueue(q,temp->left);
          }
          if(temp->right !=NULL)
          {
            enqueue(q,temp->right);
          }

       }
}
void perorder(struct node * root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        perorder(root->left);
        perorder(root->right);
    }
}
void inorder(struct node * root)
{
    if(root!=NULL)
    {
        // printf("%d ",root->data);
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void postorder(struct node * root)
{
    if(root!=NULL)
    {
        // printf("%d ",root->data);
        postorder(root->left);
        // printf("%d ",root->data);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
void main ()
{
    struct node * root=NULL;
    root=build_tree();
    printf("level order traverse :");
    level_order_traverse(root);
    printf("\npreorder traversal is :");
    perorder(root);
    printf("\ninorder traversal is:");
    inorder(root);
    printf("\npostorder traversal is :");
    postorder(root);
}