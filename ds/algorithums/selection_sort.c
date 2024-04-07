#include<stdio.h>

int  slection_sort(int arr[],int n)
{   int i,j,position;
    for(i=0;i<(n-1);i++)
    {    position=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[position]>arr[j])
            position=j;
        }
    
    if(position!=i)
    {
        int tmp=arr[i];
        arr[i]=arr[position];
        arr[position]=tmp;
    }
    }
}
void display(int arr[],int n,char * msg)
{
    if(msg!=NULL)
    puts(msg);
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
int main ()
{   int n,arr[10];
    printf("enter how many elements:");
    scanf("%d",&n);
    printf("enter element to sort :");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    display(arr,n,"before sort");
    slection_sort(arr,n);
    display(arr,n,"\nafter sort");

}