#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
};
 struct node * createnode ();
 void create_link_list(struct node **head);
 void disaply_link_List(struct node * head);
 void insertatfirst(struct node * * head);
 void insertatlast(struct node **head);
 int countnode(struct node * head);
 void insertatpos(struct node ** head);
 void delteatfirst(struct node **head);
 void deleteatlast(struct node ** head);
int main ()
{    struct node * first;
    int choice;
     do
     { 
        printf("1.create ");
        printf("2.display ");
        printf("0.exit\n");
        printf("3.insert at first\n");
        printf("4.insert at last\n");
        printf("5,insert at pos\n");
        printf("6.delete at 1st\n");
        printf("7.delete at last \n");
        printf("8.delete at pos\n");

        printf("enter your choice :");
        scanf("%d",&choice);
     switch(choice)
     { 
         case 0:printf("\n exiting the link list ");
         break;
        case 1:create_link_list(&first);
          break;
        case 2:disaply_link_List(first);
          break;
        case 3:insertatfirst(&first);
          break;
        case 4:insertatlast(&first);
           break; 
        case 5 :insertatpos(&first);
           break;
        case 6:delteatfirst(&first);
          break;
          case 7:deleteatlast(&first);
          break;
          case 8:delete_at_pos(&first);
            break;

    }
     }while(choice!=0);
  
}
 struct node * createnode ()
{    int value;
    struct node * newnode=NULL;
    newnode=(struct node *)malloc(sizeof(struct node));
    if (newnode==NULL)
    {
        puts("error in memeory alloction");
        exit(EXIT_FAILURE);
    }
     printf("enter element:");
     scanf("%d",&value);
    newnode->data=value;
    newnode->next=NULL;
    return newnode;
}
void create_link_list(struct node **head)
{
    struct node * newnode=NULL;
  struct node * tempnode=*head;
    newnode=createnode();
    if(*head==NULL)
    {
        *head=newnode;
    }
    else
    {
        while(tempnode->next !=NULL)
        {
            tempnode=tempnode->next;
        } 
        tempnode->next=newnode;
    }
}
void disaply_link_List(struct node * head)
{
    if(head==NULL)
    {
        printf("link list is empty");
    }
    else
    {
        while(head!=NULL)
        {
            printf("%d ",head->data);
            head=head->next;
        }
    }
    printf("\n");
}
void insertatfirst(struct node * * head)
{    struct node * newnode=NULL;
    newnode=createnode();
    newnode->next=*head;
    *head=newnode;
}
void insertatlast(struct node **head)
{
    create_link_list(head);
}
int countnode(struct node * head)
{
    int count=0;
    while(head!=NULL)
    {   count ++;
        head=head->next;
    }
    return count;
}
void insertatpos(struct node ** head)
{   struct node * newnode;
    int pos,n;
    n=countnode(*head);
    printf("enter the position :");
    scanf("%d",&pos);
    if(pos==1)
    {
        insertatfirst(head);
    }
    else if (pos==n+1)
    {
        insertatlast(head);
    }
    else if (pos<1 || pos >n+1)
    {
        printf("invalid position \nenter valid position");
        insertatpos(head);
    }
    else
    {
        struct node * travnode=*head;
        for(int i=0;i<pos-1;i++)
        {
            travnode=travnode->next;
        }
        newnode=createnode();
        newnode->next=travnode->next;
        travnode->next=newnode;
    }
}
void delteatfirst(struct node **head)
{
    struct node * tmp=*head;
    *head=(*head)->next;
    free(tmp);

}
void deleteatlast(struct node ** head)
{ struct node * travnode=*head;
   if (* head==NULL)
   {
    printf("link llist is empty");

   }
   else if ((*head)->next=NULL)
   {
    free(*head);
    *head=NULL;
   }
   else
   {  
   struct node * travnode=*head;  
   
    while(*head->next->next!=NULL)
     {
          travnode=travnode->next;   
     }
     free(travnode->next);
     travnode->next=NULL;
   

}
}
void delete_at_pos(struct node ** head)
{
  int pos;
  printf("enter pos to delete:");
  scanf("%d",&pos);
  int n=countnode(* head);
  if (pos==1)
  {
    delteatfirst(head);
  }
  else if (pos==n)
  {  
  deleteatlast(head);
  }
  else if(pos>n || pos <1)
  {
    prntf("invalid pos");
      delete_at_pos(head);
  } 
  else
  {  struct node *travnode=*head;
      for(i=0;i<pos-1;i++)
      
  }
}