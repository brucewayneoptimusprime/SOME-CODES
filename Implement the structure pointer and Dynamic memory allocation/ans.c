#include <stdio.h>
#include <stdlib.h>

// Define a structure for a person
struct Person {
    char name[50];
    int age;
};

int main() {
    // Declare a pointer to a struct Person
    struct Person *personPtr;

    // Allocate memory for one person using malloc
    personPtr = (struct Person *)malloc(sizeof(struct Person));

    // Check if memory allocation is successful
    if (personPtr == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1; // Exit with an error code
    }

    // Input data for the person using the structure pointer
    printf("Enter name: ");
    scanf("%s", personPtr->name);

    printf("Enter age: ");
    scanf("%d", &personPtr->age);

    // Display the information using the structure pointer
    printf("Person's Information:\n");
    printf("Name: %s\n", personPtr->name);
    printf("Age: %d\n", personPtr->age);

    // Deallocate memory using free
    free(personPtr);

    return 0;
}
