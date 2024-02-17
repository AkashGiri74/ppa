#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
};
 struct node * createnode()
  {   int value; 
    struct node * newnode=NULL;
 newnode=(struct node *) malloc(sizeof(struct node ));
 if (newnode==NULL)
 {
  puts("error in memory allocation");
  exit(EXIT_FAILURE);
 }
 printf("enter element");
 scanf("%d",&value);
 newnode->data=value;
 newnode->next=NULL;
 
  return newnode;
  }
  void createlinklist(struct node ** head)
  {
    struct node * newnode=NULL;
      struct node * tempnode=* head;
      newnode=createnode();
        if(*head==NULL)
        {
          *head=newnode;
        }
        else
        {
          while(tempnode->next!=NULL)
          {
            tempnode=tempnode->next;
          }
          tempnode->next=newnode;
        }

  }
  void display(struct  node * head)
  {
    if (head==NULL)
    {
      printf("link list is empty");
    
    }
    else{
      while(head!=NULL)
      {
        printf("%d ",head->data);
        head=head->next;
      }
    }
  }
  void sort_dcending(struct node ** head)
  {
    struct node *tavnode=*head;
    struct node *tempnode=NULL;
     int temp;
    for(tavnode=*head;tavnode!=NULL;tavnode=tavnode->next)
    {
      for(tempnode=tavnode->next;tempnode!=NULL;tempnode=tempnode->next)
      {
        if(tavnode->data < tempnode->data)
        {  temp=tavnode->data;
        tavnode->data=tempnode->data;
        tempnode->data=temp;

        }
      }
    }
  }
int main ()
{  struct node * first=NULL;
int choice;
do
{
  printf("1.create link list\n");
  printf("2.display link list\n");
  printf("3.sort decending\n");
  printf("0.exit\n");

     printf("enter your choice\n");
     scanf("%d",&choice);
     switch(choice)
     {
      case 1:createlinklist(&first);
         break;
         case 2:display(first);
         break;
       case 3:sort_dcending(&first);
       break;  
     }

}while(choice !=0);

}