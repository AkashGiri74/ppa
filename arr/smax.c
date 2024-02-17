// q 6
//second max 
#include <stdio.h>
int main()
 {
    int n, i;
    printf("Enter elements\n ");
    scanf("%d", &n);
    int a[n];
    printf("Enter elements\n");
    for (i = 0;i<n;i++)
     {
        scanf("%d",&a[i]);
      }

    
    int max = a[0];
    int secondmax = a[1];
    for(i=2;i<n;i++)
     {
        if (a[i]>max) 
        {
            secondmax = max;
            max = a[i];
        } 
        else if (a[i] > secondmax && a[i]<max) 
        {
            secondmax = a[i];
        }
    }
    printf("Second max %d\n", secondmax);
}
