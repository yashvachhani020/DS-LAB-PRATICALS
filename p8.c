#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *prev, *next;
};

struct node* start = NULL;

void traverse()
{
    if (start == NULL) {
        printf("\nList is empty\n");
        return;
    }

    struct node* temp = start;
    printf("\n--- List Elements ---\n");
    while (temp != NULL) {
        printf("Data = %d\n", temp->info);
        temp = temp->next;
    }
}

void insertAtFront()
{
    int data;
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("\nMemory allocation failed\n");
        return;
    }

    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);

    temp->info = data;
    temp->prev = NULL;
    temp->next = start;

    if (start != NULL) {
        start->prev = temp;
    }
    start = temp;
}

void insertAtEnd()
{
    int data;
    struct node *temp, *trav;
    temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("\nMemory allocation failed\n");
        return;
    }

    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);

    temp->info = data;
    temp->next = NULL;
    temp->prev = NULL;

    if (start == NULL) {
        start = temp;
    } else {
        trav = start;
        while (trav->next != NULL) {
            trav = trav->next;
        }
        trav->next = temp;
        temp->prev = trav;
    }
}

void insertAtPosition()
{
    int data, pos, i = 1;
    printf("\nEnter position: ");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("\nInvalid position!\n");
        return;
    }

    if (pos == 1) {
        insertAtFront();
        return;
    }

    if (start == NULL) {
        printf("\nList is empty. Can only insert at position 1.\n");
        return;
    }

    struct node* temp = start;
    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("\nPosition out of range!\n");
        return;
    }

    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("\nMemory allocation failed\n");
        return;
    }

    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);

    newnode->info = data;
    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newnode;
    }
    temp->next = newnode;
}

void deleteFirst()
{
    if (start == NULL) {
        printf("\nList is empty\n");
        return;
    }

    struct node* temp = start;
    start = start->next;

    if (start != NULL) {
        start->prev = NULL;
    }
    free(temp);
    printf("\nFirst node deleted successfully\n");
}

void deleteEnd()
{
    if (start == NULL) {
        printf("\nList is empty\n");
        return;
    }

    struct node* temp = start;

    if (temp->next == NULL) {
        start = NULL;
        free(temp);
        printf("\nLast node deleted successfully\n");
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    free(temp);
    printf("\nLast node deleted successfully\n");
}

void deletePosition()
{
    if (start == NULL) {
        printf("\nList is empty\n");
        return;
    }

    int pos, i = 1;
    printf("\nEnter position: ");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("\nInvalid position!\n");
        return;
    }

    if (pos == 1) {
        deleteFirst();
        return;
    }

    struct node* temp = start;
    while (i < pos && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("\nPosition out of range!\n");
        return;
    }

    temp->prev->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
    printf("\nNode at position %d deleted successfully\n", pos);
}

int main()
{
    int choice;
    while (1) {
        printf("\n============================\n");
        printf("\t1 To see list\n");
        printf("\t2 For insertion at starting\n");
        printf("\t3 For insertion at end\n");
        printf("\t4 For insertion at any position\n");
        printf("\t5 For deletion of first element\n");
        printf("\t6 For deletion of last element\n");
        printf("\t7 For deletion of element at any position\n");
        printf("\t8 To exit\n");
        printf("============================\n");
        printf("Enter Choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
        case 1:
            traverse();
            break;
        case 2:
            insertAtFront();
            break;
        case 3:
            insertAtEnd();
            break;
        case 4:
            insertAtPosition();
            break;
        case 5:
            deleteFirst();
            break;
        case 6:
            deleteEnd();
            break;
        case 7:
            deletePosition();
            break;
        case 8:
            exit(0);
        default:
            printf("Incorrect Choice. Try Again.\n");
        }
    }
    return 0;
}