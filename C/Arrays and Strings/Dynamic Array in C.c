/**==================================================
--    Author    :   YOUSSEF ADEL YOUSSEF
-- Description  :   HackerRank C - Dynamic Array in C
==================================================**/

#include <stdio.h>
#include <stdlib.h>

/*
 * This stores the total number of books in each shelf.
 */
int* total_number_of_books;

/*
 * This stores the total number of pages in each book of each shelf.
 * The rows represent the shelves and the columns represent the books.
 */
int** total_number_of_pages;

int main()
{
    // Declare variables
    int total_number_of_shelves, total_number_of_queries;

    // Read the total number of shelves and queries from the user
    scanf("%d", &total_number_of_shelves);
    scanf("%d", &total_number_of_queries);

    // Dynamically allocate memory for the total number of books and pages
    total_number_of_books = (int *)malloc(total_number_of_shelves * sizeof(int));
    total_number_of_pages = (int **)malloc(total_number_of_shelves * sizeof(int*));

    // Initialize the number of books and pages for each shelf to 0 and NULL, respectively
   for(int i = 0 ; i < total_number_of_shelves ; i++)
   {
       total_number_of_books[i] = 0;
       total_number_of_pages[i] = NULL;
   }
    
    // Process each query
    while (total_number_of_queries--) 
    {
        int type_of_query;
        scanf("%d", &type_of_query);
        
        if (type_of_query == 1) 
        {
           
            int x, y;
            scanf("%d %d", &x, &y);

            // Increment the number of books on shelf x
            total_number_of_books[x]++; 

            // If this is the first book on shelf x, allocate memory for one page
            if(total_number_of_books[x] == 1) 
                total_number_of_pages[x] = malloc(sizeof(int)); 
                
            // If this is not the first book on shelf x, reallocate memory for one more page    
            else
                total_number_of_pages[x] = realloc(total_number_of_pages[x], total_number_of_books[x]*sizeof(int));

            // Add the number of pages of the new book at the end of the pages array of shelf x
            total_number_of_pages[x][total_number_of_books[x] - 1] = y;

        } 
	
	else if (type_of_query == 2) 
	{
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", *(*(total_number_of_pages + x) + y));
        } 
	
	else 
	{
            int x;
            scanf("%d", &x);
            printf("%d\n", *(total_number_of_books + x));
        }
    }

    if (total_number_of_books) 
    {
        free(total_number_of_books);
    }
    
    for (int i = 0; i < total_number_of_shelves; i++) 
    {
        if (*(total_number_of_pages + i)) 
	{
            free(*(total_number_of_pages + i));
        }
    }
    
    if (total_number_of_pages) 
    {
        free(total_number_of_pages);
    }
    
    return 0;
}