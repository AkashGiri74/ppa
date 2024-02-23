#include<stdio.h>
#include<stdlib.h>
struct node
{   struct node *prev;
    int data;
    struct node * next;
};
struct node * createnode()
{  struct node * newnode=NULL;
   int value;
  newnode=(struct node *)malloc(sizeof(struct node));
  if(newnode==NULL)
  {
    printf("error in memeory allocation \n");
    exit(EXIT_FAILURE);
  }
  else
  {
    printf("enter element:");
    scanf("%d",&value);
    newnode->prev=NULL;
    newnode->data=value;
    newnode->next=NULL;
  }

}
void create_link_list(struct node **head,struct node **tail)
{
    struct node * newnode=NULL;
    struct node *tempnode=*head;
    newnode=createnode();
    if(*head==NULL && *tail==NULL)
    {
        *head=*tail=newnode;
        newnode->next=*head;
    }
    else
    {  while(tempnode->next!=*tail)
       {
         tempnode=tempnode->next;
        }
        (*tail)->next=newnode;
        newnode->prev=*tail;
        (*head)->prev=newnode;
        *tail=newnode;
    }

}
void display_forward(struct node * head,struct node *tail)
{   if(head==NULL)
  {
    printf("link list is empty ");
    exit(EXIT_FAILURE);
 }
 else
 {
    struct node * tempnode=head;
      do
       {
          printf("%d ",tempnode->data);
          tempnode=tempnode->next;
       }  while(tempnode!=tail);
 }

}
void display_backward(struct node * tail,struct node *head)
{ if(tail==NULL)
 {
  printf("link list is empty ");
  exit(EXIT_FAILURE);
 } 
 else
 {  struct node * tempnode=tail;
   do
   {
    printf("%d ",tempnode->data);
    tempnode=tempnode->prev;
   } while(tempnode !=head);
   

 }

}
// void insert_at_first(struct node **head,struct node **tail)
// {
//     struct node * new_node=createnode();
//     (*head)->prev=new_node;
//     new_node->next=(*head);
//     *(tail)->next=new_node;
//     new_node->prev=(*tail);
    
// }
void insert_at_first(struct node **head, struct node **tail)
{
    struct node *new_node = createnode();
    new_node->next = *head;
    (*head)->prev = new_node;
    new_node->prev = *tail;
    (*tail)->next = new_node;
    *head = new_node;
}


int main ()
{   struct node *first=NULL;
    struct node *last=NULL;
      int choice;
    do
    { printf("1.create ");
      printf("2.display forward ");
      printf("3. display backward ");
      printf("4.insert at first ");
      printf("0. exit ");
        printf("enter your choice: ");
        scanf("%d",&choice);
      switch(choice)
      {
        case 1:create_link_list(&first,&last);
          break;
        case 2:display_forward(first,last );
          break;
        case 3:display_backward(last,first);
          break;
        case 4:insert_at_first(&first,&last);
          break;
      }
    }while(choice !=0);
}