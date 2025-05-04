#include <cstdio>
#include <vector>

void linearSearch(const std::vector<int>& arr, int target);
void binarySearch(std::vector<int>& arr, int target);
void insertionSort(std::vector<int>& arr);

int main() {
int size, target;
printf("Enter the number of elements in the array: ");
scanf("%d", &size);
    if (size <= 0) return printf("Invalid size. The size must be greater than 0.\n"), 1;

    std::vector<int> arr(size);
    for (int& elem : arr) {
        printf("Enter element: ");
        scanf("%d", &elem);
    }

    while (true) {
        printf("\nMenu:\n1. Linear Search\n2. Binary Search\n3. Exit\nEnter your choice: ");
        int choice;
        scanf("%d", &choice);
        if (choice == 3) return 0;

        printf("Enter the target element: ");
        scanf("%d", &target);
        if (choice == 1) linearSearch(arr, target);
        else if (choice == 2) {
            insertionSort(arr);
            binarySearch(arr, target);
        } else printf("Invalid choice. Please try again.\n");
    }
}

void linearSearch(const std::vector<int>& arr, int target) {
 for (int i = 0; i < arr.size(); i++) {
     if (arr[i] == target) return printf("The element is found at index %d.\n", i), void();
    }
    printf("The element is not present in the array.\n");
}

void binarySearch(const std::vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return printf("The element is found at index %d.\n", mid), void();
        arr[mid] < target ? left = mid + 1 : right = mid - 1;
    }
    printf("The element is not present in the array.\n");
}

void insertionSort(std::vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key) arr[j + 1] = arr[j], j--;
        arr[j + 1] = key;
    }
}