#include "stacksll.h"
#include <cctype>
#include <cstring>

#define MAX 100

// Function to return precedence of operators
int precedence(char op) {
    if (op == '=')
        return 1;
    if (op == '+' || op == '-')
        return 2;
    if (op == '*' || op == '/' || op == '%')
        return 3;
    return 0;
}

// Convert infix to postfix
void infixToPostfix(char infix[], char postfix[]) {
    list s;
    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (isalnum(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.is_empty() && s.peek() != '(') {
                postfix[j++] = s.pop();
            }
            s.pop();
        } else {
            while (!s.is_empty() && precedence(s.peek()) >= precedence(c)) {
                postfix[j++] = s.pop();
            }
            s.push(c);
        }
    }
    while (!s.is_empty()) {
        postfix[j++] = s.pop();
    }
    postfix[j] = '\0';

    printf("Postfix Expression: %s\n", postfix);
}

// Evaluate postfix expression
int evaluatePostfix(char postfix[]) {
    list s;
    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];

        if (isdigit(c)) {
            s.push(c - '0');
        } else {
            int b = s.pop();
            int a = s.pop();
            switch (c) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
                case '%': s.push(a % b); break;
                case '=': s.push(b); break; // Store result
            }
        }
    }
    return s.pop();
}

int main() {
    char infix[MAX], postfix[MAX];
    int choice;

    do {
        printf("\nMenu:\n1. Get Infix\n2. Convert Infix\n3. Evaluate Postfix\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter infix expression: ");
                scanf("%s", infix);
                break;
            case 2:
                infixToPostfix(infix, postfix);
                break;
            case 3:
                printf("Result: %d\n", evaluatePostfix(postfix));
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}