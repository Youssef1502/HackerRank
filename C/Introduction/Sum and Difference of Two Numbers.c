/**==================================================
--    Author    :   YOUSSEF ADEL YOUSSEF
-- Description  :   HackerRank C - Sum and Difference of Two Numbers
==================================================**/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    // Declare variables to store input
    int INT_Num1 , INT_Num2;
    float FLOAT_Num1 , FLOAT_Num2;

    // Read two integers and two floating-point numbers from standard input
    scanf("%d %d %f %f\n", &INT_Num1, &INT_Num2, &FLOAT_Num1, &FLOAT_Num2);

    /* Print the sum and difference of the two integers, 
    and the sum and difference of the two floating-point numbers */
    printf("%d %d\n%.1f %.1f\n", INT_Num1+INT_Num2, INT_Num1-INT_Num2, FLOAT_Num1+FLOAT_Num2, FLOAT_Num1-FLOAT_Num2);

    return 0;
}