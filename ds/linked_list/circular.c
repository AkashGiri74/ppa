//oparations on circular link list 
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
        (*head)->next=*head;
    }
    else
    {
        while(tempnode->next !=*head)
        {
            tempnode=tempnode->next;
        } 
        tempnode->next=newnode;
        newnode->next=*head;
    }

}void disaply_link_List(struct node * head)
{
    if(head==NULL)
    {
        printf("link list is empty \n");
        return;
    }
    else
    {   struct node * tempnode=head;
            do
            {
                printf("%d ",tempnode->data);
                tempnode=tempnode->next;
            }
            while(tempnode!=head);
    }
    
}
void insert_at_first(struct node ** head)
{
    struct node *tempnode=*head;
  struct node *newnode=createnode();
while(tempnode->next!=*head)
  {
    tempnode=tempnode->next;
  }
  tempnode->next=newnode;
  newnode->next=*head;
  *head=newnode;

}
void insert_at_last(struct node **head)
{
    create_link_List(head);
}
int countnode(struct node *head)
{   int count=0;
    struct node *tempnode=head;
    while(tempnode->next!=head)
    {
        count++;
        tempnode=tempnode->next;
    }
    return count;
}
void insert_at_pos(struct node ** head)
{
    int pos,n;
    printf("enter pos :");
    scanf("%d",&pos);
    n=countnode(*head);
    if(pos==1)
    {
        insert_at_first(head);
    }
    else if (pos==n+1)
    {
        insert_at_last(head);
    }
    else if (pos <1 || pos >n+1)
    {
        printf("invalid position ");
        insert_at_pos(head);
    }
    else
    {
       struct node * tempnode=*head;
       for(int i=1;i<pos-1;i++)
       {
        tempnode=tempnode->next;
       }
       struct node* new_node=createnode();
       new_node->next=tempnode->next;
       tempnode->next=new_node;
    }
}
// void delete_at_fist(struct node **head)
// {
//     struct node * tempnode=*head;
//     struct node * findlastnode=*head;
//   if(tempnode->next==*head)
//   {
//     *head=NULL;
//     free(tempnode);
//   }
//   else{ 
//      while(findlastnode->next !=NULL)
//     {
//         findlastnode =findlastnode ->next;
//     }
//     findlastnode->next=tempnode->next;
//     *head=tempnode->next;
//     free(tempnode);
//   }
// }
void delete_at_first(struct node **head)
{
    if (*head == NULL) 
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct node *tempnode = *head;
    struct node *findlastnode = *head;
    while (findlastnode->next != *head) 
    {
        findlastnode= findlastnode->next;
    }
    if (tempnode->next == *head)//fkt ekach node asl trr 
     {
        *head = NULL;
        free(tempnode);
    }
     else
     {
        findlastnode->next = tempnode->next;
        *head = tempnode->next;
        free(tempnode);
    }
}
void delete_at_last(struct node **head)
{
    struct node * tempnode=*head;
    struct node * previousnode=NULL;
    while(tempnode->next !=*head)
    {   previousnode=tempnode;
        tempnode=tempnode->next;
    }
    if (tempnode->next ==*head)
    {
        *head=NULL;
        free(tempnode);
    }
    else{
        previousnode->next=tempnode->next;
        if(tempnode==*head )
           *head=previousnode->next;
        free(tempnode);
    }
    
}
void delete_at_pos(struct node **head)
{  int pos,n;
printf("enter pos:");
scanf("%d",&pos);
  n=countnode(*head);
    if (pos==1)
    {
        delete_at_first(head);
    }
    else if(pos==n)
    {
        delete_at_last(head);
    }
    else if (pos <1 || pos >n)
    {
        printf("invalid pos ");
        delete_at_pos(head);
    }
    else{
        struct node * travnode=*head;
        for(int i=1;i<pos-1;i++)
        {
            travnode=travnode->next;
        }
        struct node *tempnode=travnode->next;
        travnode->next=travnode->next->next;
        free(tempnode);
    }
}


int main ()
{  int choice;
    struct node* first_node=NULL;
    do
    { printf("1.create ");
       printf("2.dispaly ");
       printf("3. insert at first ");
       printf("4.insert at last");
       printf("5.insert at pos \n");
       printf(" 6.delete at first ");
       printf("7.delete at last ");
       printf("8.delete at position ");
       printf("0.exit \n");
       printf("enter your choice ");

       scanf("%d",&choice);
       switch(choice)
       {
        case 1:create_link_List(&first_node);
             break;
        case 2:disaply_link_List(first_node);
        break;  
        case 3:insert_at_first(&first_node);
         break;   
         case 4:insert_at_last(&first_node);
         break;
         case 5:insert_at_pos(&first_node);
         break;
         case 6:delete_at_first(&first_node);
         break;
         case 7:delete_at_last(&first_node);
         break;
         case 8:delete_at_pos(&first_node);
         break;
       }

    }while(choice!=0);
}