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
int countnode(struct node * head)
  {
   int count=0;
   while(head!=NULL)
   {
    count++;
    head=head->next;
   }
   return  count;

  }
void replace_nodes(struct node ** head,int pos1,int pos2)
{   int count,temp,i;
    if(*head==NULL)
    {
        printf("link list is empty");
        return;
    }
    if(pos1==pos2)
    {
        printf("same position");
    }

    count=countnode(*head);
    if(pos1 >count || pos1 < 1 || pos2>count || pos2 <1 )
    {
        printf("invalid postion \n");
        return;
    }
    if(pos1 >pos2)
    {
        temp=pos1;
        pos1=pos2;
        pos2=temp;
    }

    struct node * previous1=NULL;
    struct node * node1=*head;
    for(i=1;i<pos1;i++)
    {
        previous1=node1;//find previous node of positon 1
        node1=node1->next;
    }

    struct node *previous2=NULL;
    struct node *node2=*head;
    for(i=1;i<pos2;i++)
    {
        previous2=node2;//find previous node of position 2
        node2=node2->next;
    }

    if(previous1!=NULL)
    {
        previous1->next=node2;
    }
    else 
    *head=node2;
    
    if(previous2!=NULL)
    {
        previous2->next=node1;
    }
    else
    *head=node2;

   struct node * tempnode1=node1->next;
   node1->next=node2->next;
   node2->next=tempnode1;


}

int main ()
{  int choice;
    struct node* first_node=NULL;
    do
    { printf(" \n 1.create ");
       printf("2.dispaly ");
       printf("3.replace nodes \n");
       printf("0.exit\n");
       printf("enter your choice:");
       scanf("%d",&choice);
       switch(choice)
       {
        case 1:create_link_List(&first_node);
             break;
        case 2:disaply_link_List(first_node);
        break; 
        case 3:{  int pos1, pos2;
                 printf("enter postion 1:");
                 scanf("%d",&pos1);
                 printf("ennter position 2:");
                 scanf("%d",&pos2);
            replace_nodes(&first_node,pos1,pos2);
            }break;    
       }

    }while(choice!=0);
}