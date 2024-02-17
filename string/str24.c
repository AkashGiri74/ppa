#include <stdio.h>

void main() {
    char str[100];

    
    printf("Enter a String: ");
    fgets(str, sizeof(str), stdin);

    
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }

    
    int lastWordStart = length - 1;
    while (lastWordStart >= 0 && str[lastWordStart] == ' ')
     {
        lastWordStart--;
    }

    
    int lastWordEnd = lastWordStart;
    while (lastWordEnd >= 0 && str[lastWordEnd] != ' ' && str[lastWordEnd] != '\n')
     {
        lastWordEnd--;
    }

    printf("Last word in the string: ");
    for (int i = lastWordEnd + 1; i <= lastWordStart; i++) 
    {
        printf("%c", str[i]);
    }
    printf("\n");

    
}
