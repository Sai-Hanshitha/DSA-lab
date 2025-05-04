#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;
const int EMPTY = -1;
const int DELETED = -2;

class HashTable {
private:
    int table[TABLE_SIZE];

    int hashFunction(int key, int i) {
        return (key + i * i) % TABLE_SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = EMPTY;
        }
    }

    void insert(int key) {
        for (int i = 0; i < TABLE_SIZE; i++) {
            int index = hashFunction(key, i);
            if (table[index] == EMPTY || table[index] == DELETED) {
                table[index] = key;
                cout << "Inserted at index " << index << endl;
                return;
            }
        }
        cout << "Hash table is full. Cannot insert key.\n";
    }

    void remove(int key) {
        for (int i = 0; i < TABLE_SIZE; i++) {
            int index = hashFunction(key, i);
            if (table[index] == EMPTY) break;
            if (table[index] == key) {
                table[index] = DELETED;
                cout << "Key deleted from index " << index << endl;
                return;
            }
        }
        cout << "Key not found.\n";
    }

    void search(int key) {
        for (int i = 0; i < TABLE_SIZE; i++) {
            int index = hashFunction(key, i);
            if (table[index] == EMPTY) break;
            if (table[index] == key) {
                cout << "Key found at index " << index << endl;
                return;
            }
        }
        cout << "Key not found.\n";
    }

    void display() {
        cout << "Hash Table:\n";
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i] == EMPTY)
                cout << i << ": EMPTY\n";
            else if (table[i] == DELETED)
                cout << i << ": DELETED\n";
            else
                cout << i << ": " << table[i] << endl;
        }
    }
};

int main() {
    HashTable ht;
    int choice, key;

    do {
        cout << "\n--- Hash Table Menu ---\n";
        cout << "1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                ht.insert(key);
                break;
            case 2:
                cout << "Enter key to delete: ";
                cin >> key;
                ht.remove(key);
                break;
            case 3:
                cout << "Enter key to search: ";
                cin >> key;
                ht.search(key);
                break;
            case 4:
                ht.display();
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}