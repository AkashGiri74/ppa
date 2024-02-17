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

}void disaply_link_List(struct node * head)
{
    if(head==NULL)
    {
        printf("\n");
        return;
    }
    printf("%d ",head->data);
    disaply_link_List(head->next);
}
void insert_at_first(struct node ** head)
{
   struct node *newnode=NULL;
   newnode=createnode();
   newnode->next=*head;
   *head=newnode;
}
void insert_at_last(struct node* *head)
{
    create_link_List(head);
}


int main ()
{  int choice;
    struct node* first_node=NULL;
    do
    { printf("1.create ");
       printf("2.dispaly ");
       printf("3.insert at first \n");
       printf("insert at last ");
       printf("5.insert at position\n");
       printf("enter your choice:");
       scanf("%d",&choice);
       switch(choice)
       {
        case 1:create_link_List(&first_node);
             break;
        case 2:disaply_link_List(first_node);
        break;
        case 3:insert_at_first(&first_node);
        break; 
        case 4 :insert_at_last(&first_node);
        break;    
       }

    }while(choice!=0);
}