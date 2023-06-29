/**==================================================
--    Author    :   YOUSSEF ADEL YOUSSEF
-- Description  :   HackerRank C - Digit Frequency
==================================================**/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    // Declare variables
    char num[1000];
    int digits[10] = { 0 } , i = 0;

    // Read a string of characters from the user
    scanf("%s", num);

    // Count the frequency of digits in the string using ASCII decimal representation
    for (int i = 0; i < strlen(num); i++)
    {
        // Check if the current character is a digit
        if (num[i] >= 48 && num[i] <= 57) 
            // Increment the corresponding element in the digits array
            digits[num[i] - 48]++; 
    }

    // Print the frequency of each digit to the console
    for (i = 0; i < 10; i++) 
    {
        printf("%d ", digits[i]);
    }

    return 0;
}
