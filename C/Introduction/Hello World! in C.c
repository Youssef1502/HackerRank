/**==================================================
--    Author    :   YOUSSEF ADEL YOUSSEF
-- Description  :   HackerRank C - Hello World!
==================================================**/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    
    char s[100];
    
    // Read a string from standard input until a newline character is entered
    scanf("%[^\n]%*c", &s);
      
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    printf("Hello, World!\n%s",s);      
    return 0;
}