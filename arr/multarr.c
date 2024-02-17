#include<stdio.h>
int main ()
{  int ro,col;
  printf("enter row\n");
  scanf("%d",&ro);
  printf("enter col\n");
  scanf("%d",&col);
  int a[ro][col],b[ro][col],c[ro][col];
  int i,j,k;
  printf("enter elements a:");
   for(i=0;i<ro;i++)
     {
        for(j=0;j<col;j++)
        {
            scanf("%d",&a[i][j]);
        }

     }
     printf("enter elements b:");
  for(i=0;i<ro;i++)
     {
        for(j=0;j<col;j++)
        {
            scanf("%d",&b[i][j]);
        }

     }
   
     for(i=0;i<ro;i++)
     {
        for(j=0;j<col;j++)
          {  
            int sum=0;
            for(k=0;k<col;k++)

          {
            sum+=a[i][k]*b[k][j];
           }
           c[i][j]=sum;
         }
     }

     printf("multiplicatiom:\n");
     for(i=0;i<ro;i++)
     {
        for(j=0;j<col;j++)
        {
          printf(" %d",c[i][j]);
        }
        printf("\n");
     }
     



}