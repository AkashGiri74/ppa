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
// void create_link_List(struct node* *head)
// {
//     struct node * newnode=NULL;
//     struct node *tempnode=*head;
//     newnode=createnode();
//     if (*head==NULL)
//     {
//         *head=newnode;
//         (*head)->next=*head;
//     }
//     else
//     {
//         while(tempnode->next !=*head)
//         {
//             tempnode=tempnode->next;
//         } 
//         tempnode->next=newnode;
//         newnode->next=*head;
//     }




// }
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
        printf("link list is empty \n");
        return;
    }
    else{
    // {   struct node * tempnode=head;
    //         do
    //         {
    //             printf("%d ",tempnode->data);
    //             tempnode=tempnode->next;
    //         }
    //         while(tempnode!=head);

    
    }
    
}
void circular_or_not(struct node *head)
{
    struct node * tempnode=head;
    while(tempnode->next !=head)
    {
        tempnode=tempnode->next;
    }
    if(tempnode->next==head)
    {
        printf("link list is circular ");

    }
    else
    {
        printf("not circular ");
    }
}
int main ()
{  int choice;
    struct node* first_node=NULL;
    do
    { printf("1.create ");
       printf("2.dispaly ");
       printf("3.check circular or not ");
       printf("enter your choice ");

       scanf("%d",&choice);
       switch(choice)
       {
        case 1:create_link_List(&first_node);
             break;
        case 2:disaply_link_List(first_node);
        break; 
        case 3:circular_or_not(first_node);
        break;

        
       }

    }while(choice!=0);
}