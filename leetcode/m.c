#include<stdio.h>
void main()
{
    int i;
    int n;
    int a[10];
     int sum=0;
     int sum1;
    printf("enter value of n");
    scanf("%d",&n);
    printf("enter elements");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        sum=sum+a[i];
    }
    sum1=(n*(n+1)/2);
    printf("missing number is %d",sum1-sum);
}