#include<stdio.h>
#include<stdlib.h>
struct Queue
{
    int *arr;
    int capacity;
    int rare;
    int front;

};

 struct Queue*create_queue()
{   int cap;
struct Queue* queue=NULL;
  queue=(struct Queue*)malloc(sizeof(struct Queue));\
  if(queue==NULL)
  {
    puts("error in memeory allocation");
    exit(EXIT_FAILURE);
  }

  puts("enter cap:");
  scanf("%d",&cap);

  queue->capacity=cap;
  queue->arr=(int *)malloc(queue->capacity*sizeof(int));
  if(queue->arr==NULL)
  {
    puts("error  in memory allocatin");
    exit(EXIT_FAILURE);
  }

  queue->front=-1;
  queue->rare=-1;
  return queue;
}
int is_full(struct Queue * queue)
{
  return  queue->rare==queue->capacity-1;
}
void enqueue(struct Queue* queue,int data)
{
   if( is_full(queue))
   {
    puts("queue is full");
    return;
   }
   (queue->rare)++;
   queue->arr[queue->rare]=data;
}
int is_empty(struct Queue* queue)
{
  return queue->front==queue->rare;
}
void dequeue(struct Queue * queue)
{
    if( is_empty(queue))
    {
        puts("queue is empty");
        return;
    }
    (queue->front)++;
    printf("dqueue element is %d ",queue->arr[queue->front]);
}
void display(struct Queue *queue)
{

int i;
for(i=queue->front+1;i<=queue->rare;i++)
{
   printf("%d ",queue->arr[i]);
}
}
void get_front(struct Queue * queue)
{
    if( is_empty(queue))
    {
        puts("queue is empty");
        return;
    }
    printf("front element is %d",queue->arr[(queue->front)+1]);
}
void get_rare(struct Queue * queue)
{   if( is_empty(queue))
    {
        puts("queue is empty");
        return;
    }
    printf("rare elemt is %d",queue->arr[queue->rare]);
}
void main ()
{   int choice;
    struct Queue *queue=NULL;
    queue=create_queue();
    do
    { printf("\n");
         puts("1.enqueue");
       puts("2.dequeue");
       puts("4.get front");
       puts("5.get rare");
       puts("3.display ");
       puts("0.exit");
       puts("enter your choice ");
       scanf("%d",&choice);
       switch (choice)
       {
       case 1:{int data;
        puts("enter data");
          scanf("%d",&data);
       enqueue(queue,data);}
        break;
        case 2:dequeue(queue);
        break;
        case 3:display(queue);
           break;
        case 4:get_front(queue);
           break;
        case 5:get_rare(queue);
          break;      
       
    
    
       }
        
    } while (choice!=0);
    
}