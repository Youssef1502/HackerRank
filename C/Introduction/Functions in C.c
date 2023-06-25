/**==================================================
--    Author    :   YOUSSEF ADEL YOUSSEF
-- Description  :   HackerRank C - Functions in C
==================================================**/

#include <stdio.h>

/* Add `int max_of_four(int a, int b, int c, int d)` here. */
int max_of_four(int a, int b, int c, int d)
{
    // Check if `b` is greater than `max`, and if so, set `max` to `b`
    int max = a;
    
    // Check if `b` is greater than `max`, and if so, set `max` to `b`
    if(max < b)
        max = b;
    
    // Check if `c` is greater than `max`, and if so, set `max` to `c`
    if(max < c)
        max = c;
    
    // Check if `d` is greater than `max`, and if so, set `max` to `d`
    if(max < d)
        max = d;
        
    // Return the maximum value
    return max;
}

int main() 
{
    int a, b, c, d;
    
    // Read four integers from input
    scanf("%d %d %d %d", &a, &b, &c, &d);
    
    // Call the `max_of_four` function and store the result in `ans`
    int ans = max_of_four(a, b, c, d);
    
    // Print the maximum value
    printf("%d", ans);
    
    return 0;
}