//q 1
//stop when get palindrome number
#include <stdio.h>
int main() {
    int n,i;
    printf("Enter  how many elements \n");
    scanf("%d",&n);
    int a[n];
    printf("Enter elements \n");
    for ( i=0;i<n;i++) 
       {
        scanf("%d",&a[i]);
       }
    printf("Palindromes at positions: ");
    for (i=0;i<n;i++)
        {
            int original =a[i];
                int reverse=0;
               int temp=original;
        while (temp>0) 
        {
            reverse=reverse*10+temp%10;
            temp/=10;
        }

        if (original== reverse) 
          {
            printf("%d ",i+1); 
           }
    }
    


}
