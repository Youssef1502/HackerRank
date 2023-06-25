/**==================================================
--    Author    :   YOUSSEF ADEL YOUSSEF
-- Description  :   HackerRank C - Pointers in C
==================================================**/

#include <stdio.h>

/* Define a function `update` that takes two integer pointers
 and updates the values to the sum and absolute difference, respectively */
void update(int *a,int *b) 
{
    int c = *a;
    
    *a = *a + *b;
    *b = abs(c - *b);
}

int main() 
{
    // Declare variables for input
    int a, b;
    int *pa = &a, *pb = &b;
    
    // Read two integers from standard input
    scanf("%d %d", &a, &b);

    // Call the `update` function with the addresses of the two integers
    update(pa, pb);

    // Print the updated values of `a` and `b` for sum and absolute difference
    printf("%d\n%d", a, b);

    return 0;
}