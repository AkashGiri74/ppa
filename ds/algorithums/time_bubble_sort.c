#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void input(int *,int );
void show(int *,int ,const char* msg);
void bubble_sort(int* ,int );
void swap(int *,int *);
void main()
{  time_t start_time,end_time,delta_time;
   int *a=NULL;
   int n;
   printf("enter how many eleemnts\n");
   scanf("%d",&n);
   if(n<0)
   {
    puts("ivalid input");
    exit(EXIT_FAILURE);
   }
   a=(int *)malloc(n*sizeof(int));
   if( a==NULL)
   {
    puts("wrong memory allocation");
    exit(EXIT_FAILURE);
   }
   input(a,n);
   show(a,n,"before sort\n");
   start_time=time(0);
   bubble_sort(a,n);
   end_time=time(0);
   show(a,n,"after sort\n");
   printf("required time is %ld",end_time-start_time);
   
   free(a);

}
void input(int *a,int n)
{
    int i;
    srand(time(0));
    for(i=0;i<n;i++)
    {
        a[i]=rand();
    }
}
void show(int *a,int n ,const char* msg)
{ int i;
  if(msg==NULL)
  puts(msg);
   for(i=0;i<n;i++)
   {
    printf("a[%d]=%d\n",i,a[i]);
   }

}
void bubble_sort(int* a ,int n )
{
    int i,itr;
   for(itr=1;itr<n;itr++)
   { for(i=0;i<n-itr;i++)
    {
        if (a[i]>a[i+1])
        {
            swap(&a[i],&a[+1]);
        }
    }
   }
}
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}