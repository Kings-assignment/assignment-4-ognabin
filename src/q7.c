// Write a C program that defines a structure Employee with members: name, employee ID, and salary. 
// Take input for 5 employees and display the details of the employee with the highest salary.
#include <stdio.h>
struct Employee {
    char name[50];
    int employeeID;
    float salary;
};
int main() {
    struct Employee employees[5];
    struct Employee *ptr = employees; 

    for (int i = 0; i < 5; i++) {
        printf("Enter details for employee %d:\n", i + 1);
        printf("Name: ");
        fgets(ptr->name, sizeof(ptr->name), stdin); 
        ptr->name[strcspn(ptr->name, "\n")] = '\0'; 

        printf("Employee ID: ");
        scanf("%d", &ptr->employeeID); 

        printf("Salary: ");
        scanf("%f", &ptr->salary); 

        getchar(); 
        ptr++; 
    }

    struct Employee *highestSalaryEmployee = &employees[0];
    for (int i = 1; i < 5; i++) {
        if (employees[i].salary > highestSalaryEmployee->salary) {
            highestSalaryEmployee = &employees[i];
        }
    }

    printf("\nEmployee with the highest salary:\n");
    printf("Name: %s\n", highestSalaryEmployee->name);
    printf("Employee ID: %d\n", highestSalaryEmployee->employeeID);
    printf("Salary: %.2f\n", highestSalaryEmployee->salary);

    return 0;
}
