// IMPLEMENTATION OF MATRIX MULTIPLICATION - DYNAMIC MEMORY ALLOCATION

#include <stdio.h>
#include <stdlib.h>

int **allocMatrix(int m, int n) {
    int **A = malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) A[i] = malloc(n * sizeof(int));
    return A;
}

void initialize(int **M, int m, int n) {
    printf("\nEnter elements:\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &M[i][j]);
}

void display(int **M, int m, int n) {
    printf("\nMatrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", M[i][j]);
        printf("\n");
    }
}

void multiply(int **A, int **B, int **C, int m, int n, int p) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}

void freeMatrix(int **M, int m) {
    for (int i = 0; i < m; i++) free(M[i]);
    free(M);
}

int main() {
    int m, n, p, q;
    int **A, **B, **C;

    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &m, &n);

    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &p, &q);

    if (m <= 0 || n <= 0 || p <= 0 || q <= 0 || n != p) {
        printf("Matrix multiplication not possible.\n");
        return 1;
    }

    A = allocMatrix(m, n);
    B = allocMatrix(p, q);
    C = allocMatrix(m, q);

    initialize(A, m, n);
    initialize(B, p, q);

    multiply(A, B, C, m, n, q);

    printf("\nFirst matrix:");
    display(A, m, n);

    printf("\nSecond matrix:");
    display(B, p, q);

    printf("\nProduct matrix:");
    display(C, m, q);

    freeMatrix(A, m);
    freeMatrix(B, p);
    freeMatrix(C, m);

    return 0;
}