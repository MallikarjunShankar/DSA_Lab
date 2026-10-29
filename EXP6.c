// IMPLEMENTATION OF DOUBLY LINKED LIST

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

void append(int x) {
    struct Node *new = malloc(sizeof(struct Node));
    if (new == NULL) return;

    new->data = x;
    new->prev = NULL;
    new->next = NULL;

    if (head == NULL) {
        head = new;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = new;
    new->prev = temp;
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
        new->prev = NULL;
        new->next = head;
        if (head != NULL) head->prev = new;
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
    new->prev = temp;

    if (temp->next != NULL) temp->next->prev = new;
    temp->next = new;
}

void delete(int x) {
    if (head == NULL) {
        printf("List empty.\n");
        return;
    }

    struct Node *temp = head;

    while (temp != NULL && temp->data != x) temp = temp->next;

    if (temp == NULL) {
        printf("Element not found.\n");
        return;
    }

    if (temp->prev != NULL) temp->prev->next = temp->next;
    else head = temp->next;

    if (temp->next != NULL) temp->next->prev = temp->prev;

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

    insert(25, 2);
    display();

    delete(20);
    display();

    freeList();
    return 0;
}