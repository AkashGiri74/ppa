#include<stdio.h>
void main()
{
int j,i,n;
int a[10];
int temp=0;
printf("enter how many elements");
scanf("%d",&n);
for(i=0;i<n;i++)
scanf("%d",&a[i]);
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{if (a[i]>a[j])
	{
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}
}
printf("assending order is");
for(i=0;i<n;i++)
printf("%d\t",a[i]);	
}