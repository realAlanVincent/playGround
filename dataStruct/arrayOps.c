#include <stdio.h>

#define MAX 100

void traverse(int arr[], int size) {
    printf("Array: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insert(int arr[], int *size, int position, int value) {
    for(int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = value;
    (*size)++;
}

void delete(int arr[], int *size, int position) {
    for(int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

int merge(int arr1[], int size1, int arr2[], int size2, int merged[]) {
    int i;
    for(i = 0; i < size1; i++) {
        merged[i] = arr1[i];
    }
    for(int j = 0; j < size2; j++) {
        merged[i] = arr2[j];
        i++;
    }
    return size1 + size2;
}

int main() {
    int arr1[MAX] = {10, 20, 30, 40, 50};
    int size1 = 5;

    traverse(arr1, size1);

    insert(arr1, &size1, 2, 25);
    traverse(arr1, size1);

    delete(arr1, &size1, 4);
    traverse(arr1, size1);

    int arr2[] = {60, 70, 80};
    int size2 = 3;
    int merged[MAX];
    int mergedSize = merge(arr1, size1, arr2, size2, merged);

    traverse(merged, mergedSize);

    return 0;
}