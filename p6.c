#include <stdio.h>
#include <stdlib.h>

// Definition of a Node
struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int val) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node **head, int val) {
    struct Node *newNode = createNode(val);
    newNode->next = *head;
    *head = newNode;
    printf("Inserted %d at the beginning.\n", val);
}

void insertAtEnd(struct Node **head, int val) {
    struct Node *newNode = createNode(val);

    if (*head == NULL) {
        *head = newNode;
        printf("Inserted %d at the end (list was empty).\n", val);
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("Inserted %d at the end.\n", val);
}

void insertAtPosition(struct Node **head, int val, int pos) {
    if (pos < 1) {
        printf("Invalid position! Position must be >= 1.\n");
        return;
    }

    if (pos == 1) {
        insertAtBeginning(head, val);
        return;
    }

    struct Node *temp = *head;
    
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Position %d is out of bounds!\n", pos);
        return;
    }

    struct Node *newNode = createNode(val);
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d at position %d.\n", val, pos);
}

void display(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;
    int choice, val, pos;

    while (1) {
        printf("\n--- SINGLY LINKED LIST MENU ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Specified Position\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insertAtBeginning(&head, val);
                break;

            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insertAtEnd(&head, val);
                break;

            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                printf("Enter position (1-based): ");
                scanf("%d", &pos);
                insertAtPosition(&head, val, pos);
                break;

            case 4:
                display(head);
                break;

            case 5: {
               
                struct Node *curr = head;
                while (curr != NULL) {
                    struct Node *next = curr->next;
                    free(curr);
                    curr = next;
                }
                printf("Memory cleared. Exiting program.\n");
                exit(0);
            }

            default:
                printf("Invalid choice! Choose between 1 and 5.\n");
        }
    }

    return 0;
}