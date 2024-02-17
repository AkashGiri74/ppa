#include<stdio.h>
void main()
{
int i,n;
int a[10];
printf("enter how many element");
scanf("%d",&n);
printf("enter elements");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
 int sum=0;
for(i=0;i<n;i++)
{
sum=sum+a[i];
}
printf("sum is%d",sum);
}