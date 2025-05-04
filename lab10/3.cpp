#include <cstdio>

class MaxHeap 
{
private:
    int heap[100];
    int size;

    void heapifyUp(int index) 
    {
        if (index <= 0) return;
        int parent = (index - 1) / 2;
        if (heap[index] > heap[parent]) 
        {
            int temp = heap[index];
            heap[index] = heap[parent];
            heap[parent] = temp;
            heapifyUp(parent);
        }
    }

    void heapifyDown(int index) 
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < size && heap[left] > heap[largest])
            largest = left;
        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest != index) 
        {
            int temp = heap[index];
            heap[index] = heap[largest];
            heap[largest] = temp;
            heapifyDown(largest);
        }
    }

public:
    MaxHeap() 
    {
        size = 0;
    }

    void insert(int val) 
    {
        if (size >= 100) 
        {
            printf("Heap is full.\n");
            return;
        }
        heap[size++] = val;
        heapifyUp(size - 1);
    }

    void deleteMax() 
    {
        if (size == 0) 
        {
            printf("Heap is empty.\n");
            return;
        }
        printf("Deleted: %d\n", heap[0]);
        heap[0] = heap[--size];
        heapifyDown(0);
    }

    void display() 
    {
        if (size == 0) 
        {
            printf("Heap is empty.\n");
            return;
        }
        printf("Heap elements: ");
        for (int i = 0; i < size; i++)
            printf("%d ", heap[i]);
        printf("\n");
    }

    bool search(int val) 
    {
        for (int i = 0; i < size; i++) 
        {
            if (heap[i] == val)
                return true;
        }
        return false;
    }

    void heapSort() 
    {
        int tempHeap[100], tempSize = size;
        for (int i = 0; i < size; i++)
            tempHeap[i] = heap[i];

        printf("Sorted elements (descending): ");
        while (size > 0) 
        {
            printf("%d ", heap[0]);
            heap[0] = heap[--size];
            heapifyDown(0);
        }
        printf("\n");

        for (int i = 0; i < tempSize; i++) // restore original heap
            heap[i] = tempHeap[i];
        size = tempSize;
    }
};

int main() 
{
    MaxHeap pq;
    int choice, val;

    do 
    {
        printf("\nPriority Queue Menu:\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Search\n5. Sort (Heap Sort)\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &val);
            pq.insert(val);
            break;
        case 2:
            pq.deleteMax();
            break;
        case 3:
            pq.display();
            break;
        case 4:
            printf("Enter value to search: ");
            scanf("%d", &val);
            if (pq.search(val))
                printf("Value found in the heap.\n");
            else
                printf("Value not found.\n");
            break;
        case 5:
            pq.heapSort();
            break;
        case 6:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}