#include<stdlib.h>
#include<stdio.h>
struct node
{
    int vertex;
    struct node * next;
};
struct node* *adjacencylist;
  int noofvertices;

  struct node * createnode(int v)
  {
    struct node * newnode=(struct node *)malloc(sizeof(struct node));
       newnode->vertex=v;
       newnode->next=NULL;
       return newnode;
  }
int initializegraph(int vertices)
{   int i; 
     noofvertices=vertices;
     adjacencylist=malloc(vertices * sizeof(struct node));
     for(i=0;i<noofvertices;i++)
     {

     adjacencylist[i]=NULL;
     }

}
int addedge(int source,int destination)
{
    struct node * newnode=createnode(destination);
                     newnode->next=adjacencylist[source];
                     adjacencylist[source]=newnode;

                     //
                     newnode=createnode(source);
                     newnode->next=adjacencylist[destination];
                     adjacencylist[destination]=newnode;
}
int print()
{
    int i;
    for(i=0;i<noofvertices;i++)
    {  struct node * temp=adjacencylist[i];
       printf("v %d->",i);
       while (temp)
       {
          printf("%d->",temp->vertex);
          temp=temp->next;
       }
       printf("\n");
       

    }
}
int main ()
{
    initializegraph(5);
    addedge(0,1);
    addedge(0,4);
    addedge(1,2);
    addedge(3,2);
    addedge(2,4);
    printf("adjacency list are:\n");
    print();
}
