#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row, col, val;
} Tuple;

Tuple *create_sparse(int **matrix, int m, int n, int *size) {
    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != 0) count++;
        }
    }
    *size = count + 1;
    Tuple *sparse = (Tuple *)malloc((*size) * sizeof(Tuple));
    sparse[0].row = m;
    sparse[0].col = n;
    sparse[0].val = count;
    int k = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != 0) {
                sparse[k].row = i;
                sparse[k].col = j;
                sparse[k].val = matrix[i][j];
                k++;
            }
        }
    }
    return sparse;
}

int main() {
    int m, n;
    printf("Enter matrix dimensions (rows cols): ");
    scanf("%d %d", &m, &n);

    int **matrix = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter matrix elements:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int size;
    Tuple *sparse = create_sparse(matrix, m, n, &size);

    printf("\nSparse Matrix Representation (3-Tuple Form):\n");
    for (int i = 0; i < size; i++) {
        printf("%d %d %d\n", sparse[i].row, sparse[i].col, sparse[i].val);
    }

    free(sparse);
    for (int i = 0; i < m; i++) free(matrix[i]);
    free(matrix);
    return 0;
}
