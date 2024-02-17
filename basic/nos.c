#include<stdio.h>
void main()
{
int n,i;
int ans=0;
printf("enter value of n");
scanf("%d",&n);
for(i=1;i<=10;i++)
{
 ans=n*i;
 printf("%d * %d = %d\n",n,i,ans);
}
}
