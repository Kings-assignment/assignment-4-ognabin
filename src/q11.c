// Write a C program to create a file and write a user-entered string into it. Then display a 
// message confirming that the file has been written successfully.
#include <stdio.h>
int main() {
    char str[100];
    FILE *file;

    printf("Enter a string to write to the file: ");
    fgets(str, sizeof(str), stdin); 
    str[strcspn(str, "\n")] = '\0'; 

    file = fopen("output.txt", "w"); 
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1; 
    }

    fprintf(file, "%s\n", str); 

    fclose(file); 

    printf("File has been written successfully.\n");

    return 0;
}

