/**==================================================
--    Author    :   YOUSSEF ADEL YOUSSEF
-- Description  :   HackerRank C - Conditional Statements in C
==================================================**/

#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read a line of input from standard input
char* readline();

int main()
{
    char* n_endptr;
    
    // Read a line of input from the user
    char* n_str = readline();
    
    // Convert the input string to an integer using base 10
    int n = strtol(n_str, &n_endptr, 10);

    // Check whether the conversion was successful
    if (n_endptr == n_str || *n_endptr != '\0') 
    {
        // Exit with an error if the input string was not a valid integer
        exit(EXIT_FAILURE);
    }

    // Array containing the English words for the numbers 1 to 9
    const char* Word[] = { "one", "two", "three", "four", "five","six", "seven", "eight", "nine" };
    
    // check whether the input number is between 1 and 9
    if (n >= 1 && n <= 9) 
    {
        // Print the corresponding English word for the input number from the defined array
        printf("%s\n", Word[n-1]);
    }
    // Check whether the input number is greater than 9
    else if(n > 9) 
    {
        // Print "Greater than 9" if the input number is greater than 9
        printf("Greater than 9");
    }
    // The input number is less than 1
    else 
    {
        // Print "Less than 9" if the input number is less than 1
        printf("Less than 9");
    }

    return 0;
}

// function to read a line of input from standard input
char* readline() 
{
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    // loop until a newline character is encountered or the maximum length of the input buffer is reached
    while (true) 
    {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        // check whether the input buffer is not large enough to hold the input string
        // if so, reallocate the buffer with twice the previous size
        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        // exit with an error if the reallocation failed
        if (!data) { break; }

        alloc_length = new_length;
    }

    // trim any trailing newline character from the input string
    if (data[data_length - 1] == '\n') 
    {
        data[data_length - 1] = '\0';
    }

    // reallocate the buffer to the size of the input string
    data = realloc(data, data_length);

    // return the input string
    return data;
}