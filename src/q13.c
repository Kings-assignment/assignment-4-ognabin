// Write a C program that copies the contents of one file to another file.
#include <stdio.h>
int main() {
    char sourceFile[100], destFile[100];
    FILE *source, *dest;
    char ch;

    printf("Enter the source filename: ");
    fgets(sourceFile, sizeof(sourceFile), stdin); 
    sourceFile[strcspn(sourceFile, "\n")] = '\0'; 

    printf("Enter the destination filename: ");
    fgets(destFile, sizeof(destFile), stdin); 
    destFile[strcspn(destFile, "\n")] = '\0'; 

    source = fopen(sourceFile, "r"); 
    if (source == NULL) {
        printf("Error opening source file!\n");
        return 1; 
    }

    dest = fopen(destFile, "w"); 
    if (dest == NULL) {
        printf("Error opening destination file!\n");
        fclose(source); 
        return 1; 
    }

    while ((ch = fgetc(source)) != EOF) { 
        fputc(ch, dest); 
    }

    fclose(source); 
    fclose(dest); 

    printf("File has been copied successfully.\n");

    return 0;
}
