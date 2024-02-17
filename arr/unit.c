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
     printf("matrix \n");
   for(i=0;i<ro;i++)
     {
        for(j=0;j<col;j++)
        {
            printf("%d ",a[i][j]);
        } printf("\n");

     }
     int flag=1;
     for(i=0;i<ro;i++)
     {
        for(j=0;j<col;j++)
        {
          if (a[i][j]!=1)
          {
             flag=0;
             break;

          }
        }
     }
     if (flag)
      printf(" is unit \n");
    else
      printf(" is not unit\n");
}