#include<stdio.h>

int main() {
    int n, i;
    int a[100];
    int sum1 = 0, sum = 0;
    
    printf("Enter the value of n: ");
    scanf("%d", &n);
    
    printf("Enter elements: ");
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &a[i]);
           sum1 += a[i];
    }
    sum = (n * (n + 1) / 2);
    printf("Missing number: %d\n", sum - sum1);
    

}
