// Write a C program that reverses an array of characters using pointers.
#include <stdio.h>
#include <string.h>
void reverseArray(char *arr, int size) {
    char temp;
    for (int i = 0; i < size / 2; i++) {
        temp = arr[i]; 
        arr[i] = arr[size - i - 1]; 
        arr[size - i - 1] = temp; 
    }
}
int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); 
    str[strcspn(str, "\n")] = '\0'; 

    int length = strlen(str);
    reverseArray(str, length); 

    printf("Reversed string: %s\n", str);

    return 0;
}
