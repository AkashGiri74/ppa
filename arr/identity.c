#include<stdio.h>
int main ()
{
  int a[3][3]={{ 1,1,8},
                { 2,1,7 },
                  {0,1,0}};
  
  int i,j;
  
 int flag=1;
  for(i=0;i<3;i++)
      {  for(j=0;j<3;j++)
        {
          if ( i==j && a[i][j]!=1  )
            {flag=0;
              break;
            }
          }
     } 
     if(flag)
        printf(" identity \n");
     else 
     printf(" not identity \n");
}