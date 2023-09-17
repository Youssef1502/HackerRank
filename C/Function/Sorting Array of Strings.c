/**==================================================
--    Author    :   YOUSSEF ADEL YOUSSEF
-- Description  :   HackerRank C - Sorting Array of Strings
==================================================**/

#include <stdio.h>      // Include the standard input-output header for functions like printf.
#include <stdlib.h>     // Include the standard library header for functions like malloc and free.
#include <string.h>     // Include the string header for string manipulation functions.

// Function to compare two strings lexicographically (ascending order).
int lexicographic_sort(const char* a, const char* b) 
{
    return strcmp(a, b);  // Use the strcmp function to compare the two strings.
}

// Function to compare two strings lexicographically (descending order).
int lexicographic_sort_reverse(const char* a, const char* b) 
{
    return strcmp(b, a);  // Use the strcmp function to compare the two strings in reverse order.
}

// Function to count the number of distinct characters in a string.
int characters_count(const char* s) 
{
    int n = 0;                 // Initialize a counter for distinct characters.
    int count[128] = {0};      // Initialize an array to count occurrences of characters (assuming ASCII characters).

    if (NULL == s) 
	{
        return -1;  // Handle the case of a null string (error condition).
    }

    while (*s != '\0') 
	{
        if (!count[*s]) 
		{    // If the character has not been counted before:
            count[*s]++;     // Increment its count in the array.
            n++;             // Increment the counter for distinct characters.
        }
        s++;
    }
    return n;  // Return the count of distinct characters.
}

// Function to sort two strings based on the number of distinct characters they contain.
int sort_by_number_of_distinct_characters(const char* a, const char* b) 
{
    int con = characters_count(a) - characters_count(b);  // Compare the distinct character counts.
    return (con ? con : lexicographic_sort(a, b));        // If counts are equal, use lexicographic sorting.
}

// Function to sort two strings based on their lengths.
int sort_by_length(const char* a, const char* b) 
{
    int len = strlen(a) - strlen(b);     // Compare the lengths of the two strings.
    return (len ? len : lexicographic_sort(a, b));  // If lengths are equal, use lexicographic sorting.
}

// Function to perform sorting of an array of strings using a provided comparison function.
void string_sort(char** arr, const int len, int (*cmp_func)(const char* a, const char* b)) 
{
    int mid = len / 2;  // Calculate the middle index of the array.
    int con = 0;        // Initialize a variable to track whether any swaps were made.

    while (!con) 
	{  // Continue sorting until no swaps are made in a pass.
        con = 1;    // Assume the array is sorted until proven otherwise.

        for (int i = 0; i < len - 1; i++) 
		{  // Iterate through the array.
            if (cmp_func(arr[i], arr[i + 1]) > 0) 
			{  // Compare adjacent strings using the provided function.
                char* temp = arr[i];   // Swap the strings if they are out of order.
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                con = 0;              // Indicate that a swap was made, so another pass is needed.
            }
        }
    }
}

