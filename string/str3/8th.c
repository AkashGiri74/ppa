#include <stdio.h>

int main() {
    char inputString[1000],temp;
    int start = 0;
    int i = 0,length,end;

    printf("Enter a string: ");
    fgets(inputString,sizeof(inputString),stdin);

    while (inputString[i] != '\0') 
    {
        if (inputString[i] == ' ' || inputString[i] == '\0') 
        {
             length = i - start;
             end;

            if (length % 2 == 0)
             {
                end = i - 1;
                while (start < end) 
                {
                    temp = inputString[start];
                    inputString[start] = inputString[end];
                    inputString[end] = temp;
                    start++;
                    end--;
                }
            }
            start = i + 1;
        }
        i++;
    }

    printf("Output String: %s\n", inputString);


}
