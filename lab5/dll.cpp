#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Doubly Linked List class
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Insert at the beginning
    void insertBeginning(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Insert at the end
    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Insert at a specific position (1-based index)
    void insertPosition(int val, int pos) {
        if (pos <= 0) {
            cout << "Invalid position!" << endl;
            return;
        }
        if (pos == 1) {
            insertBeginning(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* temp = head;
        for (int i = 1; temp && i < pos - 1; ++i) {
            temp = temp->next;
        }
        if (!temp) {
            cout << "Position out of range!" << endl;
            return;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next) temp->next->prev = newNode;
        temp->next = newNode;
        if (!newNode->next) tail = newNode;
    }

    // Delete from the beginning
    void deleteBeginning() {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
    }

    // Delete from the end
    void deleteEnd() {
        if (!tail) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete temp;
    }

    // Delete from a specific position
    void deletePosition(int pos) {
        if (!head || pos <= 0) {
            cout << "Invalid position or empty list!" << endl;
            return;
        }
        if (pos == 1) {
            deleteBeginning();
            return;
        }
        Node* temp = head;
        for (int i = 1; temp && i < pos; ++i) {
            temp = temp->next;
        }
        if (!temp) {
            cout << "Position out of range!" << endl;
            return;
        }
        if (temp->next) temp->next->prev = temp->prev;
        if (temp->prev) temp->prev->next = temp->next;
        if (temp == tail) tail = temp->prev;
        delete temp;
    }

    // Search for an element
    bool search(int val) {
        Node* temp = head;
        while (temp) {
            if (temp->data == val) return true;
            temp = temp->next;
        }
        return false;
    }

    // Display the list
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyLinkedList list;
    int choice, value, pos;
    do {
        cout << "\nDoubly Linked List Menu";
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
