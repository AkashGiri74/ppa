#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int *arr;
    int capacity;
    int front;
    int rear;
    int size;
};

struct Queue *create_queue()
{   
    int cap;
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
        cqueue->rear=-1;
        cqueue->size = 0;
    }
    return cqueue;
}

int is_full(struct Queue * cqueue)
{
    return cqueue->size == cqueue->capacity;
}

int is_empty(struct Queue * cqueue)
{
    return cqueue->size == 0;
}

void enqueue(struct Queue * cqueue, int data)
{   
    if(is_full(cqueue))
    {
        puts("queue is full");
        return;
    }
    if(is_empty(cqueue))
    {
        cqueue->front = 0;
        cqueue->rear = 0;
    }
    else
    {
        cqueue->rear = (cqueue->rear + 1) % cqueue->capacity;
    }
    cqueue->arr[cqueue->rear] = data;
    (cqueue->size)++;
}

void dequeue(struct Queue * cqueue)
{
    if(is_empty(cqueue))
    {
        puts("queue is empty");
        return;
    }
    int item = cqueue->arr[cqueue->front];
    if(cqueue->front == cqueue->rear)
    {
        cqueue->front = -1;
        cqueue->rear = -1;
    }
    else
    {
        cqueue->front = (cqueue->front + 1) % cqueue->capacity;
    }
    printf("Dequeued element: %d\n", item);
    (cqueue->size)--;
}

void display(struct Queue * cqueue)
{
    if(is_empty(cqueue))
    {
        puts("queue is empty");
        return;
    }
    printf("Queue elements: ");
    int i = cqueue->front;
    do
    {
        printf("%d ", cqueue->arr[i]);
        i = (i + 1) % cqueue->capacity;
    } while (i != (cqueue->rear + 1) % cqueue->capacity);
    printf("\n");
}

int main ()
{   
    int choice;
    struct Queue* cqueue=NULL;
    cqueue=create_queue(); 
    do
    {
        puts("1.enqueue");
        puts("2.dequeue");
        puts("3.display");
        puts("0.Exit");
        puts("enter your choice");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1: {
                int data;
                puts("enter data");
                scanf("%d",&data);
                enqueue(cqueue,data);
            }
            break;
        
            case 2:
                dequeue(cqueue);
                break;
                
            case 3:
                display(cqueue);
                break; 
        }
    } while (choice!=0);
}
