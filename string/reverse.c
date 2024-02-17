#include <stdio.h>
#include <string.h>

#define MAX 100
int main() 
{
    char string[MAX];
    int length,i;
    printf("Enter a string: ");
    fgets(string, MAX, stdin);
     length = strlen(string) - 1;
     printf("reverese str\n");
     for(i=length-1;i>=0;i--)
        printf("%c",string[i]);
    printf("\n Number of characters in the string: %d\n", length);

}
