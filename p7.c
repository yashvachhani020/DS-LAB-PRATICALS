#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtEnd(struct Node** head_ref, int new_data);
void deleteFromBeginning(struct Node** head_ref);
void deleteFromEnd(struct Node** head_ref);
void deleteFromPosition(struct Node** head_ref, int position);
void displayList(struct Node* node);
void freeList(struct Node** head_ref);

int main(void) {
    struct Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);

    printf("Original List: ");
    displayList(head);

    deleteFromBeginning(&head);
    printf("After deleting from beginning: ");
    displayList(head);

    deleteFromEnd(&head);
    printf("After deleting from end: ");
    displayList(head);

    deleteFromPosition(&head, 2);
    printf("After deleting from position 2: ");
    displayList(head);

    freeList(&head);

    return 0;
}

void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return;
    }

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

void deleteFromBeginning(struct Node** head_ref) {
    if (head_ref == NULL || *head_ref == NULL) {
        printf("List is empty. Deletion failed.\n");
        return;
    }

    struct Node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp);
}

void deleteFromEnd(struct Node** head_ref) {
    if (head_ref == NULL || *head_ref == NULL) {
        printf("List is empty. Deletion failed.\n");
        return;
    }

    struct Node* temp = *head_ref;

    if (temp->next == NULL) {
        *head_ref = NULL;
        free(temp);
        return;
    }

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

void deleteFromPosition(struct Node** head_ref, int position) {
    if (head_ref == NULL || *head_ref == NULL) {
        printf("List is empty. Deletion failed.\n");
        return;
    }

    if (position < 1) {
        printf("Position %d is invalid. Must be >= 1.\n", position);
        return;
    }

    struct Node* temp = *head_ref;

    if (position == 1) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position %d is out of bounds.\n", position);
        return;
    }

    struct Node* next_node = temp->next->next;
    free(temp->next);
    temp->next = next_node;
}

void displayList(struct Node* node) {
    if (node == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

void freeList(struct Node** head_ref) {
    if (head_ref == NULL) return;
    struct Node* current = *head_ref;
    struct Node* next_node = NULL;

    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    *head_ref = NULL;
}