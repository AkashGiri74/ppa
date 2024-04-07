#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    int priority;
    struct node * next;
};

void enqueue(struct node ** head)
{  int value,priority;
  struct node * newnode=NULL;
   newnode=(struct node *)malloc(sizeof(struct node));
   if(newnode==NULL)
   {puts("error in memeory allocation");

   exit(EXIT_FAILURE);

   }else
   {  printf("enter data");
      scanf("%d",&value);
    newnode->data=value;
      puts("enter priroty");
      scanf("%d",&priority);
    newnode->priority=priority;
    newnode->next=NULL;
   }

   if(*head==NULL)
   {
    *head=newnode;
    return;
   }
   if((*head)->priority > newnode->priority )
   {
    newnode->next=*head;
    *head=newnode;
   }
   else
   {  struct node * current=*head;
      struct node * prev=NULL;
      while (current /*->next*/ !=NULL && current->priority < newnode->priority)
      {
        prev=current;
        current=current->next;
      }
      newnode->next=current;
      prev->next=newnode;

   }
}
int main ()
{
    struct node * front=NULL;
   
    int choice;
    do
    {
        puts("1.enqueue");
        puts("2.display");
        puts("3.dequeue");
   puts("enter your choice");
   scanf("%d",&choice);
        switch (choice)
        {
        case 1:enqueue(&front);
            
            break;
        
        case 2:display(front);
            break;
         case 3:deueue(&front);
           break;   
        }
    } while (choice!=0);
    
}