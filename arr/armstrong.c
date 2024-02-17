// q 5
//armstrong
#include<stdio.h>
int main ()
{   int n;
    printf("how many \n");
    scanf("%d",&n);
    int a[n];
    printf("enter elements\n");
    int i;
    for(i=0;i<n;i++)
      scanf("%d",&a[i]);
      printf("arm no\n");
      for(i=0;i<n;i++)
      {
          int num=a[i];
          int num1=num;
          int sum=0;
            while(num1!=0)
             {  int digit=num1%10;
                  sum=sum+digit*digit*digit;
                  num1/=10;
             }
        
          if (num==sum)
          printf("%d  ",num );

      }


}