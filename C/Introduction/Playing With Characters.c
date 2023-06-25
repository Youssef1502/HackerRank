/**==================================================
--    Author    :   YOUSSEF ADEL YOUSSEF
-- Description  :   HackerRank C - Playing With Characters
==================================================**/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    // Declare variables to store input
    char ch;
    char s[15];
    char sen[100];
    
    // Read a single character from standard input
    scanf("%c\n", &ch);
    printf("%c\n", ch);

    // Read a string of up to 15 characters from standard input
    scanf("%s\n", &s);
    printf("%s\n", s);

    // Read a sentence (string of characters until newline) from standard input
    scanf("%[^\n]%*c", &sen);
    printf("%s\n", sen);
   
    return 0;
}

