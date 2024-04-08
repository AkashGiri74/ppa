#include<stdlib.h>
#include<stdio.h>
int main ()
{
 int** ptr=NULL;
 int row, col, i, j;
 printf("enter no of rows\n");
 scanf("%d", &row) ;
  ptr=(int *)malloc (row sizeof(int*));
  
  printf("chal number tak\n");
  scanf("%d",&col);
  for(i=0;i<row;i++) 
  {
  *(ptr+i)=(int *) malloc(col*sizeof(int)) ;
  }
  
  
  printf("enter elements\n");
  for(i=0;i<row;i++) 
  { for(j=0;j<col;j++)
     {
      scanf("%d",*(ptr+i)+j);
     }
  }
  printf("elements are \n");
  for(i=0;i<row;i++) 
  { for(j=0;j<col;j++)
     {
      printf("%d ",((ptr+i)+j) );
     }
     printf("\n");
  }
  
}
