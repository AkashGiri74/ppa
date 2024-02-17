#include <stdio.h>

int main() {
    char inputString[100];
    printf("Enter a string: ");
    fgets(inputString, sizeof(inputString), stdin);

    for (int i = 0; inputString[i] != '\0'; i++) {
        if (inputString[i] == ' ') {
            inputString[i] = '$';
        }
    }
    printf("Modified string: %s", inputString);

}