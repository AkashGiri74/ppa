#include <stdio.h>

void main() {
    char sentence[100];
    int evenCount = 0, oddCount = 0;
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }

    
    
    for (int i = 0; i < length; i++) 
    {
        if (str[i] != ' ' && str[i] != '\n')
         {
            if (length % 2 == 0)
             {
                evenCount++;
            } else {
                oddCount++;
            }
        }
    }

    
    printf("Length of the sentence: %d\n", length);
    printf("Number of even lengths: %d\n", evenCount);
    printf("Number of odd lengths: %d\n", oddCount);

    
}
