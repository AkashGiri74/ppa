#include<stdio.h>
#include<stdlib.h>
struct Queue
{
    int *arr;
    int capacity;
    int front;
    int rare;
    int size;
};
struct Queue *create_queue()
{   int cap;
    struct Queue* cqueue=NULL;
    cqueue=(struct Queue *)malloc(sizeof(struct Queue));
    if(cqueue==NULL)
    {
        puts("error in memory allocation");
        exit(EXIT_FAILURE);
    }
    else
    {
        puts("enter cap");
        scanf("%d",&cap);
        cqueue->capacity=cap;
        cqueue->arr=(int *)malloc(cqueue->capacity * sizeof(int));
        cqueue->front=-1;
        cqueue->rare=-1;

    }
    return cqueue;
}
int is_full(struct Queue * cqueue)
{
    return cqueue->size==cqueue->capacity;
}
void enqueue (struct Queue * cqueue,int data)
{   
     if(is_full(cqueue))
  {
    puts("queue is full");
    return;
  }
  cqueue->rare=(cqueue->rare+1)%cqueue->capacity;
    cqueue->arr[cqueue->rare]=data;
    (cqueue->size)++;

}
int is_empty(struct Queue * cqueue)
{
    return cqueue->size == 0;
}
void dequeue(struct Queue * cqueue)
{
    if(is_empty(cqueue))
    {
        puts("queue is empty");
        return;
    }
    
    else
    {
        cqueue->front = (cqueue->front + 1) % cqueue->capacity;
    }
    printf("Dequeued element: %d\n", cqueue->arr[cqueue->front]);
    (cqueue->size)--;
}
void display(struct Queue * cqueue)
{  int i;
    if(is_empty(cqueue))
    {
        puts("queue is empty");
        return;
    }

    i = cqueue->front;
    do
    {
        printf("%d ", cqueue->arr[i]);
        i = (i + 1) % cqueue->capacity;
    }
     while (i != (cqueue->rare + 1) % cqueue->capacity);
    printf("\n");
}
void get_front(struct Queue *cqueue) {
    if (is_empty(cqueue))
     {
        printf("Queue is empty\n");
    }
     else
      {
    //    printf("Front element: %d\n", cqueue->arr[cqueue->front]);
        printf("Front element: %d\n", cqueue->arr[(cqueue->front + 1) % cqueue->capacity]);

    }
}

void get_rear(struct Queue *cqueue)
{
    if (is_empty(cqueue)) 
    {
        printf("Queue is empty\n");
    } 
    else
     {
        printf("Rear element: %d\n", cqueue->arr[cqueue->rare]);
    }
}
int main ()
{   int choice;
    struct Queue* cqueue=NULL;
    cqueue=create_queue(); 
    do
    {
        puts("1.enqueue");
        puts("2.dequeue");
        puts("3.display");
        puts("4.get front ");
        puts("5.get rare ");
        puts("enter your choice");
        scanf("%d",&choice);
        switch (choice)
        {
         case 1: {
            int data;
           puts("enter data");
          scanf("%d",&data);
         enqueue(cqueue,data);}
            break;
        
        case 2:dequeue(cqueue);
            break;
          case 3:display(cqueue);
              break;
           case 4:get_front(cqueue);
             break;    
             case 5:get_rear(cqueue);
             break;
        }
    } while (choice!=0);
}