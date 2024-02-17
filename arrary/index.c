#include<stdio.h>
void main()
{
int arr[100],i,n,search,flag;
printf("enter how many elements");
scanf("%d",&n);
printf("enter elemnts");

for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
printf("enter elements to search");
scanf("%d",&search);
if (flag=0);
for(i=0;i<n;i++)
{
if(search==arr[i])
{
	if (flag=1);
printf("%d element found at index %d",search,i);
break;

}

}
printf("elements not found");
}