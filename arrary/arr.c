#include<stdio.h>
void main()
{

int i,n;
int arr[100];
printf("enter how many elements do you want to insert");
scanf("%d",&n);
printf("emnter elements");
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
printf("elements are");
for(i=0;i<n;i++)
{
printf("arr[%d]=%d\n",i,arr[i]);
}
}