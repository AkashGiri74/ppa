#include<stdio.h>
#include<stdlib.h>
struct  node
{int data;
struct node * next;
};

struct node * createnode ()
{   struct node * newnode=NULL;
    newnode=(struct node *)malloc(sizeof(struct node));
    
        if(newnode==NULL)
     {   printf("stack is oveflow ");
        fprintf(stderr,"Error in memory allocation");
        exit(EXIT_FAILURE);      
    }
    else
    {
        printf("enter data :");
        scanf("%d",&(newnode->data));
        newnode->next=NULL;
    }
     return newnode;
}
struct node * push(struct node *head)///insert at first
{  struct node *newnode=NULL;
    newnode=createnode();

    if(head==NULL)
    {
        head=newnode;
    }
    else
    {  newnode->next=head;
          head=newnode;

    }
    return head;
}
struct node * pop(struct node * head)//delete at first 
{
    if(head==NULL)
    {
    printf("stack undeflow");
    }
    else{
        struct node * temp=head;
        printf("pop elemnt is %d ",temp->data);
        head=head->next;
        free(temp);
    }
    return head;
}
struct node * peek(struct node * head)
{   if(head==NULL)
    {
    printf("stack undeflow");
    }
    printf("top elemet %d",head->data);
}
void display(struct node * head)
{   if(head==NULL)
     {
    printf("stack undeflow");
    }
    while(head !=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
}

int main ()
{    struct node * top=NULL;
   int choice;
    do
    {
        puts("1.push");
        puts("2.pop ");
        puts("3.peek ");
        puts("4.display ");
        puts("enter your choice :");
        scanf("%d",& choice);

        switch (choice)
        {
        case 1:top=push(top);
            break;
        case 2:top=pop(top);
             break;
        case 3:peek(top);
            break;
        case 4:display(top);
            break;             
        
        }
    } while (choice !=0);
    
}
