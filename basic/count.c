#include<stdio.h>
void main()
{
int count=0,n;
printf("enter a number");
scanf("%d",&n);
while(n!=0)
{
n=n/10;
count++;
}
printf("%d",count);


}