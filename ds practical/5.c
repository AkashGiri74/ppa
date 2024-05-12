#include<stdio.h>
#include<stdlib.h>
typedef struct 

{
    int data[20];
    int front,rear;
}QUEUE;
int init(QUEUE * pq)
{
    pq->front=pq->rear=-1;
}
int addq(QUEUE *pq,int n)
{
    pq->data[++(pq->rear)]=n;
}
int removeq(QUEUE *pq)
{
    return pq->data[++(pq->front)];
}
int isempty(QUEUE * pq)
{
return pq->front==pq->rear;
}

void bfs(int m[5][5],int n)
{    static int visited[20]={0};
    int v=0;
    QUEUE q;
    init(&q);
    printf("dfs traversal of the tree :");
     visited[v]=1;
     addq(&q,v);

     while(!isempty(&q))
     {
        v=removeq(&q);
        printf(" v%d ->",v+1);
        int w;
        for(w=0;w<n;w++)
        {
            if((m[v][w]==1) && (visited[w]==0))
            {
                addq(&q,w);
                visited[w]=1;
            }
        }

     }

}
int main ()
{
    int m[5][5]={{0,0,0,0,1},{1,0,0,0,1},{0,0,1,0,1},{0,1,0,0,1},{0,0,1,0,1}};
    bfs(m,5);
}