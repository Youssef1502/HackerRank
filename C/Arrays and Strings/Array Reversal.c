/**==================================================
--    Author    :   YOUSSEF ADEL YOUSSEF
-- Description  :   HackerRank C - Array Reversal
==================================================**/

#include <stdio.h>
#include <stdlib.h>

int main()
{
// Declare variables
int num, *arr, i;

// Read the value of num from the user
scanf("%d", &num);

// Dynamically allocate an array of size num
arr = (int*) malloc(num * sizeof(int));

// Read num integers from the user and store them in the array
for(i = 0; i < num; i++) 
{
    scanf("%d", arr + i);
}

/* Reverse the elements of the array using a loop that swaps the 
   first and last elements, the second and second-to-last elements, 
   and so on until the middle of the array is reached. */
for (i = 0; i < num/2 ; i++) 
{
    int temp = arr[i];
    arr[i] = arr[num - 1 - i];
    arr[num - 1 - i] = temp;
}

// Print the reversed array to the console
for (i = 0; i < num; i++)
    printf("%d ", *(arr + i));

// Free the dynamically allocated memory
free(arr);

return 0;

}
