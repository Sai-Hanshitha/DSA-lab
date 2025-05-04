#ifndef SORT_H
#define SORT_H

#include <cstdio>

// Function to display array
void displayArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Bubble Sort function
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        // Display array after each pass
        printf("Array after pass %d: ", i + 1);
        displayArray(arr, size);

        if (!swapped) break; 
    }
}

// Selection Sort function
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap minimum element with the first 
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;

        // Display array after each pass
        printf("Array after pass %d: ", i + 1);
        displayArray(arr, size);
    }
}

// Insertion Sort function
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        // Shift elements of sorted part to find the correct position for the key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;

        // Display array after each pass
        printf("Array after pass %d: ", i);
        displayArray(arr, size);
    }
}

#endif /
