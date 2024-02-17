#include<stdio.h>
void main()
{
int n,ans=0,rem;
printf("enter number ");
scanf("%d",&n);
while(n>0)
{
rem= n %10;
ans = ans*10+rem;
n = n / 10;
}
printf("reverse no is %d",ans);
}