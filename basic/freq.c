#include<stdio.h>
void main()
{
int n,temp1,temp2,rem1,rem2,count;
printf("enter a number");
scanf("%d",&n);
temp1=n;
while(temp1>0)
{
  rem1=temp1%10;
  count=0;
  temp2=n;
  while(temp2>0)
  {
	rem2=temp2%10;
    if(rem1==rem2)
    {
   count++;
    }
   temp2 = temp2 /10;
  }
  printf("ferquncy %d = %d\n",rem1,count);
  temp1 = temp1/10;
}
}
