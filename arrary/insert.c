#include<stdio.h>
# define Max 10
void insertionsort(int A[Max],int n)
{
int i,j,key;
for(i=1;i<n;i++)
{
key=A[i];
for(j=i-1;(j>=0)&&(key<A[j]);j--)

A[j+1]=A[j];
A[j+1]=key;

}
}
void main()
{
int A[Max],i,n;
printf("enter how many element wnat to  be sorted");
scanf("%d",&n);
printf("enter an elemnen");
for(i=0;i<n;i++)
scanf("%d",&A[i]);
insertionsort(A,n);
printf("elements after sorting are");
for(i=0;i<n;i++)
printf("%d",A[i]);
}