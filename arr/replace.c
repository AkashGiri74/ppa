// q 8
#include <stdio.h>

int main()
 {
    int n,i;

    printf("Enter elemnts\n");
    scanf("%d", &n);
    int a[n];
    printf("Enter elemmts\n");
    for (i=0;i<n;i++) 
    {
        scanf("%d", &a[i]);
    }
       
       for (i = 0; i < n;i++) 
       { 
        if (a[i] % 2 != 0)
         {
            int original = a[i];
            int reverse = 0;

        
            while (original> 0)
             {
                reverse= reverse* 10 + original % 10;
                original/= 10;
            }

            a[i] = reverse;
        }
       }
    
    
    printf("elemnts are after reverse\n");
    
    for( i = 0; i < n;i++)
     {
        printf("%d\n", a[i]);
    }

}
