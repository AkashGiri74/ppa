#include <stdio.h>
#include <string.h>

#define MAX 100
int main() 
{
    char string[MAX];
    int length;
    printf("Enter a string: ");
    fgets(string, MAX, stdin);
     length = strlen(string) - 1;
    printf("Number of characters in the string: %d\n", length);

}
/*#include <stdio.h>

int main() {
    char inputString[100]; 
    int count = 0;

    printf("Enter a string: ");
    fgets(inputString, sizeof(inputString), stdin);
    
    for (int i = 0; inputString[i] != '\0'; i++) {
        if (inputString[i] != '\n' && inputString[i] != '\r') {
            count++;
        }
    }
    printf("Number of characters in the string: %d\n", count);

    return 0;
}*/