#include <iostream>
#define SIZE 5

using namespace std;

class Queue {
private:
    int arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return rear == SIZE - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full! Cannot enqueue." << endl;
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = value;
        cout << "Enqueued: " << value << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return;
        }
        cout << "Dequeued: " << arr[front] << endl;
        front++;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty! Nothing to peek." << endl;
            return;
        }
        cout << "Front element: " << arr[front] << endl;
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\nQueue Menu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 4." << endl;
        }
    } while (choice != 4);

    return 0;
}
