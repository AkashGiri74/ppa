// q 9
//delete
#include<stdio.h>
int main ()
{ int n,i;
printf("enter how many elements\n");
scanf("%d",&n);
int a[n];
printf("enter elements in array\n");
for(i=0;i<n;i++)
  {
  scanf("%d",&a[i]); 
  }
    int index;
  printf("enter the index where you want to delete\n");
  scanf("%d",&index);
  for(i=index+1;i<=n-1;i++)
      {
        a[i-1]=a[i];
      } n--;

printf("after delete\n");
for(i=0;i<n;i++)
  {
  scanf("%d",&a[i]); 
  }


}