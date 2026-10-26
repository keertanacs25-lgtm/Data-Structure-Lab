#include <stdio.h>
#define MAX 5   // maximum size of stack

int stack[MAX];
int top = -1;   // stack is initially empty
int value;
// Function to push an element
void push() {
    if (top == MAX - 1) {
        printf("STACK OVERFLOW\n");
    }
    else {
        printf("Enter a value:");
        scanf("%d",&value);
        top++;
        stack[top] = value;

    }
}

// Function to pop an element
void pop() {
    if (top == -1) {
        printf("STACK UNDERFLOW\n");
    } else {
        printf("Element popped: %d\n", stack[top]);
        top--;
    }
}

// Function to display stack elements
void display() {
    if (top == -1) {
        printf("STACK IS EMPTY\n");
    } else {
        printf("Elements in stack are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice;

    while (1) {

        printf("\nSTACK MENU\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exit");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
