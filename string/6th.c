#include <stdio.h>
#include <string.h>

int main() 
{
    char str[100] ,temp;
  int length,i;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

     length = strlen(str) - 1; 

    for ( i = 0; i < length / 2; ++i) 
    {
         temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }

    printf("Reversed String: %s\n", str);


}
