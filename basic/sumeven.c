#include<stdio.h>
void main()
{
int i;
int n;
int sum =0;
printf("enter a number ");
scanf("%d",&n);
for(i=0;i<=n;i++)
{
if(i%2==0)
{
sum = sum + i;
}
}
printf("sum of number %d ",sum);

}