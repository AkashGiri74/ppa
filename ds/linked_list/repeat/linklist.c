#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
};
struct node * create_node ();
void createlinllist(struct node **head);
void displaylinklist(struct node * head);
void insert_at_first(struct node ** head);
void insert_at_last(struct node **head);
void insert_at_pos(struct node ** head);
void delete_at_first(struct  node ** head);
void delete_at_last(struct node **head);
void delete_at_pos(struct node **head);
void reverse_link_list(struct node * head);

int main ()
{    struct node * first=NULL;
     int choice;
    do 
    { 
    printf("1.create ");
    printf("2.dislay ");
    printf("0.exit ");
    printf("3.inert at first \n");
    printf("4.insert at last");
    printf("5.insert at pos\n");
    printf("6.delte at 1st\n");
    printf("7,delete at last\n");
    printf("8.delete at position\n");
    printf("9.reverse link list \n");

    printf("\nenter your choice :");
    scanf("%d",&choice);
    switch(choice)
       {
        case 1:createlinllist(&first);
        break;
        case 2:displaylinklist(first);
        break;
        case 3:insert_at_first(&first);
        break;
        case 4:insert_at_last(&first);
        break;
        case 5:insert_at_pos(&first);
        break;
        case 6:delete_at_first(&first);
        break;
        case 7:delete_at_last(&first);
        break;
        case 8:delete_at_pos(&first);
        break;
        case 9:reverse_link_list(first);
        break;

      }
    }while(choice !=0);
}
struct node * create_node ()
{   int value;
    struct node * newnode=NULL;
    newnode=(struct node *)malloc(sizeof(struct node ));
    
    if(newnode==NULL)
    {
        puts("error in memeory alloction ");
        exit(EXIT_FAILURE);
    }
    printf("enter element:");
    scanf("%d",&value);
    newnode->data=value;
    newnode->next=NULL;
    
    return newnode;
}
void createlinllist(struct node **head)
{
    struct node * newnode=NULL;
    struct node *tempnode=*head;
    newnode=create_node();
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
void displaylinklist(struct node * head)
{
    if (head==NULL)
    {
        printf("linklist is empty");
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
void insert_at_first(struct node ** head)
{
    struct node * newnode=NULL;
    newnode=create_node();
    newnode->next=*head;
    *head=newnode;
}
void insert_at_last(struct node **head)
{
    createlinllist(head);
}
int count_node(struct node * head)
{
    int count=0;
    while(head!=NULL)
    {
        count ++;
        head=head->next;
    }
    return count;
}
void insert_at_pos(struct node ** head)
{   struct node * newnode=NULL;
    int pos,n;
    printf("enter position:");
    scanf("%d",&pos);
    n=count_node(* head);
    if (pos==1)
    {
        insert_at_first(head);
    }
   else  if (pos==n+1)
    {
        insert_at_last(head);
    }
    else if (pos <1 || pos >n+1)
    {
        printf("invalid position enter correct \n");
        insert_at_pos(head);
    }
    else
    {  struct node * travnode=*head;
        for( int i=0;i<pos-1;i++)
        {
            travnode=travnode->next;
        }
        newnode=create_node();
        newnode->next=travnode->next;
        travnode->next=newnode;
    }
}
void delete_at_first(struct  node ** head)
{
    struct node *tempnode=*head;
    *head=(*head)->next;
    free(tempnode);
}
void delete_at_last(struct node **head)
{
    struct node *travnode=*head;
 if(*head==NULL)
 {
    printf("linklist is empty");
 }
  else if((*head)->next==NULL)
  {
    free(*head);
    *head=NULL;
  }
   else
   { while(travnode->next->next!=NULL)
    {
        travnode=travnode->next;
    }
    free(travnode->next);
    travnode->next=NULL;
   }
}
void delete_at_pos(struct node **head)
{
    int pos,n;
    printf("enter position to delete: ");
    scanf("%d",&pos);
    n=count_node(*head);
    if (pos==1)
    {
        delete_at_first(head);

    }
    else if(pos==n)
    {
        delete_at_last(head);
    }
    else if(pos<1 || pos >n)
    {
        printf("invalid position..enter correct :");
        delete_at_pos(head);
    }
    else
    {
      struct node *travnode=*head;
     struct node *temp=NULL;
      for(int i=1;i<pos-1;i++)
      {  
          travnode=travnode->next;
      }
      temp=travnode->next;
      travnode->next=temp->next;
      free(temp);
    }
}
void reverse_link_list(struct node * head)
{
    if(head==NULL)
       return;
    reverse_link_list(head->next);
    printf("%d ",head->data);
}