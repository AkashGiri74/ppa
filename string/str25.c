#include <stdio.h>

int main() {
    char sentence[100];
    int position;

    
    printf("Enter a str: ");
    fgets(str, sizeof(str), stdin);

    
    printf("Enter the position: ");
    scanf("%d", &position);

    int length = 0;
    while (str[length] != '\0') 
    {
        length++;
    }

    int Count = 0;
    int start = -1, end;

    for (int i = 0; i < length; i++) {
        if (str[i] != ' ' && str[i] != '\n') 
        {
            if (start == -1) 
            {
                start = i;
            }

            if (i == length - 1 || str[i + 1] == ' ' || str[i + 1] == '\n') {
                end = i;
                Count++;

                if (Count == position) {
                    
                    printf("Word at position %d: ", position);
                    for (int j = start; j <= end; j++) {
                        printf("%c", str[j]);
                    }
                    printf("\n");
                    return 0;
                }

                start = -1;
            }
        }
    }

    
    if (position <= 0 || position > count) 
    {
        printf("Invalid position\n");
    }

    
}
