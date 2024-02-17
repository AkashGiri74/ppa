#include <stdio.h>

int main() 
{
    char sentence[100];
    int words,i;
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

     words = 0;
    for (i = 0; sentence[i] != '\0'; ++i) 
    {
        
        if (sentence[i] == ' ' || sentence[i] == '_')
         {

            if (i > 0 && sentence[i - 1] != ' ' && sentence[i - 1] != '_')
             {
                ++words;
            }
        }
    }

    if (sentence[0] != '\0' && sentence[strlen(sentence) - 1] != ' ' && sentence[strlen(sentence) - 1] != '_')
     {
        ++words;
    }

    printf("Number of words: %d\n", words);

    
}
