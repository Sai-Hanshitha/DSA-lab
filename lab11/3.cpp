#include <iostream>
#include <list>
#include <iterator>
using namespace std;

const int TABLE_SIZE = 10;

class HashTable {
private:
    list<int> table[TABLE_SIZE];

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
        cout << "Inserted key " << key << " at index " << index << endl;
    }

    void remove(int key) {
        int index = hashFunction(key);
        auto& chain = table[index];

        for (auto it = chain.begin(); it != chain.end(); ++it) {
            if (*it == key) {
                chain.erase(it);
                cout << "Key " << key << " deleted from index " << index << endl;
                return;
            }
        }
        cout << "Key not found.\n";
    }

    void search(int key) {
        int index = hashFunction(key);
        auto& chain = table[index];

        for (auto it = chain.begin(); it != chain.end(); ++it) {
            if (*it == key) {
                cout << "Key " << key << " found at index " << index << endl;
                return;
            }
        }
        cout << "Key not found.\n";
    }

    void display() {
        cout << "\nHash Table:\n";
        for (int i = 0; i < TABLE_SIZE; ++i) {
            cout << i << ": ";
            for (int val : table[i])
                cout << val << " -> ";
            cout << "NULL\n";
        }
    }
};

int main() {
    HashTable ht;
    int choice, key;

    do {
        cout << "\n--- Hash Table Menu (Separate Chaining) ---\n";
        cout << "1. Insert\n2. Delete\n3. Search\n4. Exit\n";
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
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

        ht.display();

    } while (choice != 4);

    return 0;
}