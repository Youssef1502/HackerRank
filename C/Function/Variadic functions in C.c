/**==================================================
--    Author    :   YOUSSEF ADEL YOUSSEF
-- Description  :   HackerRank C - Variadic functions in C
==================================================**/

#include <stdarg.h>       // Include the standard argument handling header.
#include <stdio.h>        // Include the standard input-output header.
#include <stdlib.h>       // Include the standard library header.
#include <time.h>         // Include the time header for time-related functions.

#define MIN_ELEMENT 1     // Define a constant for the minimum element value.
#define MAX_ELEMENT 1000000  // Define a constant for the maximum element value.

// Function to calculate the sum of a variable number of integers using variable arguments.
int sum(int count, ...) {
    int sum = 0;

    va_list ptr;  // Declare a variable of type va_list for handling variable arguments.
    va_start(ptr, count);  // Initialize the pointer to the variable argument list.

    // Loop through the variable arguments and add them to 'sum'.
    for (int i = 0; i < count; i++) {
        sum += va_arg(ptr, int);  // Access each argument in the list and increment the position.
    }
    
    va_end(ptr);  // End processing of variable arguments.
    return sum;   // Return the calculated sum.
}

// Function to find the minimum of a variable number of integers using variable arguments.
int min(int count, ...) {
    va_list ptr;
    va_start(ptr, count);
    
    int min = va_arg(ptr, int);  // Initialize 'min' with the first argument.
    int tmp;
    for (int i = 1; i < count; i++) {
        if ((tmp = va_arg(ptr, int)) < min) {
            min = tmp;  // Update 'min' if a smaller value is encountered.
        }
    }
    
    va_end(ptr);
    return min;  // Return the minimum value.
}

// Function to find the maximum of a variable number of integers using variable arguments.
int max(int count, ...) {
    va_list ptr;
    va_start(ptr, count);
    
    int max = va_arg(ptr, int);  // Initialize 'max' with the first argument.
    int tmp;
    for (int i = 1; i < count; i++) {
        if ((tmp = va_arg(ptr, int)) > max) {
            max = tmp;  // Update 'max' if a larger value is encountered.
        }
    }
    
    va_end(ptr);
    return max;  // Return the maximum value.
}

// Function to test the sum, min, and max functions with three random elements.
int test_implementations_by_sending_three_elements() {
    srand(time(NULL));  // Seed the random number generator.
    
    int elements[3];
    
    // Generate three random elements within the specified range.
    elements[0] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[1] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[2] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    
    fprintf(stderr, "Sending the following three elements:\n");
    for (int i = 0; i < 3; i++) {
        fprintf(stderr, "%d\n", elements[i]);  // Print the generated elements.
    }
    
    int elements_sum = sum(3, elements[0], elements[1], elements[2]);
    int minimum_element = min(3, elements[0], elements[1], elements[2]);
    int maximum_element = max(3, elements[0], elements[1], elements[2]);

    fprintf(stderr, "Your output is:\n");
    fprintf(stderr, "Elements sum is %d\n", elements_sum);
    fprintf(stderr, "Minimum element is %d\n", minimum_element);
    fprintf(stderr, "Maximum element is %d\n\n", maximum_element);
    
    int expected_elements_sum = 0;
    for (int i = 0; i < 3; i++) {
        if (elements[i] < minimum_element || elements[i] > maximum_element) {
            return 0;  // Return 0 if any element is out of range.
        }
        expected_elements_sum += elements[i];
    }
    
    return elements_sum == expected_elements_sum;  // Return 1 if the sum is as expected.
}

// Function to test the sum, min, and max functions with five random elements.
int test_implementations_by_sending_five_elements() {
    srand(time(NULL));
    
    int elements[5];
    
    // Generate five random elements within the specified range.
    elements[0] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[1] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[2] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[3] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[4] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    
    fprintf(stderr, "Sending the following five elements:\n");
    for (int i = 0; i < 5; i++) {
        fprintf(stderr, "%d\n", elements[i]);
    }
    
    int elements_sum = sum(5, elements[0], elements[1], elements[2], elements[3], elements[4]);
    int minimum_element = min(5, elements[0], elements[1], elements[2], elements[3], elements[4]);
    int maximum_element = max(5, elements[0], elements[1], elements[2], elements[3], elements[4]);
    
    fprintf(stderr, "Your output is:\n");
    fprintf(stderr, "Elements sum is %d\n", elements_sum);
    fprintf(stderr, "Minimum element is %d\n", minimum_element);
    fprintf(stderr, "Maximum element is %d\n\n", maximum_element);
    
    int expected_elements_sum = 0;
    for (int i = 0; i < 5; i++) {
        if (elements[i] < minimum_element || elements[i] > maximum_element) {
            return 0;
        }
        expected_elements_sum += elements[i];
    }
    
    return elements_sum == expected_elements_sum;
}

// Function to test the sum, min, and max functions with ten random elements.
int test_implementations_by_sending_ten_elements() {
    srand(time(NULL));
    
    int elements[10];
    
    // Generate ten random elements within the specified range.
    elements[0] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[1] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[2] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[3] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[4] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[5] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[6] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[7] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[8] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[9] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    
    fprintf(stderr, "Sending the following ten elements:\n");
    for (int i = 0; i < 10; i++) {
        fprintf(stderr, "%d\n", elements[i]);
    }
    
    int elements_sum = sum(10, elements[0], elements[1], elements[2], elements[3], elements[4],
                           elements[5], elements[6], elements[7], elements[8], elements[9]);
    int minimum_element = min(10, elements[0], elements[1], elements[2], elements[3], elements[4],
                           elements[5], elements[6], elements[7], elements[8], elements[9]);
    int maximum_element = max(10, elements[0], elements[1], elements[2], elements[3], elements[4],
                           elements[5], elements[6], elements[7], elements[8], elements[9]);
    
    fprintf(stderr, "Your output is:\n");
    fprintf(stderr, "Elements sum is %d\n", elements_sum);
    fprintf(stderr, "Minimum element is %d\n", minimum_element);
    fprintf(stderr, "Maximum element is %d\n\n", maximum_element);
    
    int expected_elements_sum = 0;
    for (int i = 0; i < 10; i++) {
        if (elements[i] < minimum_element || elements[i] > maximum_element) {
            return 0;
        }
        expected_elements_sum += elements[i];
    }
    
    return elements_sum == expected_elements_sum;
}

// Main function for running tests.
int main() {
    int number_of_test_cases;
    scanf("%d", &number_of_test_cases);
    
    while (number_of_test_cases--) {
        // Test the implementations for different element counts.
        if (test_implementations_by_sending_three_elements()) {
            printf("Correct Answer\n");
        } else {
            printf("Wrong Answer\n");
        }
        
        if (test_implementations_by_sending_five_elements()) {
            printf("Correct Answer\n");
        } else {
            printf("Wrong Answer\n");
        }
        
        if (test_implementations_by_sending_ten_elements()) {
            printf("Correct Answer\n");
        } else {
            printf("Wrong Answer\n");
        }
    }
    
    return 0;  // Return 0 to indicate successful execution.
}
