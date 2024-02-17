#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int input(int *a,int n)
{
    srand(time(0));
    for(int i=0;i<n;i++)
    { 
        a[i]=rand();
    }
}
int show(int *a,int n,char * msg)
{
    if (msg!=NULL)
puts(msg);
for(int i=0;i<n;i++)
{
    printf("a[%d]=%d\n",i,a[i]);
}
}
int quick_sort(int *a,int p,int r)
{   int q;
    if(p<r)
    {
       q=partition(a,p,r);
       quick_sort(a,p,q-1);
       quick_sort(a,q+1,r);
    }

}
int partition(int *a,int p,int r)
{ int i=p-1;
int pivot=a[r];
int j ,temp;
   for(j=p;j<r;j++)
   {
    if(a[j]<pivot)
    {
        i++;
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
   }
   temp=a[i+1];
   a[i+1]=a[r];
   a[r]=temp;

   return(i+1);
}
int main ()
{    time_t start_time,end_time,delta_time;
   int *a=NULL;
    int n;
    printf("enter elements ");
    scanf("%d",&n);
    if(n<=0)
    {
        puts("errr");
        exit(EXIT_FAILURE);
    }
    a=(int *)malloc(n*sizeof(int));
    if (a==NULL)
    {
        puts("error in memory allocation");
        exit(EXIT_FAILURE);
    }
    input(a,n);
    show(a,n,"before sort");
    start_time=time(0);
    quick_sort(a,0,n-1);
    end_time=time(0);
      show(a,n,"after sort\n");
      printf("required time is %ld",end_time-start_time);
      free(a);
}