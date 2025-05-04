#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Circular Linked List class
class CircularLinkedList {
private:
    Node* tail;

public:
    CircularLinkedList() : tail(nullptr) {}

    // Insert at the beginning
    void insertBeginning(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            tail = newNode;
            tail->next = tail;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
        }
    }

    // Insert at the end
    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            tail = newNode;
            tail->next = tail;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Insert at a specific position (1-based index)
    void insertPosition(int val, int pos) {
        if (pos <= 0) {
            cout << "Invalid position!" << endl;
            return;
        }
        if (pos == 1 || !tail) {
            insertBeginning(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* temp = tail->next;
        for (int i = 1; temp != tail && i < pos - 1; ++i) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        if (temp == tail) tail = newNode;
    }

    // Delete from the beginning
    void deleteBeginning() {
        if (!tail) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = tail->next;
        if (tail == temp) {
            tail = nullptr;
        } else {
            tail->next = temp->next;
        }
        delete temp;
    }

    // Delete from the end
    void deleteEnd() {
        if (!tail) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = tail->next;
        if (tail == temp) {
            delete tail;
            tail = nullptr;
            return;
        }
        while (temp->next != tail) {
            temp = temp->next;
        }
        temp->next = tail->next;
        delete tail;
        tail = temp;
    }

    // Delete from a specific position
    void deletePosition(int pos) {
        if (!tail || pos <= 0) {
            cout << "Invalid position or empty list!" << endl;
            return;
        }
        if (pos == 1) {
            deleteBeginning();
            return;
        }
        Node* temp = tail->next;
        Node* prev = nullptr;
        for (int i = 1; temp != tail && i < pos; ++i) {
            prev = temp;
            temp = temp->next;
        }
        if (!prev || temp == tail->next) {
            cout << "Position out of range!" << endl;
            return;
        }
        prev->next = temp->next;
        if (temp == tail) tail = prev;
        delete temp;
    }

    // Search for an element
    bool search(int val) {
        if (!tail) return false;
        Node* temp = tail->next;
        do {
            if (temp->data == val) return true;
            temp = temp->next;
        } while (temp != tail->next);
        return false;
    }

    // Display the list
    void display() {
        if (!tail) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = tail->next;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << "(Back to head)" << endl;
    }
};

int main() {
    CircularLinkedList list;
    int choice, value, pos;
    do {
        cout << "\nCircular Linked List Menu";
        cout << "\n1. Insert Beginning";
        cout << "\n2. Insert End";
        cout << "\n3. Insert Position";
        cout << "\n4. Delete Beginning";
        cout << "\n5. Delete End";
        cout << "\n6. Delete Position";
        cout << "\n7. Search";
        cout << "\n8. Display";
        cout << "\n9. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insertBeginning(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                list.insertEnd(value);
                break;
            case 3:
                cout << "Enter value and position: ";
                cin >> value >> pos;
                list.insertPosition(value, pos);
                break;
            case 4:
                list.deleteBeginning();
                break;
            case 5:
                list.deleteEnd();
                break;
            case 6:
                cout << "Enter position: ";
                cin >> pos;
                list.deletePosition(pos);
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                cout << (list.search(value) ? "Found" : "Not Found") << endl;
                break;
            case 8:
                list.display();
                break;
            case 9:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 9);
    return 0;
}