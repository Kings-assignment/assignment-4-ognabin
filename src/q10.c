// Write a C program that defines a structure Car with members: model, year, and mileage. 
// Store information for 3 cars and find the car with the lowest mileage.
#include <stdio.h>
struct Car {
    char model[50];
    int year;
    float mileage;
};
int main() {
    struct Car cars[3];

    for (int i = 0; i < 3; i++) {
        printf("Enter details for car %d:\n", i + 1);
        printf("Model: ");
        fgets(cars[i].model, sizeof(cars[i].model), stdin); 
        cars[i].model[strcspn(cars[i].model, "\n")] = '\0'; 

        printf("Year: ");
        scanf("%d", &cars[i].year); 

        printf("Mileage: ");
        scanf("%f", &cars[i].mileage); 

        getchar(); 
    }

    struct Car *lowestMileageCar = &cars[0];
    for (int i = 1; i < 3; i++) {
        if (cars[i].mileage < lowestMileageCar->mileage) {
            lowestMileageCar = &cars[i];
        }
    }

    printf("\nCar with the lowest mileage:\n");
    printf("Model: %s\n", lowestMileageCar->model);
    printf("Year: %d\n", lowestMileageCar->year);
    printf("Mileage: %.2f\n", lowestMileageCar->mileage);

    return 0;
}
