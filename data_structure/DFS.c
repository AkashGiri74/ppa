// #include<stdio.h>
// int dfs(m,n,w);
// void main()
// {
//  int m[5][5]={{0,0,1,1,0},{0,0,1,0,1},{0,1,0,0,0},{0,0,0,0,1},{0,0,0,0,0}};
// //  {{0,1,0}, {0,0,1}, {1,0,0}};
 
//  printf("\n The depth first search traversal is:");
//  dfs(m,3,0);
// }
// int dfs(int m[6][6], int n, int v)
// {
//  int w;
//  static int visited[20]={0};
//  visited[v]=1;
//  printf("V%d", v+1);
//  for(w=1; w<=n; w++)
//  {
//   if((m[v][w]==1)&&(visited[w]==0))
//      dfs(m,n,w);
// }
// }
#include <stdio.h>

void dfs(int m[5][5], int n, int v, int visited[5]);

int main() {
    int m[5][5] = {{0, 0, 1, 1, 0},
                   {0, 0, 1, 0, 1},
                   {0, 1, 0, 0, 0},
                   {0, 0, 0, 0, 1},
                   {0, 0, 0, 0, 0}};
    int visited[5] = {0}; // Initialize visited array
    printf("The depth-first search traversal is: ");
    dfs(m, 5, 0, visited); // Start DFS from vertex 0
    printf("\n");
    return 0;
}

void dfs(int m[5][5], int n, int v, int visited[5]) {
    int w;
    visited[v] = 1; // Mark vertex as visited
    printf("V%d ", v + 1); // Print visited vertex
    for (w = 0; w < n; w++) {
        if (m[v][w] == 1 && visited[w] == 0) { // Check adjacency and unvisited
            dfs(m, n, w, visited); // Recursive call for adjacent unvisited vertex
        }
    }
}
