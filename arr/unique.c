//q 3
//unique
#include <stdio.h>
int main()
 {
    int n,i,j;
    printf("Enter how many\n");
    scanf("%d", &n);
    int a[n];
    printf("Enter elements\n");
    for (i=0;i<n;i++) 
    {
        scanf("%d",&a[i]);
    }
    printf("Unique elements in the array\n");
    for (i=0;i<n;i++)
     {
        int Unique=1;
        for (j=0;j<i;j++) 
        {
            if (a[j]==a[i]) 
            {
                Unique=0;
                break;
            }
        }
        if (Unique==1) 
        {
            printf("%d\n",a[i]);
        }
    }

}
