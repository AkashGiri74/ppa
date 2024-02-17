#include<stdio.h>
int main ()
{
  int a[3][3]={{ 1,0,0},
                { 0,4,0  },
                  {1,0,1}};
  
  int i,j;
  
 int flag=1;
  for(i=0;i<3;i++)
      {  for(j=0;j<3;j++)
        {
          if (i<j && a[i][j]!=0)
            {    flag=0;
              break;
            }
          }
     } 
     if(flag)
        printf("lower triangular \n");
     else 
     printf("not lower\n");
}