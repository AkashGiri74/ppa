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
// void insert_at_first(struct node ** head)
// {

// }
int search(struct node * head,int key)
{  
   int pos=1;
     while(head!=NULL)
     {  
        if (head->data==key)
        {
            return pos;
        }
        pos++;
        head=head->next;

     }
  return -1;
}

int main ()
{  int choice;
    struct node* first_node=NULL;
    do
    { printf("\n 1.create ");
       printf("2.dispaly ");
       printf("3.search \n");
    
       printf("enter your choice:");
       scanf("%d",&choice);
       switch(choice)
       {
        case 1:create_link_List(&first_node);
             break;
        case 2:disaply_link_List(first_node);
        break;
        case 3:{  int key,pos;
        printf("enter element you want to search");
        scanf("%d",&key);
        pos=search(first_node,key);
        if (pos==-1)
        {
            printf("element not fund");
        }
        else
        {
            printf("element found at pos %d",pos);
        }
          break; 
        }    
       }

    }while(choice!=0);
}