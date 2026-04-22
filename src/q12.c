// Write a C program to read the contents of a text file and display them on the screen.
#include <stdio.h>
int main() {
    char filename[100];
    char ch;
    FILE *file;

    printf("Enter the filename to read: ");
    fgets(filename, sizeof(filename), stdin); 
    filename[strcspn(filename, "\n")] = '\0'; 

    file = fopen(filename, "r"); 
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1; 
    }

    printf("\nContents of the file:\n");
    while ((ch = fgetc(file)) != EOF) { 
        putchar(ch); 
    }

    fclose(file); 

    return 0;
}
