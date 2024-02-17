#include<stdio.h>
int max_profit(int weight[],int profit[],int current_item,int n,int capacity);
int max(int a ,int b);
int main ()
{
    int n=3;
    int capacity=4;
    int weight[]={1,2,3};
    int profit[]={4,5,1};
   int  Max=max_profit(weight,profit,0,n,capacity);
    printf("maximum profit is %d",Max);
}
int max_profit(int weight[],int profit[],int current_item,int n,int capacity)
{   int consider=0,no_consider=0;
    if(current_item==n)
      return 0;
    if(current_item<=capacity)
    consider=profit[current_item]+max_profit(weight,profit,current_item+1,n,capacity-weight[current_item]);
    no_consider=max_profit(weight,profit,current_item+1,n,capacity);
   return max(consider,no_consider);

}
int max(int a ,int b)
{
    return (a>b)?a:b;
}