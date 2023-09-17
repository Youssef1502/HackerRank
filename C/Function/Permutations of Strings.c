/**==================================================
--    Author    :   YOUSSEF ADEL YOUSSEF
-- Description  :   HackerRank C - Permutations of Strings
==================================================**/

#include <stdio.h>      // Include the standard input-output header for functions like printf and scanf.
#include <stdlib.h>     // Include the standard library header for functions like malloc, free, and calloc.
#include <string.h>     // Include the string header for string manipulation functions.

// Function to generate the next lexicographically ordered permutation of a sequence of strings.
int next_permutation(int n, char **s) 
{
  int k, l;

  // 1. Find the largest index k such that s[k] < s[k+1].
  for (k = n - 2; k >= 0; k--) 
  {
    if (strcmp(s[k], s[k+1]) < 0) break;
  }
  if (k < 0) return 0;

  // 2. Find the largest index l greater than k such that s[k] < s[l].
  for (l = n - 1; l > k; l--) 
  {
    if (strcmp(s[k], s[l]) < 0) break;
  }

  // 3. Swap elements present at k and l.
  char *tmp = s[k];
  s[k] = s[l];
  s[l] = tmp;

  // 4. Reverse the sequence of elements from k+1 to n.
  for (int i = k + 1, j = n - 1; i < j; i++, j--) 
  {
    tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
  }
  return 1;
}

int main() 
{
    char **s;      // Declare a pointer to a pointer for strings.
    int n;         // Declare an integer variable 'n' to store the number of strings.

    scanf("%d", &n);   // Read the number of strings from the standard input.

    // Allocate memory for an array of pointers to strings.
    s = calloc(n, sizeof(char*));

    // Read each string and allocate memory for it.
    for (int i = 0; i < n; i++) 
	{
        s[i] = calloc(11, sizeof(char));  // Assuming each string has a maximum length of 10 characters.
        scanf("%s", s[i]);                // Read a string and store it in the array.
    }

    // Generate and print all permutations of the input strings.
    do {
        for (int i = 0; i < n; i++) 
		{
            printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');  // Print each string with space or newline.
        }
    } while (next_permutation(n, s));  // Generate the next permutation using the next_permutation function.

    // Free the allocated memory for strings and the array of pointers.
    for (int i = 0; i < n; i++) 
	{
        free(s[i]);
    }
    free(s);

    return 0;  // Return 0 to indicate successful execution of the program.
}

