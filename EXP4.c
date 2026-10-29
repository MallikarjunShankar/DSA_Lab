// ARRAY IMPLEMENTATION OF LIST

#define MAX 10
#include <stdio.h>

int a = 0;
int list[MAX];

void append(int x) {
    if (a == MAX) {
        printf("List full.\n");
        return;
    }
    list[a] = x;
    a++;
}

void insert(int x, int pos) {
    if (a == MAX) {
        printf("List full.\n");
        return;
    }
    if (pos < 0 || pos > a) {
        printf("Invalid position.\n");
        return;
    }
    int i;
    for (i = a; i > pos; i--) list[i] = list[i - 1];
    list[pos] = x;
    a++;
}

void delete(int x) {
    if (a == 0) {
        printf("List empty.\n");
        return;
    }
    int i, j;
    for (i = 0; i < a; i++)
        if (list[i] == x) break;

    if (i < a) {
        for (j = i; j < a - 1; j++) list[j] = list[j + 1];
        a--;
    }
    else {
        printf("Element not found.\n");
        return;
    }
}

void display() {
    if (a == 0) {
        printf("List empty.\n");
        return;
    }
    for (int i = 0; i < a; i++) printf("%d ", list[i]);
    printf("\n");
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
    return 0;
}