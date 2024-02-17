#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int input(int *a,int n)
{   int i;
    srand(time(0));
    for(i=0;i<n;i++)
    {
        a[i]=rand();
    }
}
int show(int *a,int n,char * msg)
{    int i;
     if(msg!=NULL)
      puts(msg);
      for(i=0;i<n;i++)
      {
        printf("a[%d]=%d\n",i,a[i]);
      }

}
void merge_proc(int *a,int p,int q ,int r)
{  int n1=(q-p)+1;
    int n2=r-q;
    int *a1=NULL,*a2=NULL;
    int i,j,k;
     a1=(int *)malloc(n1*sizeof(int));
       if (a1==NULL)
       {
        puts("erroer \n");
        exit(EXIT_FAILURE);
       }

       a2=(int *)malloc(n2*sizeof(int));
       if (a2==NULL)
       {
        puts("erroer \n");
        exit(EXIT_FAILURE);
       }
       for(i=0;i<n1;i++)
       {
        a1[i]=a[p+i];
       }
       for(i=0;i<n2;i++)
       {
        a2[i]=a[q+1+i];
       }
       i=0;j=0;k=0;
      while(i<n1 && j<n2)
      {     if(a1[i]<a2[j])
               {
                a[p+k]=a1[i];
                i++;
                k++;
               }
               else
               {
                a[p+k]=a2[j];
                j++;
                k++;
               }

      }
      while(i<n1)
        {  a[p+k]=a1[i];
           i++;
           k++;

        }
        while(j<n2)
        {  a[p+k]=a2[j];
           j++;
           k++;
        }
        free(a1);
        free(a2);

}
void mergesort(int *a,int low,int high)
{
    int mid;
    if(low<high)
    {
    mid=(low+high)/2;
    mergesort(a,low,mid);
    mergesort(a,mid+1,high);
    merge_proc(a,low,mid,high);
   }
}
int main ()
{
    int *a=NULL;
    int n;
    printf("enter value of n");
    scanf("%d",&n);
    if (n<=0)
    {
        puts("errr\n");
        exit(EXIT_FAILURE);
    }
    a=(int *)malloc(n*sizeof(int));
    if(a==NULL)
    {
        puts("erroe in memory allocatiob");
        exit(EXIT_FAILURE);
    }
    input(a,n);
    show(a,n,"before sort\n");
    mergesort(a,0,n-1);
     show(a,n,"after sort\n");
     free(a);
     exit(EXIT_SUCCESS);

}