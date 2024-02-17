#include <stdlib.h>
#include <stdio.h>

int main()
{
    int ***ptr = NULL;
    int dim1, dim2, dim3, i, j, k;
    printf("Enter the number of dimensions (dim1 dim2 dim3): ");
    scanf("%d %d %d", &dim1, &dim2, &dim3);

    // Memory allocation
    ptr = (int ***)malloc(dim1 * sizeof(int **));
    for (i = 0; i < dim1; i++)
    {
        * (ptr + i) = (int **)malloc(dim2 * sizeof(int *));
        for (j = 0; j < dim2; j++)
        {
          * ( * (ptr + i) + j) = (int *)malloc(dim3 * sizeof(int));
        }
    }

    
    printf("Enter elements:\n");
    for (i = 0; i < dim1; i++)
    {
        for (j = 0; j < dim2; j++)
        {
            for (k = 0; k < dim3; k++)
            {
                scanf("%d", * ( * (ptr + i) + j) + k);
            }
        }
    }

    
    printf("Elements are:\n");
    for (i = 0; i < dim1; i++)
    {
        for (j = 0; j < dim2; j++)
        {
            for (k = 0; k < dim3; k++)
            {
                printf("%d ", * ( * ( * (ptr + i) + j) + k));
            }
            printf("\n");
        }
        printf("\n");

    for (i = 0; i < dim1; i++)
    {
        for (j = 0; j < dim2; j++)
        {
            free(((ptr + i) + j));
        }
        free(*(ptr + i));
    }
    free(ptr);

    
}