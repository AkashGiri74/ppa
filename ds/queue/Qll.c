
#include<stdio.h>
#include<stdlib.h>
struct node
{   
   int data;
   struct node * next;
};
struct Queue
{  
   struct node * front;
   struct node *rare;
   
};

struct node * create_node()
{  int value;
  struct node * newnode=NULL;
  newnode=(struct node *)malloc(sizeof(struct node ));
  if(newnode==NULL)
  {
    puts("error in memory allocation");
    exit(EXIT_FAILURE);
  }
  else
  {  puts("enter data");
       scanf("%d",&value);
       newnode->data=value;
       newnode->next=NULL;

  }
  return newnode;
}

struct Queue *create_queue()
{
    struct Queue *queue=NULL;
    queue=(struct Queue *)malloc(sizeof(struct Queue));
      queue->front=NULL;
      queue->rare=NULL;
      return queue;


}
void enqueue(struct Queue * queue)
{  
  struct node* newnode=NULL;
   newnode=create_node();
  if (queue->front ==NULL && queue->rare==NULL)
  {
    queue->front=queue->rare=newnode;
  }
  queue->rare->next=newnode;
  queue->rare=newnode;


}
void dequeue(struct Queue * queue)
{
    if(queue->front==NULL && queue->rare==NULL)
    {   puts("queue is empty");
        return;
    }
    else{
           struct node * temp=queue->front;
           queue->front=queue->front->next;
           printf("dequeue element is %d ",temp->data);
           free(temp);
           if(queue->front==NULL)
           {
            queue->rare=NULL;
           }

    }
}
void display(struct Queue* queue)
{    struct node * temp=queue->front;
   if(queue->front==NULL && queue->rare==NULL)
    {   puts("queue is empty");
        return;
    }
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    } 
}
int main ()
{ struct Queue * queue=NULL;
    int choice;

    queue=create_queue();
    do
    {
        puts("1.enqueue");
        puts("2.dequeue");
        puts("3.display");
        puts("enter your choice");
        scanf("%d",&choice);
        switch (choice)
        {
         case 1:enqueue(queue);
            break;
        
        case 2:dequeue(queue);
            break;
           case 3:display(queue);
             break; 
        }
    } while (choice!=0);
    


}
