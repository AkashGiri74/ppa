//q 2
//COPY
#include <stdio.h>
int main() {
    int n,i;
    printf("Enter how many\n ");
    scanf("%d", &n);
    int arr1[n];
    int arr2[n];
    printf("Enter elements \n");
    for (i=0;i<n;i++) 
    {
        scanf("%d",&arr1[i]);
    }
    for (i=0;i<n;i++) 
    {
        arr2[i] = arr1[i];
    }
    printf("Elements of the second array \n");
    for (i=0;i<n;i++)
     {
         printf("%d", arr2[i]);
     }
    
}
