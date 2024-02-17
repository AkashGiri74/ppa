#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void input(int *,int);
void show(int *,int,const char* msg);
void bubble_sort(int *,int );
void swap(int *a,int *b);
void main ()
{
    int *a=NULL;
    int n;
    printf("enter no of elemnts:");
    scanf("%d",&n);
    if(n<=0)
    {
        printf("invalisd input\n");
        exit(EXIT_FAILURE);

    }
    a=(int *)malloc(n*sizeof(int));
    if(a==NULL)
    {
        printf("invalid allocation\n");
        exit(EXIT_FAILURE);
    }
    input(a,n);
     show(a,n,"before sort\n");
        bubble_sort(a,n);
         show(a,n,"after sort\n");
         free(a);
}
void input(int *a,int n)
{
    int i;
    printf("enter sorted array\n");
    for(i=0;i<n;i++)
    {  
        scanf("%d",&a[i]);
    }
}
void show(int *a,int n,const char* msg)
{
    int i;
    if(msg==NULL)
     puts(msg);
    for(i=0;i<n;i++)
    {
        printf("a[%d]=%d\n",i,a[i]);
    }
}
void bubble_sort(int *a,int n)
{  int flag;
    int i,itr;
for(itr=1;itr<n;itr++)#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void input(int *,int);
void show(int *,int,const char* msg);
void bubble_sort(int *,int );
void swap(int *a,int *b);
void main ()
{
    int *a=NULL;
    int n;
    printf("enter no of elemnts:");
    scanf("%d",&n);
    if(n<=0)
    {
        printf("invalisd input\n");
        exit(EXIT_FAILURE);

    }
    a=(int *)malloc(n*sizeof(int));
    if(a==NULL)
    {
        printf("invalid allocation\n");
        exit(EXIT_FAILURE);
    }
    input(a,n);
     show(a,n,"before sort\n");
        bubble_sort(a,n);
         show(a,n,"after sort\n");
         free(a);
}
void input(int *a,int n)
{
    int i;
    printf("enter sorted array\n");
    for(i=0;i<n;i++)
    {  
        scanf("%d",&a[i]);
    }
}
void show(int *a,int n,const char* msg)
{
    int i;
    if(msg==NULL)
     puts(msg);
    for(i=0;i<n;i++)
    {
        printf("a[%d]=%d\n",i,a[i]);
    }
}
void bubble_sort(int *a,int n)
{  int flag;
    int i,itr;
for(itr=1;itr<n;itr++)
   { flag=0;

    for(i=0;i<n-itr;i++)
    {
        if (a[i]>a[i+1])
        {
            swap(&a[i],&a[i+1]);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("array is alredy sorted no need iteration\n");
        break;
    }
   }
}
void swap(int *a,int *b)
{
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}
   { 
    
    for(i=0;i<n-itr;i++)
    {
        if (a[i]>a[i+1])
        {
            swap(&a[i],&a[i+1]);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("array is alredy sorted no need iteration\n");
        break;
    }
   }
}
void swap(int *a,int *b)
{
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}