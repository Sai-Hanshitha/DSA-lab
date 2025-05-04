#include <iostream>
using namespace std;

// Node structure
struct Node {
    int time;
    Node* next;
    Node(int t) : time(t), next(nullptr) {}
};

// Circular Queue class for Round Robin Scheduling
class RoundRobinScheduler {
private:
    Node* tail;
    int timeQuantum;

public:
    RoundRobinScheduler(int tq) : tail(nullptr), timeQuantum(tq) {}

    // Insert process
    void insertProcess(int time) {
        Node* newNode = new Node(time);
        if (!tail) {
            tail = newNode;
            tail->next = tail;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Execute process
    void execute() {
        if (!tail) {
            cout << "No processes in the queue!" << endl;
            return;
        }
        Node* temp = tail->next;
        cout << "Executing process with time: " << temp->time << endl;
        int remainingTime = temp->time - timeQuantum;
        if (remainingTime > 0) {
            cout << "Process incomplete, remaining time: " << remainingTime << endl;
            insertProcess(remainingTime);
        } else {
            cout << "Process completed." << endl;
        }
        if (temp == tail) {
            tail = nullptr;
        } else {
            tail->next = temp->next;
        }
        delete temp;
    }
};

int main() {
    int timeQuantum;
    cout << "Enter time quantum: ";
    cin >> timeQuantum;
    RoundRobinScheduler scheduler(timeQuantum);
    int choice, time;
    do {
        cout << "\nRound Robin Scheduling Menu";
        cout << "\n1. Insert Process";
        cout << "\n2. Execute";
        cout << "\n3. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter process execution time: ";
                cin >> time;
                scheduler.insertProcess(time);
                break;
            case 2:
                scheduler.execute();
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 3);
    return 0;
}
