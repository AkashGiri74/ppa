#include<stdio.h>
int main ()
{  int ro,col;
  printf("enter row\n");
  scanf("%d",&ro);
  printf("enter col\n");
  scanf("%d",&col);
  int a[ro][col];
  int i,j;
  printf("enter elements a:");
   for(i=0;i<ro;i++)
     {
        for(j=0;j<col;j++)
        {
            scanf("%d",&a[i][j]);
        }

     }

     int sum=0;
  for(i=0;i<ro;i++)
     {
        for(j=0;j<col;j++)
        {
         sum+=a[i][j];
        }

     }
     printf("sum is %d",sum);
}