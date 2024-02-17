#include <stdio.h>

int main() {
    char str[100];
    int small_letters = 0, capital_letters = 0, spaces = 0, digits = 0;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            small_letters++;
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            capital_letters++;
        } else if (str[i] == ' ') {
            spaces++;
        } else if (str[i] >= '0' && sentence[i] <= '9') {
            digits++;
        }
    }

    printf("Small Letters: %d\n", small_letters);
    printf("Capital Letters: %d\n", capital_letters);
    printf("Spaces: %d\n", spaces);
    printf("Digits: %d\n", digits);

    return 0;
}
