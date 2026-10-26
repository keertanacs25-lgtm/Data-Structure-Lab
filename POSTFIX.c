#include <stdio.h>
#include <ctype.h>   // for isalnum
#define MAX 100

char stack[MAX];
int top = -1;

// Push function
void push(char c) {
    stack[++top] = c;
}

// Pop function
char pop() {
    return stack[top--];
}

// Precedence function
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Infix to Postfix conversion
void infixToPostfix(char* exp) {
    char output[MAX];
    int k = 0;

    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];

        if (isalnum(c)) {
            output[k++] = c;   // operand → output
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                output[k++] = pop();
            }
            pop(); // remove '('
        }
        else { // operator
            while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                output[k++] = pop();
            }
            push(c);
        }
    }

    while (top != -1) {
        output[k++] = pop();
    }

    output[k] = '\0';
    printf("Postfix Expression: %s\n", output);
}

int main() {
    char exp[MAX];
    int choice;

    while (1) {
        printf("\nMENU\n");
        printf("1. Convert Infix to Postfix\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a valid infix expression: ");
                scanf("%s", exp);
                top = -1; // reset stack for each new expression
                infixToPostfix(exp);
                break;
            case 2:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
