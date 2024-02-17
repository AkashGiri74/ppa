#include<stdio.h>
void main()
{
int n1,n2 ,max;
printf("enter a number1 and number 2");
scanf("%d %d",&n1,&n2);
max = (n1>n2)? n1 : n2;
while(1)
{
if(max % n1 ==0 && max %n2 ==0)
{
    printf("lcm of %d and %d = %d",n1,n2,max);
   break;
}
max++;
}

} 