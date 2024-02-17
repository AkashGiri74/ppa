#include<stdio.h>
void main()
{
int i,n,less=0,equal=0,greater=0;
int a[10];
printf("enter how many elements want to insert");
scanf("%d",&n);
printf("enter elements");
for(i=0;i<n;i++)
{
    scanf("%d",&a[i]);
}
 for(i=0;i<n;i++)
{
        if(a[i]>0)
    {
        greater++;
    }
    else if(a[i]<0)
    {
        less++;
    }
    else
    {
        equal++;
    }
}
printf("elements less than zero %d\n",less);
printf("elements greater than zero %d\n",greater);
printf("elements equal to zero%d\n",equal);

}