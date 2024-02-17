#include <stdio.h>

void main() {
    char str[100];
    int count = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; ++i) {
        
        if (str[i] == ' ' || str [i] == '\n') 
        {
            ++count;
        }
    }

    
    ++count;

    printf("Number of words in the sentence: %d\n",count);

    
}