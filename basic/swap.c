#include<stdio.h>
void main()
{
int n1,n2,temp;
printf("enter n1\n");
scanf("%d",&n1);
printf("enter n2\n");
scanf("%d",&n2);
temp=n1;
n1=n2;
n2=temp;
printf("n1 = %d\n",n1);
printf("n2  = %d\n",n2);

}