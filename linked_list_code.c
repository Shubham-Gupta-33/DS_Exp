#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;

void insertAtBegin();
void insertAtEnd();
void insertAtPos();
void deleteAtBegin();
void deleteAtEnd();
void deleteAtPos();
void display();
void search();

int main() {
    int choice;
    do {
        printf("\n----- LINKED LIST MENU -----\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Display\n");
        printf("8. Search\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertAtBegin(); break;
            case 2: insertAtEnd();   break;
            case 3: insertAtPos();   break;
            case 4: deleteAtBegin(); break;
            case 5: deleteAtEnd();   break;
            case 6: deleteAtPos();   break;
            case 7: display();       break;
            case 8: search();        break;
            case 9: printf("Exiting...\n"); break;
            default: printf("Invalid choice, try again.\n");
        }
    } while (choice != 9);

    return 0;
}

/* ---------------- INSERTION ---------------- */

void insertAtBegin() {
    struct node *newNode;
    int value;

    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &value);
    newNode->data = value;

    newNode->next = start;   /* works whether start is NULL or not */
    start = newNode;

    printf("Node inserted at beginning.\n");
}

void insertAtEnd() {
    struct node *newNode, *p;
    int value;

    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &value);
    newNode->data = value;
    newNode->next = NULL;

    if (start == NULL) {
        start = newNode;
    } else {
        p = start;
        while (p->next != NULL)
            p = p->next;
        p->next = newNode;
    }
    printf("Node inserted at end.\n");
}

void insertAtPos() {
    struct node *newNode, *p;
    int value, pos, i;

    printf("Enter the data: ");
    scanf("%d", &value);
    printf("Enter position (1 = first node): ");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }

    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;

    if (pos == 1) {
        newNode->next = start;
        start = newNode;
        printf("Node inserted at position %d.\n", pos);
        return;
    }

    p = start;
    for (i = 1; i < pos - 1 && p != NULL; i++)
        p = p->next;

    if (p == NULL) {
        printf("Position out of range.\n");
        free(newNode);
        return;
    }

    newNode->next = p->next;
    p->next = newNode;
    printf("Node inserted at position %d.\n", pos);
}

/* ---------------- DELETION ---------------- */

void deleteAtBegin() {
    struct node *p;

    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }
    p = start;
    start = start->next;
    printf("Deleted value: %d\n", p->data);
    free(p);
}

void deleteAtEnd() {
    struct node *p, *q;

    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (start->next == NULL) {
        printf("Deleted value: %d\n", start->data);
        free(start);
        start = NULL;
        return;
    }
    p = q = start;
    while (p->next != NULL) {
        q = p;
        p = p->next;
    }
    q->next = NULL;
    printf("Deleted value: %d\n", p->data);
    free(p);
}

void deleteAtPos() {
    struct node *p, *q;
    int pos, i;

    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Enter position to delete (1 = first node): ");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1) {
        p = start;
        start = start->next;
        printf("Deleted value: %d\n", p->data);
        free(p);
        return;
    }

    p = start;
    for (i = 1; i < pos - 1 && p != NULL; i++)
        p = p->next;

    if (p == NULL || p->next == NULL) {
        printf("Position out of range.\n");
        return;
    }

    q = p->next;
    p->next = q->next;
    printf("Deleted value: %d\n", q->data);
    free(q);
}

/* ---------------- DISPLAY ---------------- */

void display() {
    struct node *p = start;

    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List: ");
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

/* ---------------- SEARCH ---------------- */

void search() {
    struct node *p = start;
    int value, pos = 1;

    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Enter value to search: ");
    scanf("%d", &value);

    while (p != NULL) {
        if (p->data == value) {
            printf("Found %d at position %d.\n", value, pos);
            return;
        }
        p = p->next;
        pos++;
    }

    printf("%d not found in the list.\n", value);
}
