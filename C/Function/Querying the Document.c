/**==================================================
--    Author    :   YOUSSEF ADEL YOUSSEF
-- Description  :   HackerRank C - Querying the Document
==================================================**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

// Function to parse the input text and create a document structure.
char**** get_document(char* text)
{
    char ****document; // Declare a four-dimensional array to represent the document.
    int paragraphs = 1, sentences = 1, words = 1, i; // Initialize counters for paragraphs, sentences, and words.

    // Allocate memory for the document structure.
    document = (char ****)malloc(sizeof(char ***));
    document[0] = (char ***)malloc(sizeof(char **));
    document[0][0] = (char **)malloc(sizeof(char *));
    document[0][0][0] = text; // Store the entire input text in the document.

    for(i = 0; text[i + 1] != 0; i++)
    {
        if(text[i + 1] == '\n')
            text[i++] = 0;

        switch(text[i])
        {
            case '\n':
                // Allocate memory for a new paragraph.
                document = (char ****)realloc(document, ++paragraphs * sizeof(char ***));
                sentences = 0;
            case '.':
                // Allocate memory for a new sentence.
                document[paragraphs - 1] = (char ***)realloc(document[paragraphs - 1], ++sentences * sizeof(char **));
                words = 0;
            case ' ':
                // Allocate memory for a new word and store the word's starting address.
                document[paragraphs - 1][sentences - 1] = (char **)realloc(document[paragraphs - 1][sentences - 1], ++words * sizeof(char *));
                document[paragraphs - 1][sentences - 1][words - 1] = &text[i + 1];
                text[i] = 0;
                break;
        }
    }

    text[i] = 0;

    return document; // Return the parsed document.
}

// Function to retrieve the kth word in the mth sentence of the nth paragraph.
char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) 
{
    return document[n - 1][m - 1][k - 1]; // Access and return the specified word.
}

// Function to retrieve the kth sentence in the mth paragraph.
char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) 
{ 
    return document[m - 1][k - 1]; // Access and return the specified sentence.
}

// Function to retrieve the kth paragraph.
char*** kth_paragraph(char**** document, int k) 
{
    return document[k - 1]; // Access and return the specified paragraph.
}

// Function to get the input text from standard input.
char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();

    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen(doc) + 1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc; // Return the input text as a dynamically allocated string.
}

// Function to print a single word.
void print_word(char* word) {
    printf("%s", word); // Print the specified word.
}

// Function to print a single sentence.
void print_sentence(char** sentence) {
    int word_count;
    scanf("%d", &word_count);
    for(int i = 0; i < word_count; i++){
        printf("%s", sentence[i]); // Print each word in the sentence.
        if( i != word_count - 1)
            printf(" ");
    }
} 

// Function to print a single paragraph.
void print_paragraph(char*** paragraph) {
    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++) {
        print_sentence(*(paragraph + i)); // Print each sentence in the paragraph.
        printf(".");
    }
}

int main() 
{
    char* text = get_input_text(); // Get the input text.
    char**** document = get_document(text); // Parse the input into a document.

    int q;
    scanf("%d", &q); // Read the number of queries.

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n); // Read query parameters.
            char* word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word); // Print the specified word.
        }

        else if (type == 2){
            int k, m;
            scanf("%d %d", &k, &m); // Read query parameters.
            char** sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence); // Print the specified sentence.
        }

        else{
            int k;
            scanf("%d", &k); // Read query parameter.
            char*** paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph); // Print the specified paragraph.
        }
        printf("\n"); // Print a newline to separate query results.
    }     
}
