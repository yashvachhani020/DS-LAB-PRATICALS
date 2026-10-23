#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push(int val) {
    if (top >= MAX - 1) {
        printf("Stack Overflow! Cannot push %d.\n", val);
        return;
    }
    top++;
    stack[top] = val;
    printf("%d pushed onto the stack.\n", val);
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow! Stack is empty.\n");
        return -1;
    }
    int val = stack[top];
    top--;
    printf("%d popped from the stack.\n", val);
    return val;
}

void peep(int i) {
    if (top - i + 1 < 0 || i <= 0) {
        printf("Invalid position! Stack Underflow on PEEP.\n");
        return;
    }
    printf("Element at position %d from top is: %d\n", i, stack[top - i + 1]);
}

void change(int i, int newVal) {
    if (top - i + 1 < 0 || i <= 0) {
        printf("Invalid position! Cannot change value.\n");
        return;
    }
    stack[top - i + 1] = newVal;
    printf("Value at position %d from top updated to %d.\n", i, newVal);
}

void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements (Top -> Bottom): ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int choice, val, pos;

    while (1) {
        printf("\n--- STACK OPERATIONS (Capacity: %d) ---\n", MAX);
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEP (i-th from top)\n");
        printf("4. CHANGE (i-th from top)\n");
        printf("5. DISPLAY\n");
        printf("6. EXIT\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(val);
                break;

            case 2:
                pop();
                break;

            case 3:
                printf("Enter position from top (1-based): ");
                scanf("%d", &pos);
                peep(pos);
                break;

            case 4:
                printf("Enter position from top (1-based): ");
                scanf("%d", &pos);
                printf("Enter new value: ");
                scanf("%d", &val);
                change(pos, val);
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Enter between 1 and 6.\n");
        }
    }

    return 0;
}