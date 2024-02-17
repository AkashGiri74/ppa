#include<stdio.h>
int min (int a,int b)
{
    return  ( a<b)?a:b;

}
int cs(int c[],int n)
{  if (n==0||n==1)//if n value is 0 or 1 reurn 0
  {
    return 0;
   }
return c[n-1]+min(cs(c,n-1),cs(c,n-2));//cureent positin //move one step ahed or two step ahed and its minimum

}
int  main ()
{
    int c[]={1,2,3,4,2},n;
    n=(sizeof(c)/sizeof(c[0]));
    printf("min cost %d",cs(c,n));
}