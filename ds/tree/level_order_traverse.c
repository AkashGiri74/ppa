//level order traverse
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * left,*right;
};
struct Queuenode
{
    struct node * nodedata;
    struct Queuenode * next;
};
struct queue
{
    struct Queuenode * front;
    struct Queuenode * rear;
};

struct node * createnode(int value)
{
    struct node * newnode=NULL;
    newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        return NULL;
    }
    else
    {
        newnode->data=value;
        newnode->left=newnode->right=NULL;
        return newnode;
    }
}
struct node * build_tree()
{    int data;
  printf("enter data :");
  scanf("%d",&data);
  if(data==-1)
  {
    return NULL;
  }
    struct node * root=NULL;
    root=createnode(data);
    printf("enter data for left of %d ",data);
    root->left=build_tree();
    printf("enter data for right of %d ",data);
    root->right=build_tree();
    return root;
}
struct queue * create_queue()
{
    struct queue * q=NULL;
    q=(struct queue *)malloc(sizeof(struct queue));
    if(q==NULL)
    return NULL;
    q->front=NULL;
    q->rear=NULL;
    return q;
}
struct Queuenode* create_qnode(struct node * root)
{
    struct Queuenode * newqueuenode=NULL;
    newqueuenode=(struct Queuenode *)malloc(sizeof(struct Queuenode));
    if (newqueuenode==NULL)
    {
        return NULL;
    }
    newqueuenode->nodedata=root;
    newqueuenode->next=NULL;
    return newqueuenode;

}
void enqueue(struct queue * q,struct node * root)
{
    struct Queuenode * qnode=NULL;
      qnode=create_qnode(root);

      if(q->front==NULL)
      {
        q->front=q->rear=qnode;
      }
      else
      {
        q->rear->next=qnode;
        q->rear=q->rear->next;
      }
}
int is_empty(struct queue * queue)
{
    return queue->front==NULL;
}
struct node * dequeue(struct queue * q)
{
    struct node * tempdata=NULL;
    struct Queuenode * tempnode=NULL;
    if(q->front==NULL)
    {
        return NULL;
    }
    tempdata=q->front->nodedata;
    tempnode=q->front;
    q->front=q->front->next;
    if(q->front==NULL)
    {
        q->rear==NULL;
    }
    free(tempnode);
    return tempdata;
}
void level_order_traverse(struct node * root)
{
    struct queue* q=NULL;
    q=create_queue();
    enqueue(q,root);
    struct node * tempdata=NULL;
    while(!is_empty(q))
    {  tempdata=dequeue(q);
      printf("%d ",tempdata->data);
      if(tempdata->left!=NULL)
     {
        enqueue(q,tempdata->left);
     }
      if(tempdata->right!=NULL)
     {
        enqueue(q,tempdata->right);
     }

    }

}


int main ()
{
    struct node * root=NULL;
    root=build_tree();
    level_order_traverse(root);

}