/**==================================================
--    Author    :   YOUSSEF ADEL YOUSSEF
-- Description  :   HackerRank C - Students Marks Sum
==================================================**/

#include <stdio.h>     // Include the standard input-output header for functions like printf and scanf.
#include <string.h>    // Include the string header for string manipulation functions (not used in this code).
#include <math.h>      // Include the math header for mathematical functions (not used in this code).
#include <stdlib.h>    // Include the standard library header for functions like malloc and free.


int marks_summation(int* marks, int number_of_students, char gender) 
{
    int sum = 0;     // Initialize a variable 'sum' to store the total marks.
    int i = 0;       // Initialize a variable 'i' to track the current student index.

    // Loop to iterate through the students' marks based on gender.
    while (i < number_of_students) 
	{
        switch (gender) 
		{
            case 'b':
                sum += marks[i];      // If gender is 'b' (boys), add the marks of boys to the total.
                i += 2;               // Move to the next boy's index (skipping girls).
                break;

            case 'g':
                sum += marks[i + 1];  // If gender is 'g' (girls), add the marks of girls to the total.
                i += 2;               // Move to the next girl's index (skipping boys).
                break;
        }
    }

    return sum;  // Return the total marks.
}

int main() 
{
    int number_of_students;
    char gender;
    int sum;

    scanf("%d", &number_of_students);  // Read the number of students from the standard input.
    
    // Allocate memory for an integer array to store marks for each student.
    int *marks = (int *) malloc(number_of_students * sizeof(int));

    // Read the marks for each student and store them in the 'marks' array.
    for (int student = 0; student < number_of_students; student++) 
	{
        scanf("%d", (marks + student));
    }

    scanf(" %c", &gender);  // Read the gender character ('b' or 'g') from the standard input.
    
    // Call the 'marks_summation' function to calculate the total marks based on gender.
    sum = marks_summation(marks, number_of_students, gender);
    
    printf("%d", sum);  // Print the total marks to the standard output.
    
    free(marks);  // Free the dynamically allocated memory.
    
    return 0;  // Return 0 to indicate successful execution of the program.
}
