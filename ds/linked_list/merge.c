#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
};
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
void create_link_List2(struct node* *head1)
{
    struct node * newnode=NULL;
    struct node *tempnode=*head1;
    newnode=createnode();
    if (*head1==NULL)
    {
        *head1=newnode;
    }
    else
    {
        while(tempnode->next !=NULL)
        {
            tempnode=tempnode->next;
        }
        tempnode->next=newnode;
    }
       
       
         printf("second link list\n");
         struct node * trav=*head1;
         while(trav!=NULL)
         {
            printf("%d ",trav->data);
            trav =trav->next;
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
void merge_link_list(struct node **head,struct node * head1)
{  
    if (*head ==NULL)
   {
    *head=head1;
  }
  else
  {
      struct node *travnode=*head;
    while(travnode->next !=NULL)
    {
        travnode=travnode->next;
    }
    travnode->next=head1;
  }

}


int main ()
{  int choice;
    struct node* first_node=NULL;
    struct node * secondnode=NULL;
    do
    { printf("\n 1.create ");
       printf("2.dispaly ");
       printf("3.create second\n");
       printf("4.merge link list\n");
       printf("0.exit\n");
       printf("enter your choice :");
       scanf("%d",&choice);
       switch(choice)
       {
        case 1:create_link_List(&first_node);
             break;
        case 2:disaply_link_List(first_node);
        break;
        case 3:create_link_List2(&secondnode);
          break; 
        case 4 :merge_link_list(&first_node,secondnode);
          break;    
       }

    }while(choice!=0);
}