#include <stdio.h>

#define MAX 10 // Maximum matrix size for simplicity

typedef struct {
    int row, col, val;
} Tuple;

void create_sparse(int matrix[MAX][MAX], int rows, int cols, Tuple sparse[MAX * MAX], int *size) {
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparse[count + 1].row = i;
                sparse[count + 1].col = j;
                sparse[count + 1].val = matrix[i][j];
                count++;
            }
        }
    }
    sparse[0].row = rows;
    sparse[0].col = cols;
    sparse[0].val = count;
    *size = count + 1;
}

void print_matrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("\nOriginal Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void print_sparse(Tuple sparse[MAX * MAX], int size) {
    printf("\nSparse Matrix (Row, Column, Value):\n");
    for (int i = 0; i < size; i++) {
        printf("%d  %d  %d\n", sparse[i].row, sparse[i].col, sparse[i].val);
    }
}

int main() {
    int rows, cols;
    int matrix[MAX][MAX];
    Tuple sparse[MAX * MAX];
    
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);
    
    printf("\nEnter the matrix elements (use 0 for sparse positions):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    
    print_matrix(matrix, rows, cols);
    
    int size;
    create_sparse(matrix, rows, cols, sparse, &size);
    print_sparse(sparse, size);
    
    return 0;
}
