//q 7
#include<stdio.h>
int main ()
{
  int n,i;
  printf("enter how many element\n");
  scanf("%d",&n);
  int a[n];
  printf("enter elemts in array\n");
  for(i= 0; i< n;i++)
  {
    scanf("%d",&a[i]);
  }
  
  printf("the no \\ 7   ! 5 are\n");

  for(i=0;i<n;i++)
  {  
    if (a[i]%7==0 && a[i]%5!=0)
      printf("%d  ",a[i]);

  }



}