#include<stdio.h>
int waystoclimb(int n)
{
    if(n<=1)
        return 1;
    else
    return waystoclimb(n-1)+waystoclimb(n-2);
}
int main ()
{     int n;
    printf("enter no of stairs");
    scanf("%d",&n);
    printf("no of ways to reach the top %d",waystoclimb(n));
}