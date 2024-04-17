#include<stdio.h>

int total_ways(int nums[],int ci,int target,int n)
{    
  int postive_sign,negative_sign;
    if(ci==n && target==0)
    {
        return 1;
    }
    if(ci==n && target!=0)
    {
        return 0;
    }
    
  postive_sign=total_ways(nums,ci+1,target-nums[ci],n);
  negative_sign=total_ways(nums,ci+1,target+nums[ci],n);

  return postive_sign+negative_sign;



}
int main()
 {   int target,n,ways;
     int nums[] = {1, 1, 1, 1, 1};
     n = sizeof(nums) / sizeof(nums[0]);
     target= 3;
     ways = total_ways(nums,0, target, n);
     printf("Number of ways to reach the target sum: %d\n", ways);

 }