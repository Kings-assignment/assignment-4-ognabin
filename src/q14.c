// Write a C program that counts the number of characters, words, and lines in a text file.
#include <stdio.h>
int main() {
    char filename[100];
    char ch;
    int charCount = 0, wordCount = 0, lineCount = 0;
    FILE *file;

    printf("Enter the filename to analyze: ");
    fgets(filename, sizeof(filename), stdin); 
    filename[strcspn(filename, "\n")] = '\0'; 

    file = fopen(filename, "r"); 
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1; 
    }

    while ((ch = fgetc(file)) != EOF) { 
        charCount++; 

        if (ch == ' ' || ch == '\t' || ch == '\n') { 
            wordCount++; 
        }
        if (ch == '\n') { 
            lineCount++; 
        }
    }

    if (charCount > 0) {
        wordCount++; 
    }

    printf("\nCharacter Count: %d\n", charCount);
    printf("Word Count: %d\n", wordCount);
    printf("Line Count: %d\n", lineCount);

    fclose(file); 

    return 0;
}
