//q 4
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
  int index,element;
  printf("enter the no where you want to insert elements\n");
  scanf("%d",&index);
  printf("enter elemnt yu want to insert\n");
  scanf("%d",&element);

  for(i=n-1;i>=index;i--)
  {
     a[i+1]=a[i];

  }n++;
  a[index]=element;

printf(" after enter  array\n");
  for(i= 0; i< n;i++)
  {
    printf("%d  ",a[i]);
  }





}