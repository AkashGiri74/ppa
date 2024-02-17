//print word at specific postion
#include<stdio.h>
int main ()
{
  char str[100];
  int position ,i=0,currentpos=1;
  printf("enter a string :");
  fgets(str,sizeof(str),stdin);

  printf("enter postion you want to prinnt the word \n");
  scanf("%d",&position);

  while(str[i]!='\0') 
  { 
      if  (str[i]!=' ' && str[i]!='\n' && str[i]!='\t')
         {
                if (currentpos==position)
           {     
             while (str[i]!=' ' && str[i]!='\n' && str[i]!='\t')
           {
           printf("%c",str[i]);
            i++;
           }
           printf("\n");
         }
         currentpos++;
         }
     i++;
    
  }






}
/*#include <stdio.h>

int main() {
    char sentence[100]; // Declare an array to store the input sentence
    int position, currentPos = 1; // Declare variables for the word position and current position

    // Accepting the string from the user
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    // Accepting the position of the word to print
    printf("Enter the position of the word to print: ");
    scanf("%d", &position);

    int i = 0; // Initialize a variable for traversing the string

    // Traverse the string
    while (sentence[i] != '\0') {
        // Check for the start of a word
        if (sentence[i] != ' ' && sentence[i] != '\n' && sentence[i] != '\t') {
            // Check if the current word matches the specified position
            if (currentPos == position) {
                // Print the word at the specified position
                while (sentence[i] != ' ' && sentence[i] != '\n' && sentence[i] != '\t') {
                    printf("%c", sentence[i]);
                    i++;
                }
                printf("\n");
                return 0;
            }
            currentPos++; // Increment the current position if it's not the target word
        }
        i++; // Move to the next character in the string
    }

    printf("Word at position %d not found.\n", position); // Print a message if the word is not found
    return 0; // Return from the program
*/