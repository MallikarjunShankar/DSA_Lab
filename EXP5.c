// LINKED LIST IMPLEMENTATION OF LIST

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void append(int x) {
    struct Node *new = malloc(sizeof(struct Node));
    if (new == NULL) return;

    new->data = x;
    new->next = NULL;

    if (head == NULL) {
        head = new;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = new;
}

void insert(int x, int pos) {
    if (pos < 0) {
        printf("Invalid position.\n");
        return;
    }

    struct Node *new = malloc(sizeof(struct Node));
    if (new == NULL) return;
    new->data = x;

    if (pos == 0) {
        new->next = head;
        head = new;
        return;
    }

    struct Node *temp = head;
    int i;
    for (i = 0; temp != NULL && i < pos - 1; i++) temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position.\n");
        free(new);
        return;
    }

    new->next = temp->next;
    temp->next = new;
}

void delete(int x) {
    if (head == NULL) {
        printf("List empty.\n");
        return;
    }

    struct Node *temp = head, *prev = NULL;

    while (temp != NULL && temp->data != x) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element not found.\n");
        return;
    }

    if (prev == NULL) head = temp->next;
    else prev->next = temp->next;

    free(temp);
}

void display() {
    if (head == NULL) {
        printf("List empty.\n");
        return;
    }

    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void freeList() {
    struct Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    append(10);
    append(20);
    append(30);
    append(40);
    append(50);
    display();

    insert(40, 2);
    display();

    delete(20);
    display();

    freeList();
    return 0;
}