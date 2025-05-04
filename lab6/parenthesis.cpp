#include "stacksll.h"

#define MAX 100

// Function to check balanced parentheses
int isBalanced(char expr[]) {
    list s;
    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(') {
            s.push(expr[i]);
        } else if (expr[i] == ')') {
            if (s.is_empty()) return 0;
            s.pop();
        }
    }
    return s.is_empty();
}

int main() {
    int choice;
    char expr[MAX];

    do {
        printf("\nMenu:\n1. Check Balance\n2. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter parentheses string: ");
                scanf("%s", expr);
                if (isBalanced(expr)) {
                    printf("The parentheses are balanced.\n");
                } else {
                    printf("The parentheses are NOT balanced.\n");
                }
                break;
            case 2:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 2);

    return 0;
}