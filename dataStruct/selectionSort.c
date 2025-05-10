#include <stdio.h>

// Function to perform Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, minIdx, temp;

    // Outer loop: Traverse through all array elements
    for (i = 0; i < n-1; i++) {
        // Assume the current index i is the smallest
        minIdx = i;
        
        // Inner loop: Find the smallest element in the remaining unsorted portion
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j; // Update minIdx if a smaller element is found
            }
        }
        
        // Swap the found smallest element with the first element
        temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
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
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Original Array: ");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("Sorted Array: ");
    printArray(arr, n);

    return 0;
}
