#include<stdio.h>
#include<stdlib.h>
void main ()
{
    int m[3][3]={{0,0,1},{1,0,0},{1,0,1}};
    printf("dfs travesrasal of the tree");
    dfs(m,3,0);
}
int dfs(int m[3][3],int n,int v)
{   int w;
   static int visited[20]={0};
      
     visited[v]=1;

     printf("v%d",v+1);

     for( w=0;w<n;w++)
     {
        if((m[v][w]==1) && (visited[w]==0))
        {
          dfs(m,n,w);
        }
     }
}
// int main ()
// {
//     int m[3][3]={{0,0,1},{1,0,0},{1,0,1}};
//     printf("dfs travesrasal of the tree");
//     dfs(m,3,0);
// }