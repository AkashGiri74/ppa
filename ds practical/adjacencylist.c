#include<stdio.h>
#include<stdlib.h>
struct node
{
    int vertex;
    struct node * next;
};
int no_ofvertices;
struct node* *adjacencylist;

struct node * createnode(int v)
{
    struct node * newnode=(struct node *)malloc(sizeof(struct node ));
    newnode->vertex=v;
    newnode->next=NULL;
    return newnode;

}
int initializegraph(int vertices)
{     no_ofvertices=vertices;
      adjacencylist=malloc(vertices * sizeof(struct node *));
      for(int i=0;i<vertices;i++)
      {
     adjacencylist[i]=NULL;
      }
}
int addedge(int source,int destination)
{  struct node * newnode=createnode(destination);
    newnode->next=adjacencylist[source];
    adjacencylist[source]=newnode;

    newnode=createnode(source);
    newnode->next=adjacencylist[destination];
    adjacencylist[destination]=newnode;

}
int print()
{
    for(int i=0;i<no_ofvertices;i++)
    {  struct node * temp=adjacencylist[i];
        printf("vertex %d ",i);
        while(temp)
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
    addedge(0,3);
    addedge(1,0);
    addedge(1,2);
    addedge(3,1);
    addedge(1,4);
    print();

}