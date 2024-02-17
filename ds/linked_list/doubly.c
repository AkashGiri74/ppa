#include<stdio.h>
#include<stdlib.h>
struct node
{    struct node *prev;
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
    new_node->prev=NULL;//for two compatment that is previous and next 
    new_node->data=value;
    new_node->next=NULL;
    return new_node;
}
void create_link_List(struct node* *head,struct node * *tail)
{
    struct node * newnode=NULL;
    struct node *tempnode=*head;
    newnode=createnode();
    if (*head==NULL && *tail==NULL  )
    {
        *head=*tail=newnode;//if there is only one node 
    }
    else
    {
        (*tail)->next=newnode;//shevtchya node chya next madhi newnode
        newnode->prev=*tail;//navin node chya prev madhi shevtachya node cha address
        *tail=newnode;//navin node la last node manayacha

    }

}
void disaply_forward_link_List(struct node * head)
{
    if(head==NULL)
    {
        printf("link list is empty");
        return;
    }
    while(head!=NULL)
    {
    printf("%d ",head->data);
    head=head->next;
    }
}
void disaply_backward_link_List(struct node * tail)
{
    if(tail==NULL)
    {
        printf("empty");
    }
    else{
        while(tail!=NULL)
        {
            printf("%d ",tail->data);
            tail=tail->prev;
        }
    }
}
void insert_at_first(struct node **head,struct node **tail)
{
        struct node * newnode=NULL;
        newnode=createnode();
    if(*head==NULL && *tail==NULL)
    {
        *head=*tail=newnode;
    }
    else
    {
           newnode->next=*head;
           (*head)->prev=newnode;
           *head=newnode;    
    }
}
void insert_at_last(struct node **head,struct node **tail)
{
    create_link_List(head,tail);
}
int countnode(struct node *head)
{
    int count;
    while(head!=NULL)
    {
        count ++;
        head=head->next;
    }
    return count;
}
void insert_at_pos(struct node **head,struct node ** tail)
{
    int pos,n;
    puts("enter position");
    scanf("%d",&pos);
   n=countnode(*head);  
   if(pos==1)
   {
    insert_at_first(head,tail);
   }
    else if(pos==n+1)
    {
        insert_at_last(head,tail);
    }
    else if (pos <1 || pos >n+1)
    {
        printf("invalid pos ");
        insert_at_pos(head,tail);
    }
    else
    {
        struct node * new_node=createnode();
        struct node *travnode=*head;
        for(int i=1;i<pos;i++)
        {
            travnode=travnode->next;

        }
        new_node->prev=travnode->prev;
        new_node->next=travnode;
        travnode->prev->next=new_node;
        travnode->prev=new_node;
    }
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
}
void delete_at_first(struct node ** head,struct node ** tail)
{  if(*head==NULL && *tail==NULL)
{
    puts("link list is emepty ");
    return;
}
else if((*head)->next==NULL)
{
    free(*head);
    *head=*tail=NULL;
}
struct node * tempnode=*head;
*head=(*head)->next;
(*head)->prev=NULL;
free(tempnode);

}
void delete_at_last(struct node **head,struct node **tail)
{ if (*head==NULL && *tail==NULL)
{
    printf("error in memeory allocation ");
    return;
}
else if ((*tail)->prev==NULL)
{  free(*tail);
  *head=(*tail)=NULL;

}
else
{
    struct node *tempnode=*tail;
    *tail=(*tail)->prev;//shevtchya node chya adhicha node
    (*tail)->next=NULL;//ani mgg tyacaha next null
    free(tempnode);//delete shevtacha node
}

}
void delete_at_pos(struct node **head,struct node ** tail)
{
    int pos,n;
    printf("enter value of position ");
    scanf("%d",&pos);
    n=countnode(*head);
    if(pos==1)
    {
        delete_at_first(head,tail);
    }
    else if(pos==n)
    {
        delete_at_last(head,tail);
    }else if (pos >n || pos <1)
    {  puts("invalid value for delete at pos ");
         delete_at_pos(head,tail);
    }
    else
    {
        struct node *tavnode=*head;
        for(int i=1;i<pos;i++)
        { 
            tavnode=tavnode->next;
        }
        tavnode->prev->next=tavnode->next;
        tavnode->next->prev=tavnode->prev;
        free(tavnode);
    }

}
int search (struct node * head,struct node * tail)
{
    int search_data,falg=0,index=0;
    printf("eneter eleement to search ");
    scanf("%d",&search);
    do{
        if(head->data ==search_data || tail->data==search_data)
        {  index ++;
            falg=1;
            printf("element found at index %d ",index );
            break;
        }
        else
        {
            head=head->next;
            tail=tail->prev;
        }
    }
    while(head->prev !=tail->next);
    if(falg==0)
    {
        printf("element  not found");
    }

    
}


int main ()
{  int choice;
    struct node* first=NULL;
    struct node* last=NULL;
    do
    { printf("1.create ");
       printf("2.dispaly  forward link list ");
       printf("3.display backward link list ");
       printf("4.insert first ");
       printf("5.insert last ");
       printf("6.insert at position\n ");
       printf("7.delete at first ");
       printf("8.delete at last ");
       printf("9.dlete at pos ");
       printf("10.search ");
       printf("enter your choice:");
       
       scanf("%d",&choice);
       switch(choice)
       {
        case 1:create_link_List(&first,&last);
             break;
        case 2:disaply_forward_link_List(first);
        break; 
        case 3:disaply_backward_link_List(last);
        break; 
        case 4:insert_at_first(&first,&last);
        break;
        case 5:insert_at_last(&first,&last);
        break;
        case 6:insert_at_pos(&first,&last);  
          break;
         case 7:delete_at_first(&first,&last);
         break;
         case 8:delete_at_last(&first,&last);
         break;
         case 9:delete_at_pos(&first,&last);
         break;
         case 10:search(first,last);
           break;
       }
    }while(choice!=0);
}
