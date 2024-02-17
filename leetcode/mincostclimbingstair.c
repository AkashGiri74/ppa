//minimum cost to climbing stair problem 
#include<stdio.h>
int min(int a,int b)
{
    return(a<b)?a:b;
}
int cs(int c[],int n)
{
   if(n==0||n==1)
   {
    return 0;
   }

   return c[n-1]+min(cs(c,n-1),cs(c,n-2));
}
int main ()
{ int c[]={10,15,20,1,3},n=6;
  printf("min cost to reach top %d ",cs(c,n));
   

}
