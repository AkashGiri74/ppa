#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
};
void delete_at_pos(struct node **head);
void create_link_List(struct node* *head);
struct node * createnode();
void disaply_link_List(struct node * head);
void delete_at_first(struct node ** head);
void delete_last(struct node **head);
int count_node(struct node *  head);
int main ()
{  int choice;
    struct node* first_node=NULL;
    do
    { printf("1.create ");
       printf("2.dispaly ");
       printf("3.delete at first \n");
       printf("4.delete  at last \n ");
          printf("5.delete  at pos\n ");
       printf("0.exit\n");
       
       printf("enter your choice:");
       scanf("%d",&choice);
       switch(choice)
       {
        case 1:create_link_List(&first_node);
             break;
        case 2:disaply_link_List(first_node);
        break;
        case 3:delete_at_first(&first_node);
        break; 
        case 4 :delete_last(&first_node);
        break;
        case 5:delete_at_pos(&first_node);
          break;    
       }

    }while(choice!=0);
}
struct node * createnode()
{   int value;
    struct node * new_node=NULL;
    new_node=(struct node *)malloc(sizeof(struct node));
    if(new_node==NULL)
    {  puts("error in memory allocation\n");
       exit(EXIT_FAILURE);
    }
    printf("enter element:");
    scanf("%d",&value);
    new_node->data=value;
    new_node->next=NULL;
}
void create_link_List(struct node* *head)
{
    struct node * newnode=NULL;
    struct node *tempnode=*head;
    newnode=createnode();
    if (*head==NULL)
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
        printf("\n");
        return;
    }
    printf("%d ",head->data);
    disaply_link_List(head->next);
}
void delete_at_first(struct node ** head)
{  
    struct node * temp=*head;
      *head=(*head)->next;
        free(temp);


}
void delete_last(struct node **head)
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
int count_node(struct node *  head)
{  int count=0;
    while(head!=NULL)
    {
        count++;
        head=head->next;
    }
    return count;

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
        delete_last(head);
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