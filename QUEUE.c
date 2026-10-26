#include <stdio.h>
#define MAX 5   // maximum size of queue

int queue[MAX];
int front = -1, rear = -1;

// Function to insert an element
void insert(int value) {
    if (rear == MAX - 1) {
        printf("QUEUE OVERFLOW\n");
    } else {
        if (front == -1) front = 0; // first element
        rear++;
        queue[rear] = value;
        printf("Inserted: %d\n", value);
    }
}

// Function to delete an element
void delete() {
    if (front == -1 || front > rear) {
        printf("QUEUE EMPTY\n");
    } else {
        printf("Deleted: %d\n", queue[front]);
        front++;
    }
}

// Function to display queue elements
void display() {
    if (front == -1 || front > rear) {
        printf("QUEUE EMPTY\n");
    } else {
        printf("Queue elements are:\n");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\nQUEUE MENU\n");
        printf("1. INSERT\n");
        printf("2. DELETE\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
