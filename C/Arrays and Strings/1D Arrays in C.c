/**==================================================
--    Author    :   YOUSSEF ADEL YOUSSEF
-- Description  :   HackerRank C - 1D Arrays in C
==================================================**/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

// Declare and initialize variables
int n=0 , i=0 , sum=0;

// Read the value of n from the user
scanf("%d" , &n);

// Dynamically allocate an array of size n
int *arr = (int*) malloc(n * sizeof(int)); 

// Read n integers from the user and store them in the array
for (i=0 ; i<n ; i++) 
{
    scanf("%d" , &arr[i]);
    sum += arr[i]; // Calculate the sum of the integers in the array
} 

// Print the sum of the integers in the array to the console
printf("%d" , sum);

// Free the dynamically allocated memory
free(arr);

return 0;

}