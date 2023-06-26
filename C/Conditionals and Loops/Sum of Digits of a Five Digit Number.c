/**==================================================
--    Author    :   YOUSSEF ADEL YOUSSEF
-- Description  :   HackerRank C - Sum of Digits of a Five Digit Number
==================================================**/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    int n;
    
    // Read an integer from standard input
    scanf("%d", &n);
    
    // Initialize a variable to store the sum of the digits
    int sum=0;
    
    // Loop through the digits of the input number and add them to the sum
    while(n>0)
    {
        sum += n%10; // Add the last digit to the sum
        n /= 10;     // Remove the last digit from the number
    }
    
    // Print the sum of the digits
    printf("%d" , sum);
    
    return 0;
}