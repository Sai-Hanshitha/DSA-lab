#include <iostream>
using namespace std;

// Node structure for the character binary tree
struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(char value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;

    void preorder(TreeNode* node) {
        if (node) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void inorder(TreeNode* node) {
        if (node) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    void postorder(TreeNode* node) {
        if (node) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }

    TreeNode* search(TreeNode* node, char key) {
        if (!node || node->data == key)
            return node;
        
        TreeNode* leftSearch = search(node->left, key);
        if (leftSearch)
            return leftSearch;
        return search(node->right, key);
    }

public:
    BinaryTree() : root(nullptr) {}

    void insert(char parent, char value, char direction) {
        TreeNode* newNode = new TreeNode(value);
        if (!root) {
            root = newNode;
            cout << "Inserted " << value << " as root." << endl;
            return;
        }
        TreeNode* parentNode = search(root, parent);
        if (!parentNode) {
            cout << "Parent node not found!" << endl;
            delete newNode;
            return;
        }
        if (direction == 'L' || direction == 'l') {
            if (parentNode->left)
                cout << "Left child already exists!" << endl;
            else {
                parentNode->left = newNode;
                cout << "Inserted " << value << " to the left of " << parent << endl;
            }
        } else if (direction == 'R' || direction == 'r') {
            if (parentNode->right)
                cout << "Right child already exists!" << endl;
            else {
                parentNode->right = newNode;
                cout << "Inserted " << value << " to the right of " << parent << endl;
            }
        } else {
            cout << "Invalid direction! Use 'L' for left or 'R' for right." << endl;
            delete newNode;
        }
    }

    void displayPreorder() {
        preorder(root);
        cout << endl;
    }

    void displayInorder() {
        inorder(root);
        cout << endl;
    }

    void displayPostorder() {
        postorder(root);
        cout << endl;
    }

    bool search(char key) {
        return search(root, key) != nullptr;
    }
};

int main() {
    BinaryTree tree;
    int choice;
    char parent, value, direction;
    
    do {
        cout << "\nBinary Tree Menu:\n";
        cout << "1. Insert\n";
        cout << "2. Preorder Traversal\n";
        cout << "3. Inorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Search\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter parent node, value to insert, and direction (L/R): ";
                cin >> parent >> value >> direction;
                tree.insert(parent, value, direction);
                break;
            case 2:
                tree.displayPreorder();
                break;
            case 3:
                tree.displayInorder();
                break;
            case 4:
                tree.displayPostorder();
                break;
            case 5:
                cout << "Enter value to search: ";
                cin >> value;
                if (tree.search(value))
                    cout << "Node found!" << endl;
                else
                    cout << "Node not found!" << endl;
                break;
            case 6:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 6." << endl;
        }
    } while (choice != 6);
    
    return 0;
}
