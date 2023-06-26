/**==================================================
--    Author    :   YOUSSEF ADEL YOUSSEF
-- Description  :   HackerRank C - Bitwise Operators
==================================================**/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Function to calculate the maximum values of bitwise AND, OR, and XOR operations
void calculate_the_maximum(int n, int k) 
{
    int maxAnd = 0;
    int maxOr = 0;
    int maxXor = 0;

    // Loop through all pairs of integers from 1 to n
    for (int i=1; i<=n; i++) 
    {
        for (int j=i+1; j<=n; j++) 
        {
            // Check whether the bitwise AND of i and j is greater than the current maximum and less than k
            if (((i&j) > maxAnd) && ((i&j) < k)) 
            {
                maxAnd = i&j; // Update the maximum AND value
            }
            
            // Check whether the bitwise OR of i and j is greater than the current maximum and less than k
            if (((i|j) > maxOr) && ((i|j) < k)) 
            {
                maxOr = i|j; // Update the maximum OR value
            }
            
            // Check whether the bitwise XOR of i and j is greater than the current maximum and less than k
            if (((i^j) > maxXor) && ((i^j) < k)) 
            {
                maxXor = i^j; // Update the maximum XOR value
            }
        }
    }
    
    // Print the maximum values of bitwise AND, OR, and XOR operations
    printf("%d\n%d\n%d\n", maxAnd, maxOr, maxXor);
}

int main() 
{
    int n, k;
  
    // Read two integers from standard input
    scanf("%d %d", &n, &k);
    
    // Call the function to calculate the maximum values of bitwise AND, OR, and XOR operations
    calculate_the_maximum(n, k);
 
    return 0;
}