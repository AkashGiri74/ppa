#include <stdio.h>
int main()
 {
    int n,a[10],i,j,count=0;
    printf("Enter how many elements\n ");
    scanf("%d", &n);
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
     

    for (int i = 0; i < n; i++)
     {
       count = 1;
        if (a[i] != -1) // Check if the element is counted already
         {
            for ( j = i+1; j < n; j++)
             {
                if (a[i] == a[j]) 
                {
                    count++;
                    a[j] = -1; // Mark the counted element to avoid counting it again
                }
            }

            printf("Frequency of %d = %d\n", a[i], count);
     }
}

}
