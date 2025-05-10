#include <stdio.h>

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int swapped;

    // Outer loop: Traverse the array multiple times
    for (i = 0; i < n-1; i++) {
        swapped = 0;

        // Inner loop: Compare adjacent elements and swap if needed
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap the elements
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
            }
        }

        // If no two elements were swapped in the inner loop, the array is already sorted
        if (swapped == 0) {
            break;
        }
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
    int arr[] = {64, 34, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Original Array: ");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("Sorted Array: ");
    printArray(arr, n);

    return 0;
}
