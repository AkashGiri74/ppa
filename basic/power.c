#include<stdio.h>
void main()
{
int i,base,exp,ans=1;
printf("enter base");
scanf("&d",&base);
printf("enter exp");
scanf("%d",&exp)
for(i=1;i<exp;i++)
{
     ans = ans* base;
}
     printf("ans is %d",ans);
}

