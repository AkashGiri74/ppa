// q 10 
#include <stdio.h>

int main() 
{
    int n,i;
    printf("Enter how many\n ");
    scanf("%d", &n);
    int a[n];
    printf("enter how many\n");
    for ( i=0;i<n;i++) 
        scanf("%d", &a[i]);
    
    int maxdiff = a[1] - a[0];
   
    int first = a[0];
   
    int second = a[1];
      int j,diff;
    for (i = 1;i<n;i++)
     {
        for (int j =i+1;j<n;j++)
         {
             diff = a[j] - a[i];
           
            if (diff > maxdiff)
             {
                maxdiff = diff;
                first= a[i];
                second= a[j];
            }
        }
    }

    
    printf(" elements  %d and %d have largest diff\n", first, second);

    
}
