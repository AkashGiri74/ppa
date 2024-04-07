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
    struct node* rear;
};
struct node * create_node()
{
    struct node* newnode=NULL;
    newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        puts("error in memeory allocation");
        exit(EXIT_FAILURE);
    }
    else{
        int value;
        printf("enter element :");
        scanf("%d",&value);
        newnode->data=value;
        newnode->next=NULL;
    }
    return newnode;
}
struct Queue * create_queue()
{
    struct Queue * cqueue=NULL;
    cqueue=(struct Queue *)malloc(sizeof(struct Queue));
    if(cqueue==NULL)
    {
        puts("error ");
        exit(EXIT_FAILURE);
    }
    else
    {
        cqueue->front=cqueue->rear=NULL;
    }
    return cqueue;

}
void enqueue(struct Queue * cqueue)
{
    struct node * newnode=NULL;
    newnode=create_node();
    if(cqueue->front==NULL && cqueue->rear==NULL)
    {
        cqueue->front=cqueue->rear=newnode;
        cqueue->rear->next=cqueue->front;
    }
    cqueue->rear->next=newnode;
    cqueue->rear=newnode;
    cqueue->rear->next=cqueue->front;
}
voide dequeue(struct Queue * cqueue)
 {
    struct node * tempnode=NULL;
    if(cqueue->front==NULL&& cqueue->rear==NULL)
    {
        puts("list is empty");
        return;
    }
    else if(cqueue->front->next==cqueue->rear)
    {
        free(cqueue->front);
        cqueue->front=NULL;
        cqueue->rear=NULL;

    }
    else
    {
        tempnode=cqueue->front;
        cqueue->front=cqueue->front->next;
        cqueue ->rear->next=cqueue->front;
        free(tempnode);
}
}
// void dequeue(struct Queue * cqueue)
// {
//     if(cqueue->front==NULL && cqueue->rear==NULL)
//     {
//         puts("empty");
//         return;
//     }
//     else if(cqueue->front->next=cqueue->rear)
//     {  free(cqueue->front);
//          cqueue->front=cqueue->rear=NULL;
    
//     }
//     struct node * tmp=cqueue->front;
//     cqueue->front=cqueue->front->next;
//     cqueue->rear->next=cqueue->front;
//     printf("%d dqueued elemet ",cqueue->front->data);
//     free(tmp);
    
// }
int main ()
{  struct Queue * cqueue=NULL;
  cqueue=create_queue();
  int choice;
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
         enqueue(cqueue);}
            break;
        
        case 2:dequeue(cqueue);
            break;
        //   case 3:display(cqueue);
        //       break;
        //    case 4:get_front(cqueue);
        //      break;    
        //      case 5:get_rear(cqueue);
        //      break;
        }
    }while(choice!=0);


}
