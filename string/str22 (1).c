#include <stdio.h>

void main() {
    char str[100];
    int spaces = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            spaces++;
        }
    }

    printf("Number of white spaces: %d\n", spaces);

    
}
