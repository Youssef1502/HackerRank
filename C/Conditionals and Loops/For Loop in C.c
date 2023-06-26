/**==================================================
--    Author    :   YOUSSEF ADEL YOUSSEF
-- Description  :   HackerRank C - For Loop in C
==================================================**/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int a, b;
    
    // Read two integers from standard input
    scanf("%d\n%d", &a, &b);
    
    // Array containing the English words for the numbers 1 to 9
    const char* Word[] = { "one", "two", "three", "four", "five","six", "seven", "eight", "nine" };
        
    // Loop through the integers from a to b
    for (int i=a ; i<=b ; i++) 
    {
        // Check whether the integer is between 1 and 9
        if (i >= 1 && i <= 9) 
        {
            // Print the corresponding English word for the integer
            printf("%s\n", Word[i-1]);
        }
        // Check whether the integer is greater than 9 and even
        else if (i > 9 && i % 2 == 0) 
        {
            // Print "even" if the integer is greater than 9 and even
            printf("even\n");
        }
        // Check whether the integer is greater than 9 and odd
        else if (i > 9 && i % 2 == 1) 
        {
            // Print "odd" if the integer is greater than 9 and odd
            printf("odd\n");
        }
    }
    
    return 0;
}