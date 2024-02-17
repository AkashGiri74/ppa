#include <stdio.h>

int main() {
    char inputString[100],temp;
    int N1, N2,strLength=0;

    printf("Enter a string: ");
    fgets(inputString,sizeof(inputString),stdin);

    printf("Enter the starting index (N1): ");
    scanf("%d", &N1);
    printf("Enter the ending index (N2): ");
    scanf("%d", &N2);

    while (inputString[strLength] != '\0') 
    {
        strLength++;
    }

    if (N1 < 0 || N2 >= strLength || N1 > N2)
     {
        printf("Invalid range.\n");
        return 1;
    }

    while (N1 < N2) 
    {
        if (inputString[N1] != ' ' && inputString[N2] != ' ') 
        {
             temp = inputString[N1];
            inputString[N1] = inputString[N2];
            inputString[N2] = temp;
            N1++;
            N2--;
        } else if (inputString[N1] == ' ') 
        {
            N1++;
        } else if (inputString[N2] == ' ') 
        {
            N2--;
        }
    }

    printf("Output String: %s\n", inputString);


}
