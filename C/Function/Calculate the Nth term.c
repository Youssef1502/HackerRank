/**==================================================
--    Author    :   YOUSSEF ADEL YOUSSEF
-- Description  :   HackerRank C - Calculate the Nth term
==================================================**/

#include <stdio.h>     // Include the standard input-output header for functions like printf and scanf.
#include <string.h>    // Include the string header for string manipulation functions (not used in this code).
#include <math.h>      // Include the math header for mathematical functions (not used in this code).
#include <stdlib.h>    // Include the standard library header for functions like malloc and free.

int find_nth_term(int n, int a, int b, int c) 
{
    int sum = 0 ;  // Initialize a variable 'sum' to store the sum of the last three terms.

    // Check if n is 1 or 2, and update c accordingly.
    if(n == 1)
        c = a;
    else if(n == 2)
        c = b;

    // Loop to calculate the nth term using the sum of the last three terms.
    while(n > 3) 
	{
        n--;             // Decrement n.
        sum = a + b + c;  // Calculate the sum of the last three terms.
        a = b;            // Update a with the value of b.
        b = c;            // Update b with the value of c.
        c = sum;          // Update c with the calculated sum.
        find_nth_term(n, a, b, c);  // Recursively call the function with updated values.
    }

    return c;  // Return the calculated nth term.
}

int main() {
    int n, a, b, c;  // Declare integer variables n, a, b, and c.
  
    scanf("%d %d %d %d", &n, &a, &b, &c);  // Read four integers from the standard input and store them in n, a, b, and c.
    int ans = find_nth_term(n, a, b, c);   // Call the find_nth_term function with the provided values and store the result in ans.
 
    printf("%d", ans);  // Print the value of ans to the standard output.
    return 0;            // Return 0 to indicate successful execution of the program.
}
