#include<stdio.h>
#include<stdlib.h>
struct element//for enqueue
{
int data;
int priorty;
};
struct PQueue
{
   struct element* arr;
    int capacity;
    int size;
};
 struct PQueue *  create_queue()
{   int capacity;
    struct PQueue *pq=NULL;
    pq=(struct PQueue*)malloc(sizeof(struct PQueue));
    if(pq==NULL)
    {
        puts("error in memeory allocation");
        exit(EXIT_FAILURE);
    }
    puts("enter capacity");
    scanf("%d",&capacity);
    pq->capacity=capacity;
    pq->arr=(struct element*)malloc(pq->capacity *sizeof(struct element));
    if(pq->arr==NULL)
    {
        puts("error in memeory allocation");
        exit(EXIT_FAILURE);
    }
    pq->size=0;
    return pq;
}
int is_full(struct PQueue * pq)
{
    return pq->size==pq->capacity;
}
void enqueue(struct PQueue* pq)
{  int i,data,priority;
    if(is_full(pq))
    {
        puts(" priorty queue is full ");
        return;
    }
    puts("enter data");
    scanf("%d",&data);
    puts("enter priorty");
    scanf("%d",&priority);
    (pq->arr[pq->size]).data=data;
    pq->arr[pq->size].priorty = priority;//address asel trr -> direct object asel trr .
    (pq->size)++;
    struct element  temp;
    for(i=pq->size-1;i>0;i--)
    {
        if((pq->arr[i]).priorty > (pq->arr[i-1]).priorty)
       {
         temp=pq->arr[i];
        pq->arr[i]=pq->arr[i-1];
        pq->arr[i-1]=temp;
       }

    }

}
int is_empty(struct PQueue* pq)
{
    return pq->size==0;
}
void dqueue(struct PQueue * pq)
{
    if(is_empty(pq))
    {  puts("empty");
       return;

    }
    else
    { int i;
      for(i=0;i<pq->size-1;i++)
      {
        pq->arr[i]=pq->arr[i+1];
      }
     (pq->size)--;
    }
}
int peek(struct PQueue * pq)
{  
     for(int i=0;i<pq->size-1;i++)
{
    return pq->arr[0].data;
}
}
void display(struct PQueue* pq)
 {
    if (pq->size == 0)
     {
        puts("Priority queue is empty");
        return;
    }
    
    for (int i = 0; i < pq->size; i++)
     {
        printf("Data: %d, Priority: %d\n", pq->arr[i].data, pq->arr[i].priorty);
    }
}
int main ()
{ struct PQueue * pq=NULL;
   pq=create_queue();
   int choice;
   do
   {
    puts("1.enequeue");
    puts("2.display");
    puts("3.dequeue");
    puts("4.peek");
    puts("enter your choice");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        enqueue(pq);
        break;
    
    case 2:display(pq);
        break;
    case 3:dqueue(pq);
        break;
    case 4: {int p;
     p=peek(pq);
    printf("peek elemnt is %d",p);
     } break;        
    }
   } while (choice!=0);

   free(pq->arr);
    free(pq);
   

}