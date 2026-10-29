// IMPLEMENTATION OF STRUCTS
#define MAX 10
#include <stdio.h>
#include <string.h>

struct list {
    int num;
    char name[100];
};

int main() {
    struct list arr[MAX];

    for (int i = 0; i < MAX; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", arr[i].name);
        arr[i].num = i + 1;
    }

    printf("\nDisplaying student details:\n\n");
    printf("Number\tName\n\n");
    for (int i = 0; i < MAX; i++) printf("%d\t%s\n", arr[i].num, arr[i].name);
    return 0;
}