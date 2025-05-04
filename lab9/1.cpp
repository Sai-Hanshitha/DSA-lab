#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// BST Class
class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }

    // Insert function
    Node* insert(Node* node, int key) {
        if (node == nullptr) return new Node(key);
        if (key < node->data)
            node->left = insert(node->left, key);
        else
            node->right = insert(node->right, key);
        return node;
    }

    void insert(int key) {
        root = insert(root, key);
    }

    // Inorder traversal (LNR)
    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void inorder() {
        inorder(root);
        cout << endl;
    }

    // Preorder traversal (NLR)
    void preorder(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void preorder() {
        preorder(root);
        cout << endl;
    }

    // Postorder traversal (LRN)
    void postorder(Node* node) {
        if (node == nullptr) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    void postorder() {
        postorder(root);
        cout << endl;
    }

    // Search operation
    bool search(Node* node, int key) {
        if (node == nullptr) return false;
        if (node->data == key) return true;
        return (key < node->data) ? search(node->left, key) : search(node->right, key);
    }

    bool search(int key) {
        return search(root, key);
    }
};

// Menu-driven program
int main() {
    BST tree;
    int choice, val;

    do {
        cout << "\nBinary Search Tree Menu:\n";
        cout << "1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Search\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                tree.insert(val);
                break;
            case 2:
                cout << "Preorder Traversal: ";
                tree.preorder();
                break;
            case 3:
                cout << "Inorder Traversal: ";
                tree.inorder();
                break;
            case 4:
                cout << "Postorder Traversal: ";
                tree.postorder();
                break;
            case 5:
                cout << "Enter value to search: ";
                cin >> val;
                cout << (tree.search(val) ? "Found" : "Not Found") << endl;
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
