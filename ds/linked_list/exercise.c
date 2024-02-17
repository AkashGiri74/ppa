#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* createnode()
{
  struct node * newnode=NULL;
  int value;
  newnode=(struct node * )malloc(sizeof(struct node));
  if (newnode==NULL)
  {
    puts("error in memeory allocation");
    exit(EXIT_FAILURE);
  }
  printf("enter element:");
  scanf("%d",&value);
  newnode->data=value;
  newnode->next=NULL;
  return newnode;
}
void cratelinkedlist(struct node* *head)
{
   struct node * new_node;
   struct node* tempnode=*head;
    new_node=createnode();
    if(*head==NULL)
    {
      *head=new_node;
    }
    else
    {
        while(tempnode ->next!=NULL)
        {
          tempnode=tempnode->next;
        }
        tempnode->next=new_node;

    }
}
void displaylinkedlist(struct node* head)
{
   if (head==NULL)
     puts("linked list is empty");
   else
   { 
    while(head!=NULL)
    {
     printf("%d ",head->data);
     head = head->next;
    }
  }
  printf("\n\n");
}
// void displaylinkedlist(struct node* head)
// {
//   printf("%d ",head->data);
//   displaylinkedlist(head->next);

// }
void sort_asending(struct node* *head)
{
    struct node *tempnode=NULL;
    struct node *travnode=NULL;

     int temp;
    for(travnode=*head;travnode!=NULL;travnode=travnode->next)
    {  for(tempnode=travnode->next;tempnode!=NULL;tempnode=tempnode->next)
        {
            if(travnode->data > tempnode->data)
            {
                   temp=travnode->data;
                   travnode->data=tempnode->data;
                   tempnode->data=temp;
            }
        }
    }
    printf("sorted link list asending :");
    struct node *temp1=*head;
      while(temp1!=NULL)
      {
        printf("%d ",temp1->data);
          temp1=temp1->next;
      }
     
}
void sort_decending(struct node* *head)
{
    struct node *tempnode=NULL;
    struct node *travnode=NULL;

     int temp;
    for(travnode=*head;travnode!=NULL;travnode=travnode->next)
    {  for(tempnode=travnode->next;tempnode!=NULL;tempnode=tempnode->next)
        {
            if(travnode->data < tempnode->data)
            {
                   temp=travnode->data;
                   travnode->data=tempnode->data;
                   tempnode->data=temp;
            }
        }
    }
    printf("sorted link list decending:");
    struct node *temp1=*head;
      while(temp1!=NULL)
      {
        printf("%d ",temp1->data);
          temp1=temp1->next;
      }
     
}
int  search_element(struct node *head,int key)
{
    int position=1;
    while(head!=NULL)
    {
        if(head->data==key)
        {
            return position;
        }
        position++;
        head=head->next;
    }
    
    return -1;
}
void create_second_link_list(struct node* *head1)
{
   struct node * new_node;
   struct node* tempnode=*head1;
    new_node=createnode();
    if(*head1==NULL)
    {
      *head1=new_node;
    }
    else
    {
        while(tempnode ->next!=NULL)
        {
          tempnode=tempnode->next;
        }
        tempnode->next=new_node;

    }
    printf("\n second link list:");
    struct node *trav=*head1;
      while(trav!=NULL)
      {
        printf("%d ",trav->data);
        trav=trav->next;
      }
      printf("\n");
}
void merge_link_list(struct node* * head ,struct node * head1)
{
    if(*head==NULL)
    {
        *head=head1;
    }
    else
    {  
      
        struct node * travnode=*head;
        while(travnode->next!=NULL)
        {
            travnode=travnode->next;
        }
        travnode->next=head1;
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

void half_asending_half_decending(struct node **head)
{   int i,n;
     n=count_node(*head);
    struct node *currentnode=*head;
    struct node *previousnode = NULL;
    
    for (i = 0; i < n / 2; i++) {
        previousnode = currentnode;//mid fnd karnyasathi n/2 patyant gelyavar tyachi  prevoius node store karayachi 
        currentnode = currentnode->next;//for traverse 
    }

    
    previousnode->next = NULL;//separate
                        
    sort_asending(head); // Sort the first half in ascending order
    
                    
    sort_decending(&currentnode);// Sort the second half in descending order

    // Merge the sorted half back together
    struct node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = currentnode;

    printf("\n after half asending half decending  list:");
    struct node *trav=*head;
      while(trav!=NULL)
      {
        printf("%d ",trav->data);
        trav=trav->next;
      }
      printf("\n");
}

void replace_nodes(struct node **head, int position1, int position2) 
{   int temp,count,i,j;
    if (*head == NULL)
     {
        printf("Linked list is empty\n");
        return;
    }

    if (position1 == position2) 
    {
        printf("Positions should be different\n");
        return;
    }

     count = count_node(*head);
    if (position1 < 1 || position1 > count || position2 < 1 || position2 > count)
     {
        printf("Invalid positions\n");
        return;
    }

    if (position1 > position2) //jar pahili position mothi asel trrr 
    {
     temp = position1;
        position1 = position2;
        position2 = temp;
    }

    struct node *prev1 = NULL, *prev2 = NULL;//position chya adhicya node store karnya sathi..
    struct node *node1 = *head, *node2 = *head;//taverse purpoase and 
    
    for(i=1;i<position1;i++) 
    {
        prev1 = node1;//ji node replace hotiy tichta adhi chi node previous madhe takali
        node1 = node1->next;
    }
    for(i=1;i<position2;i++)
     {
        prev2=node2;//same position two sathi pnn
        node2=node2->next;
    }

    if (prev1!=NULL)
        prev1->next=node2;//previous 1 chya next la node 2 join keli
    else
        *head=node2;//jar link lis empty asel trr 

    if (prev2!=NULL)
        prev2->next=node1;//previous two chya next la node 1 jin keli
    else
        *head=node1;//jar link list empty asel trr 

    struct node *temp1=node1->next;///node 1 chi next node temprarly variable madhi store karayachi address harvu nahi manun
    node1->next=node2->next;//node 1 chya next node madhi node 2 chya next node takayachi
    node2->next=temp1;//ani node 2 chya next madhi node 1 madhi store kelela temproly node jo ki first node cha next hota to takayacha 
                      //address takayacha 

    printf("Nodes at positions %d and %d have been replaced\n", position1, position2);
}


int main ()
{ 
  int choice;
struct node *firstnode=NULL;
struct node *secondnode=NULL;
  do
 {
  printf("\n 1.create  1st link list\n");
  printf("\n 5.create second link list : press 5 \n");
  printf("2.display\n");
  printf("3.sort aseding\n");
  printf("4.search element \n");
  printf("6.merge link list \n");
  printf("7.half asending half decending\n");
  printf("8.replace nodes\n");
  printf("9.sort decending\n");
  printf("0.EXIT\n");
  printf("enter your choice : ");
  scanf("%d",&choice);
   
   switch(choice)
   {
    
    case 1:cratelinkedlist(&firstnode);
            break;
    case 2:displaylinkedlist(firstnode);
            break;
    case 3:sort_asending(&firstnode);
           break;
    case 4:{
            int position,key;
            printf("enter element to search:");
            scanf("%d",&key);
            position=search_element(firstnode,key);  
            if(position==-1)
             {
              printf("element not found");
             }
            else
            {
             printf("eleemnt found at postion %d",position);
            }
            }
             break;
    case 5:create_second_link_list(&secondnode);
        break;
    case 6:merge_link_list(&firstnode,secondnode);
        printf("success\n");
        break;
    case 7:half_asending_half_decending(&firstnode);
          printf("success\n");
          break;  
    case 8:{  int position1,position2;
      printf("enter position 1:");
      scanf("%d",&position1);
      printf("enter position 2:");
      scanf("%d",&position2);
      replace_nodes(&firstnode,position1,position2) ;
             
    }      break;   
    case 9:sort_decending(&firstnode);
       break;               
   }
 }while(choice !=0);

}