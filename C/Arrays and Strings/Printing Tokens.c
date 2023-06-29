/**==================================================
--    Author    :   YOUSSEF ADEL YOUSSEF
-- Description  :   HackerRank C - Printing Tokens
==================================================**/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    // Declare variables
    char *s;
    s = malloc(1024 * sizeof(char));

    // Read a sentence from the user and store it in a dynamically allocated character array
    scanf("%[^\n]", s);

    // Reallocate the memory to the exact size of the input string
    s = realloc(s, strlen(s) + 1);

    // Print the tokens of the sentence to the console
    while(*s != '\0')
    {
        if(*s == ' ')
        {
            printf("\n"); // Print a new line character to separate tokens
        }
        
        else 
        {
            printf("%c" , *s); // Print the current character
        }
        
        s++; // Move to the next character in the string
    }

    return 0;
}
