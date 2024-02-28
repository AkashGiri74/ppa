#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
};

struct node * createnode()
{    int  value;
    struct node * newnode=NULL;
      newnode=(struct node *)malloc(sizeof(struct node));
      if(newnode==NULL)
      {
        puts("error in memory alloction");
        exit(EXIT_FAILURE);
      }
      else{
        
        printf("enter data:");
        scanf("%d",&value);
        newnode->data=value;
        newnode->next=NULL;
      }
      return newnode;
}
void create_link_list(struct node * * head)
{    struct node * tarvnode=*head;
    struct node * newnode=NULL;
    newnode=createnode();
    if(*head==NULL)
    {
        *head=newnode;
    }
    else{
        while (tarvnode->next!=NULL)
        {
            tarvnode=tarvnode->next;
        }
        tarvnode->next=newnode;
    }
}
  void display_link_list(struct node *head)
  {
    if(head==NULL)
    {
        printf("link list is empty");
        exit(EXIT_FAILURE);
    }
    else{
        struct node * travnode=head;
         while(travnode!=NULL)
         {
            printf("%d ",travnode->data);
            travnode=travnode->next;
         }
    }
  }

  void insert_at_first(struct node ** head)
  {
    struct node * newnode=createnode();
    newnode->next=*head;
      *head=newnode;
  }
  void insert_at_last(struct node ** head)
  {
    create_link_list(head);
  }



   
  
  void delete_at_first(struct node ** head)
  {  struct node * tempnode=*head;
      *head=(*head)->next;
        free(tempnode);
  }
  void delete_at_last(struct node ** head)
  {
    struct node * travnode=*head;
    if(*head==NULL)
    {
        printf("link list is empty");
    }
    else if((*head)->next==NULL)
    {
       free(*head);
         *head=NULL;
    }

    while(travnode->next->next!=NULL)
    {
        travnode=travnode->next;
    }
      free(travnode->next);
      travnode->next=NULL;
  }





int main ()

{
    struct node * first=NULL;
    int choice;
    do
    {   puts("1.create ");
        puts("2.display ");
        puts("3.insert at first ");
        puts("4.insert at last ");
        puts("5.insert at postion ");
        puts("6.delete at first ");
        puts("7.delete at last ");
        puts("8.delete at postiion ");
        puts("enter your choice ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:create_link_list(&first);
              break;
            case 2:display_link_list(first);
               break;
            case 3:insert_at_first(&first);
              break;
            case 4:insert_at_last(&first);
              break;
              


            case 6:delete_at_first(&first);
               break;
            case 7:delete_at_last(&first);
                break;
       

        }
        
    } while (choice !=0);
    
}