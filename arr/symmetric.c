#include<stdio.h>
int main ()
{
  int a[3][3]={{ 9,1,1},
                { 1,4,1 },
                  {1,1,9}};
  
  int i,j;
  
 int flag=1;
  for(i=0;i<3;i++)
      {  for(j=0;j<3;j++)
        {
          if ( a[i][j]!=a[j][i])
              {  flag=0;
              break;
              }
          }
          if(!flag)
            break;
     } 
     if(!flag)
        printf(" not symmetric \n");
     else 
     printf(" symmetric \n");
}