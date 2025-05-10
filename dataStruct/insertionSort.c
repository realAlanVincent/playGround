#include <stdio.h>

// Function to perform Insertion Sort
void insertionSort(int arr[], int n) {
    int i, key, j;

    // Start from the second element (index 1) because the first element is already "sorted"
    for (i = 1; i < n; i++) {
        key = arr[i];  // The element to be inserted
        j = i - 1;

        // Shift elements of arr[0..i-1] that are greater than key to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        // Place key in the correct position
        arr[j + 1] = key;
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Original Array: ");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("Sorted Array: ");
    printArray(arr, n);

    return 0;
}
