#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int input(int *a,int n)
{  int i;
    srand(time(0));
    for(i=0;i<n;i++)
    {
        a[i]=rand();
    }
}
int show(int *a,int n,const char * msg)
{  
    int i;
    if (msg!=NULL)
      puts(msg);
    for(i=0;i<n;i++)
    {
        printf("a[%d]=%d\n",i,a[i]);
    }
}
int swap(int *a,int *b)
{
    int temp=*a;
         *a=*b;
         *b=temp;
}
int bubble_sort(int *a,int n)
{
    int itr,i,flag=0;
    for(itr=1;itr<n;itr++)
    {  flag=0;
    for(i=0;i<n-itr;i++)
      {  if (a[i]>a[i+1])
        {
        swap(&a[i],&a[i+1]);
        flag=1;
        }
     }
     if (flag==0)
       {
        printf("no more iterations required\n");
        break;
      }
    }
}
int binary_search(int *a,int low,int high,int search)
{  
    
    if(low<=high)
    {    
      int  mid=(low+high)/2;
        if(search==a[mid])
        return mid;
        if(search<a[mid])
        return binary_search(a,low,mid-1,search);
        if(search>a[mid])
        return binary_search(a,mid+1,high,search);
    }
    return -1;

}

int main ()
{
    int *a=NULL;
    int n;
    int search;
    int index;
    printf("enter how many elements \n");
    scanf("%d",&n);
    if(n<=0)
    {
        printf("invalid input\n");
        exit(EXIT_FAILURE);
    }
    a=(int *)malloc(n*sizeof(int *));
    if(a==NULL)
    {
        printf("error in memeory allocation\n");
        exit(EXIT_FAILURE);
    }
     input(a,n);
     show(a,n,"before bubble_sort\n");
     bubble_sort(a,n);
     show(a,n,"after bubble_sort\n");
     printf("enter elements for search:");
     scanf("%d",&search);
    index= binary_search(a,0,n-1,search);
     if (index==-1)
     {
        printf("elemnent not found \n");
     }
     else
     {
       printf("element found at index %d",index);
     }

     free(a);
    exit(EXIT_SUCCESS);
}