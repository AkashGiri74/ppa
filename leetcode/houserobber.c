#include<stdio.h>
int max(int a,int b);
int maximum_money (int nums[],int current_home,int n);
int main ()
{
    int nums[]={2,7,9,3,1};
    int n=5;

    printf("maximum money %d",maximum_money(nums,0,n));
}
int maximum_money (int nums[],int current_home,int n)
{  int rob,not_rob;
    if(current_home>=n)
         return 0;
    else    
        rob=nums[current_home]+maximum_money(nums,current_home+2,n);
        not_rob=maximum_money(nums,current_home+1,n);
        return max(rob,not_rob);
}
int max(int a,int b)
{
    return a>b?a:b;
}
