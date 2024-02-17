#include<stdio.h>
void main()
{
int n;
int first_dight;
int last_dight;
printf("enter no");
scanf("%d",&n);
last_dight=n%10;
while(n>=10)
{
n=n/10;
}
first_dight=n;
printf("first dight = %d\n last dight=%d\n",first_dight,last_dight);
}
