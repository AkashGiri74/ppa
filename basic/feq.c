#include<stdio.h>
void main()
{
int i,n,k,s,j;
int sum=0,temp=0,count=0;
int a[10];

printf("Enter no. of elements");
scanf("%d",&n);
printf("Enter array elements\n");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}//scan
printf("\n array elements are\n");
for(i=0;i<n;i++)
{
printf("%d\t",a[i]);
}//print
//start counting
for(i=0;i<n;i++)
{
    count=0;
for (j=0;j<n;j++)
{
    if(a[i]==a[j])
    {
        count++;
    }
}
printf("\n%d comes %d times",a[i],count);
}
}