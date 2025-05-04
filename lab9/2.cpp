#include <iostream>
#include <stack>
using namespace std;

// Node structure for Expression Tree
struct ExprNode {
    char data;
    ExprNode* left;
    ExprNode* right;

    ExprNode(char val) {
        data = val;
        left = right = nullptr;
    }
};

// Expression Tree class
class ExpressionTree {
public:
    ExprNode* root;

    ExpressionTree() {
        root = nullptr;
    }

    // Function to construct the expression tree from postfix
    ExprNode* constructTree(string postfix) {
        stack<ExprNode*> st;
        
        for (char ch : postfix) {
            if (isalnum(ch)) {  // Operand
                st.push(new ExprNode(ch));
            } else {  // Operator
                ExprNode* node = new ExprNode(ch);
                node->right = st.top(); st.pop();
                node->left = st.top(); st.pop();
                st.push(node);
            }
        }
        root = st.top();
        return root;
    }

    // Preorder Traversal (NLR)
    void preorder(ExprNode* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void preorder() {
        preorder(root);
        cout << endl;
    }

    // Inorder Traversal (LNR)
    void inorder(ExprNode* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void inorder() {
        inorder(root);
        cout << endl;
    }

    // Postorder Traversal (LRN)
    void postorder(ExprNode* node) {
        if (node == nullptr) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    void postorder() {
        postorder(root);
        cout << endl;
    }
};

// Main function with menu
int main() {
    ExpressionTree expTree;
    string postfix;
    int choice;

    do {
        cout << "\nExpression Tree Menu:\n";
        cout << "1. Enter Postfix Expression\n";
        cout << "2. Construct Expression Tree\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Inorder Traversal\n";
        cout << "5. Postorder Traversal\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter postfix expression: ";
                cin >> postfix;
                break;
            case 2:
                expTree.constructTree(postfix);
                cout << "Expression Tree Constructed.\n";
                break;
            case 3:
                cout << "Preorder Traversal: ";
                expTree.preorder();
                break;
            case 4:
                cout << "Inorder Traversal: ";
                expTree.inorder();
                break;
            case 5:
                cout << "Postorder Traversal: ";
                expTree.postorder();
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
