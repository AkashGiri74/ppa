#include<stdio.h>
int main ()
{
  int a[10][10],b[10][10],d[10][10],r,c,i,j;
  printf("enter no of row\n");
  scanf("%d",&r);
  printf("enter no of c\n");
  scanf("%d",&c);

  printf("enter elements in a\n");
  for(i=0;i<r;i++)
    {  for(j=0;j<c;j++)
    {
    scanf("%d",&a[i][j]);

    }

    }
     printf("elements of A:\n");
  for(i=0;i<r;i++)
    {  for(j=0;j<c;j++)
      {
       printf("%d ",a[i][j]);
       
    }
printf("\n");
    }

  printf("enter elements in a\n");
  for(i=0;i<r;i++)
    {  for(j=0;j<c;j++)
    {
    scanf("%d",&b[i][j]);

    }

    }
     printf("elements of b:\n");
  for(i=0;i<r;i++)
    {  for(j=0;j<c;j++)
      {
       printf("%d ",b[i][j]);
       
    }
printf("\n");
    }

    for(i=0;i<r;i++)
    {  for(j=0;j<c;j++)
      {
       d[i][j]=a[i][j]+b[i][j];
       
    }
    }
    printf("adition \n");
  for(i=0;i<r;i++)
    {  for(j=0;j<c;j++)
      {
       printf("%d ",d[i][j]);
       
    }
printf("\n");
    }
}