#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* createnode()
{
  struct node * newnode=NULL;
  int value;
  newnode=(struct node * )malloc(sizeof(struct node));
  if (newnode==NULL)
  {
    puts("error in memeory allocation");
    exit(EXIT_FAILURE);
  }
  printf("enter element:");
  scanf("%d",&value);
  newnode->data=value;
  newnode->next=NULL;
  return newnode;
}
void cratelinkedlist(struct node* *head)
{
   struct node * new_node;
   struct node* tempnode=*head;
    new_node=createnode();
    if(*head==NULL)
    {
      *head=new_node;
    }
    else
    {
        while(tempnode ->next!=NULL)
        {
          tempnode=tempnode->next;
        }
        tempnode->next=new_node;

    }
}
// void displaylinkedlist(struct node* head)
// {
//    if (head==NULL)
//      puts("linked list is empty");
//    else
//    { 
//     while(head!=NULL)
//     {
//      printf("%d ",head->data);
//      head = head->next;
//     }
//   }
//   printf("\n\n");
// }
void displaylinkedlist(struct node* head)
{
  printf("%d ",head->data);
  displaylinkedlist(head->next);

}
int main ()
{ int choice;
struct node *firstnode=NULL;
  do
 {
  printf("1.create link list\n");
  printf("2.display\n");
  printf("0.EXIT\n");
  printf("enter your choice : ");
  scanf("%d",&choice);
   
   switch(choice)
   {
    
    case 1:cratelinkedlist(&firstnode);
            break;
    case 2:displaylinkedlist(firstnode);
            break;   
               
   }
 }while(choice !=0);

}