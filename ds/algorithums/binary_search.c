#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int input (int *a,int n);
int show(int *a,int n,const char* msg);
void bubble_sort(int *a,int n);
void swap(int *a,int *b);
int binary_search(int *a,int low,int high,int search);
int main()
{  int *a=NULL;
    int n;
    int search,index;
    printf("enter n value:");
    scanf("%d",&n);
    if(n<=0)
    {
        puts("input invalid");
        exit(EXIT_FAILURE);
    }
    a=(int *)malloc(n*sizeof(int));
    if(a==NULL)
    {
        puts("error in memoery alocation");
        exit(EXIT_FAILURE);
    }
    input(a,n);
   show(a,n,"before search");
   bubble_sort(a,n);
   show(a,n,"after bubble sort");
   puts("enter searching element\n");
   scanf("%d",&search);
  index= binary_search(a,0,n-1,search);
  if (index==-1)
  {
    puts("element not found");

  }
  else
  {
    printf("element found at index %d",index);
  }
  free(a);
  exit(EXIT_SUCCESS);

}
int input (int *a,int n)
{ int i;
  srand(time(0));
  for(i=0;i<n;i++)
  {
    a[i]=rand();
  }

}
int show(int *a,int n,const char* msg)
{ int i;
    if (msg!=NULL)
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
int binary_search(int *a,int low,int high,int search)
{   int mid;
if(low<=high)
  {
    mid=(low+high)/2;
    
      if(search==a[mid])
        return mid;
      if(search <a[mid])
        return binary_search(a,low,mid-1,search);
      if(search>a[mid])
        return binary_search(a,mid+1,high,search);


    }
}