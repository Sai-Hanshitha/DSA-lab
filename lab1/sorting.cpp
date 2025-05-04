#include <cstdio>
#include <vector>
#include <algorithm> // For std::swap

// Function prototypes
void bubbleSort(std::vector<int>& arr);
void selectionSort(std::vector<int>& arr);
void insertionSort(std::vector<int>& arr);
void display(const std::vector<int>& arr);

int main() {
    int size;

    // Input the number of elements
 printf("Enter the number of elements: ");
 scanf("%d", &size);

    if (size <= 0) {
    printf("Invalid size. Size must be greater than 0.\n");
        return 1;
    }

std::vector<int> arr(size);

    // Input array elements
    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    while (true) {
        // Display menu
        printf("\nMenu:\n");
        printf("1. Bubble Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        // Handle menu choices
 switch (choice) {
            case 1:
                bubbleSort(arr);
                break;
            case 2:
                selectionSort(arr);
                break;
            case 3:
                insertionSort(arr);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Bubble Sort
void bubbleSort(std::vector<int>& arr) {
    int size = arr.size();
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
    printf("The array after pass %d is: \n", i + 1);
    display(arr);

        if (!swapped) break; // Stop if already sorted
    }
    printf("Sorted array: \n");
    display(arr);
}

// Selection Sort
void selectionSort(std::vector<int>& arr) {
    int size = arr.size();
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
         if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
    std::swap(arr[minIndex], arr[i]);

        printf("The array after pass %d is: \n", i + 1);
     display(arr);
    }
    printf("Sorted array: \n");
    display(arr);
}

// Insertion Sort
void insertionSort(std::vector<int>& arr) {
int size = arr.size();
    for (int i = 1; i < size; i++) {
        int key = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;

    printf("The array after pass %d is: \n", i);
    display(arr);
    }

    printf("Sorted array: \n");
    display(arr);
}

// Display the array
void display(const std::vector<int>& arr) {
    for (int elem : arr) {
    printf("%d ", elem);
    }
    printf("\n");
}
