// Write a C program that stores student records (name, roll number, and marks) into a 
// file and then reads and displays all stored records.
#include <stdio.h>
struct Student {
    char name[50];
    int rollNumber;
    float marks;
};
int main() {
    struct Student student;
    FILE *file;

    file = fopen("students.txt", "w"); 
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1; 
    }

    for (int i = 0; i < 3; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Name: ");
        fgets(student.name, sizeof(student.name), stdin); 
        student.name[strcspn(student.name, "\n")] = '\0'; 

        printf("Roll Number: ");
        scanf("%d", &student.rollNumber); 

        printf("Marks: ");
        scanf("%f", &student.marks); 

        fprintf(file, "%s,%d,%.2f\n", student.name, student.rollNumber, student.marks); 

        getchar(); 
    }

    fclose(file); 

    file = fopen("students.txt", "r"); 
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1; 
    }

    printf("\nStored Student Records:\n");
    while (fscanf(file, "%[^,],%d,%f\n", student.name, &student.rollNumber, &student.marks) == 3) { 
        printf("Name: %s\n", student.name);
        printf("Roll Number: %d\n", student.rollNumber);
        printf("Marks: %.2f\n\n", student.marks);
    }

    fclose(file); 

    return 0;
}
