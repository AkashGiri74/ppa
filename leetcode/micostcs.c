#include<stdio.h>
int min(int a ,int b)
{
    return (a<b)?a:b;
}
int cs(int stair[],int n)
{  if (n==0 ||n==1)
   {
     return 0;
   }
   return stair[n-1]+min(cs(stair,n-1),cs(stair,n-2));

}
int main ()
{
    int stair[]={10,23,1,7,4,19,34,56,1};
    int n=(sizeof(stair))/(sizeof(stair[0]));
    printf("min cost to reach top  %d",cs(stair ,n));
    
} //  0   1  2   3   4
//   10  23  1  7    4 
              //   return stair[n-1]  //we need to count the value of last step // 1+
              //we eiher move one step forward or two step
              //minimum of (n-1) one step back or (n-2) two step back          // 34+
              //minimum of (n-1) one step back or (n-2) two step back          //4+
               //minimum of (n-1) one step back or (n-2) two step back         //+1                                                                //1
                                                                               //=40