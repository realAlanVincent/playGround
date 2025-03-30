#include <stdio.h>

#define MAX 10 // Maximum size of the matrix

void readMatrix(int matrix[MAX][MAX], int *rows, int *cols) {
    printf("Enter number of rows and columns: ");
    scanf("%d %d", rows, cols);
    
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printSparseMatrix(int matrix[MAX][MAX], int rows, int cols) {
    int sparse[MAX * MAX][3]; // To store the sparse representation
    int k = 0;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
            }
        }
    }
    
    printf("\nSparse Matrix Representation (Row, Column, Value):\n");
    printf("%d %d %d\n", rows, cols, k); // First row contains matrix dimensions and non-zero count
    for (int i = 0; i < k; i++) {
        printf("%d %d %d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }
}

int main() {
    int matrix[MAX][MAX], rows, cols;
    
    readMatrix(matrix, &rows, &cols);
    printSparseMatrix(matrix, rows, cols);
    
    return 0;
}
