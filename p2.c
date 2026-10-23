#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 100

void traverse(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int insertElement(int arr[], int *size, int capacity, int element, int index) {
    if (*size >= capacity) {
        printf("Error: Array is full (Overflow).\n");
        return 0;
    }
    if (index < 0 || index > *size) {
        printf("Error: Invalid index. Must be between 0 and %d.\n", *size);
        return 0;
    }

    for (int i = *size - 1; i >= index; i--) {
        arr[i + 1] = arr[i];
    }

    arr[index] = element;
    (*size)++;
    printf("Element %d successfully inserted at index %d.\n", element, index);
    return 1;
}

int deleteElement(int arr[], int *size, int index) {
    if (*size == 0) {
        printf("Error: Array is empty (Underflow).\n");
        return 0;
    }
    if (index < 0 || index >= *size) {
        printf("Error: Invalid index. Must be between 0 and %d.\n", *size - 1);
        return 0;
    }

    int deletedValue = arr[index];

    for (int i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*size)--;
    printf("Element %d deleted from index %d.\n", deletedValue, index);
    return 1;
}

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[MAX_CAPACITY];
    int size = 0;
    int choice, element, index, result;

    printf("=== Array Operations Demonstration ===\n");
    printf("Enter initial number of elements (max %d): ", MAX_CAPACITY);
    if (scanf("%d", &size) != 1 || size < 0 || size > MAX_CAPACITY) {
        printf("Invalid initial size. Setting size to 0.\n");
        size = 0;
    } else {
        printf("Enter %d integers:\n", size);
        for (int i = 0; i < size; i++) {
            scanf("%d", &arr[i]);
        }
    }

    while (1) {
        printf("\n--- Operations Menu ---\n");
        printf("1. Traverse (Display elements)\n");
        printf("2. Insert an element\n");
        printf("3. Delete an element\n");
        printf("4. Search for an element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                traverse(arr, size);
                break;

            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter index position (0 to %d): ", size);
                scanf("%d", &index);
                insertElement(arr, &size, MAX_CAPACITY, element, index);
                break;

            case 3:
                printf("Enter index to delete (0 to %d): ", size - 1);
                scanf("%d", &index);
                deleteElement(arr, &size, index);
                break;

            case 4:
                printf("Enter element to search for: ");
                scanf("%d", &element);
                result = linearSearch(arr, size, element);
                if (result != -1) {
                    printf("Element %d found at index %d.\n", element, result);
                } else {
                    printf("Element %d not found in the array.\n", element);
                }
                break;

            case 5:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please choose between 1 and 5.\n");
        }
    }

    return 0;
}