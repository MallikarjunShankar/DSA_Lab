// IMPLEMENTATION OF STRUCTS USING POINTERS 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[100];
    int age;
    int id;
};

int main() {
    struct Student *student = (struct Student*)malloc(sizeof(struct Student));
    strcpy(student->name, "Mallikarjun Shankar");
    student->age = 19;
    student->id = 579;

    printf("Name:\t%s\nAge:\t%d\nID:\t%d", student->name, student->age, student->id);

    free(student);
    return 0;
}